#include "Utils.h"
#include "gui/Menu.h"
#include "mem/Memory.h"
#include <Psapi.h>

using PostRenderFn = void (*)(SDK::UGameViewportClient *, SDK::UCanvas *);

PostRenderFn originalPostRenderFn = 0;

void PostRenderHooked(SDK::UGameViewportClient *_this, SDK::UCanvas *canvas) {

  static SDK::FVector2D center{300.0f, 300.0f};
  static float size = 50.0f;
  static float thickness = 1.0f;

  // static SDK::FLinearColor color = {1.0f, 0.0f, 0.0f, 0.0f};

  // float halfSize = size / 2.0f;
  // float armOffset = size / 4.0f;

  //// Horizontal and vertical lines
  // canvas->K2_DrawLine({center.X - halfSize, center.Y},
  //                      {center.X + halfSize, center.Y}, thickness,
  //                      color); // Horizontal
  // canvas->K2_DrawLine({center.X, center.Y - halfSize},
  //                      {center.X, center.Y + halfSize}, thickness,
  //                      color); // Vertical

  //// Top-left arm
  // canvas->K2_DrawLine({center.X - halfSize, center.Y - halfSize},
  //                      {center.X - halfSize + armOffset, center.Y -
  //                      halfSize}, thickness, color); // Horizontal
  // canvas->K2_DrawLine({center.X - halfSize, center.Y - halfSize},
  //                      {center.X - halfSize, center.Y - halfSize +
  //                      armOffset}, thickness, color); // Vertical

  //// Top-right arm
  // canvas->K2_DrawLine({center.X + halfSize, center.Y - halfSize},
  //                      {center.X + halfSize - armOffset, center.Y -
  //                      halfSize}, thickness, color); // Horizontal
  // canvas->K2_DrawLine({center.X + halfSize, center.Y - halfSize},
  //                      {center.X + halfSize, center.Y - halfSize +
  //                      armOffset}, thickness, color); // Vertical

  //// Bottom-left arm
  // canvas->K2_DrawLine({center.X - halfSize, center.Y + halfSize},
  //                      {center.X - halfSize + armOffset, center.Y +
  //                      halfSize}, thickness, color); // Horizontal
  // canvas->K2_DrawLine({center.X - halfSize, center.Y + halfSize},
  //                      {center.X - halfSize, center.Y + halfSize -
  //                      armOffset}, thickness, color); // Vertical

  //// Bottom-right arm
  // canvas->K2_DrawLine({center.X + halfSize, center.Y + halfSize},
  //                      {center.X + halfSize - armOffset, center.Y +
  //                      halfSize}, thickness, color); // Horizontal
  // canvas->K2_DrawLine({center.X + halfSize, center.Y + halfSize},
  //                      {center.X + halfSize, center.Y + halfSize -
  //                      armOffset}, thickness, color); // Vertical

  canvas->K2_DrawText(pFont, L"[ANGOLA_HOOK]", {100.f, 20.f}, {1.f, 1.f},
                       {1.0f, 1.0f, 1.0f, 1.0f}, 0.0f, {1.0f, 1.0f}, {200, 200},
                       true, true, true, {0.0f, 0.0f, 0.0f, 0.5f});

  auto sSize = Utils::GetScreenSize();

  std::stringstream sScreenSize;

  sScreenSize << "[" << sSize.width << " " << sSize.height << "]";

  canvas->K2_DrawText(pFont, Utils::ToWString(sScreenSize.str()).c_str(),
                       {200.f, 20.f}, {1.f, 1.f}, {0.5f, 0.3f, 1.0f, 1.0f},
                       0.0f, {1.0f, 1.0f}, {200, 200}, true, true, true,
                       {0.0f, 0.0f, 0.0f, 0.5f});

  ZeroGUI::SetupCanvas(canvas);
  Menu::Update();

  if (originalPostRenderFn) {
    originalPostRenderFn(_this, canvas);
  }
}

static unsigned long FakEntry(HMODULE hModule) {

  AllocConsole();
  FILE *pFile{nullptr};
  freopen_s(&pFile, "CONOUT$", "w", __acrt_iob_func(1));

  U_LOG("[ANGOLA_HOOK] injected %s\n", Utils::GetWndowTitle().c_str());
  uintptr_t moduleBase = (uintptr_t)GetModuleHandle(0);

  auto UWorld = Memory::FindPattern(
      (PBYTE) "\x48\x89\x05\x00\x00\x00\x00\x48\x8B\xB7\x00\x00\x00\x00",
      "xxx????xxx????", 0x3, 0x7);

  SDK::UEngine *pEngine = SDK::UEngine::GetEngine();

  SDK::UWorld *pWorld = *(SDK::UWorld **)UWorld;

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

  U_LOG("[%p] GWorld \n", UWorld);
  U_LOG("[%p] UGameViewportClient->DrawTransition", originalPostRenderFn);

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
