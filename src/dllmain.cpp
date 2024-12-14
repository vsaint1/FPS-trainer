#include "Utils.h"
#include "gui/Menu.h"
#include "mem/Memory.h"

using PostRenderFn = void (*)(SDK::UGameViewportClient *, SDK::UCanvas *);

PostRenderFn originalPostRenderFn = 0;

void PostRenderHooked(SDK::UGameViewportClient *_this, SDK::UCanvas *pCanvas) {

  pCanvas->K2_DrawLine({100.f, 100.f}, {200.f, 200.0f}, 1.0f,
                       {1.0f, 1.0f, 1.0f, 1.0f});

  pCanvas->K2_DrawText(pFont, L"[ANGOLA_HOOK]", {100.f, 20.f}, {1.f, 1.f},
                       {1.0f, 1.0f, 1.0f, 1.0f}, 0.0f, {1.0f, 1.0f}, {200, 200},
                       true, true, true, {0.0f, 0.0f, 0.0f, 0.5f});

  auto size = Utils::GetScreenSize();

  std::stringstream sScreenSize;

  sScreenSize << "[" << size.width << " " << size.height << "]";

  pCanvas->K2_DrawText(pFont, Utils::ToWString(sScreenSize.str()).c_str(),
                       {200.f, 20.f}, {1.f, 1.f}, {0.5f, 0.3f, 1.0f, 1.0f},
                       0.0f, {1.0f, 1.0f}, {200, 200}, true, true, true,
                       {0.0f, 0.0f, 0.0f, 0.5f});

  ZeroGUI::SetupCanvas(pCanvas);
  Menu::Update();

  if (originalPostRenderFn) {
    originalPostRenderFn(_this, pCanvas);
  }
}

static unsigned long FakEntry(HMODULE hModule) {
  AllocConsole();
  FILE *pFile{nullptr};
  freopen_s(&pFile, "CONOUT$", "w", __acrt_iob_func(1));

  U_LOG("[ANGOLA_HOOK] injected %s", Utils::GetWndowTitle().c_str());

  SDK::UEngine *pEngine = SDK::UEngine::GetEngine();

  SDK::UWorld *pWorld = SDK::UWorld::GetWorld();

  if (!pWorld || !pEngine) {
    U_LOG("Failed to get world and engine");
  }

  auto *viewport = pWorld->OwningGameInstance->LocalPlayers[0]->ViewportClient;

  if (!viewport) {
    U_LOG("ViewportClient is nullptr!");
  }

  void **viewportVtable = *reinterpret_cast<void ***>(viewport);

  originalPostRenderFn = reinterpret_cast<decltype(originalPostRenderFn)>(
      Memory::VMT_Hook(viewportVtable, 0x63, &PostRenderHooked));

  while (!GetAsyncKeyState(VK_END)) {

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  viewportVtable[0x63] = originalPostRenderFn;
  originalPostRenderFn = nullptr;
  FreeConsole();
  fclose(pFile);
  FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {

  if (ul_reason_for_call == DLL_PROCESS_ATTACH) {

    auto hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)FakEntry,
                                hModule, 0, nullptr);

    if (hThread)
      CloseHandle(hThread);

    return TRUE;
  }

  return false;
}
