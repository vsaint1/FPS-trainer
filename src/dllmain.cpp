
#include "cheat/Cheat.h"
#include "gui/Menu.h"
#include "hooks/Hooks.h"

void PostRenderHooked(SDK::UGameViewportClient *_this, SDK::UCanvas *canvas) {
  if (!_this || !canvas) {
    U_LOG(
        "PostRenderHooked: _this or canvas is nullptr. Skipping rendering. \n");
    return;
  }

  canvas->K2_DrawText(pFont, L"[ANGOLA_HOOK]", {100.f, 20.f}, {1.f, 1.f},
                      {1.0f, 1.0f, 1.0f, 1.0f}, 0.0f, {1.0f, 1.0f}, {200, 200},
                      true, true, true, {0.0f, 0.0f, 0.0f, 0.5f});

  auto sSize = Utils::GetScreenSize();
  std::stringstream sScreenSize;
  sScreenSize << "[" << sSize.width << " " << sSize.height << "]";
  canvas->K2_DrawText(pFont, Utils::ToWString(sScreenSize.str()).c_str(),
                      {200.f, 20.f}, {1.f, 1.f}, {0.5f, 0.3f, 1.0f, 1.0f}, 0.0f,
                      {1.0f, 1.0f}, {200, 200}, true, true, true,
                      {0.0f, 0.0f, 0.0f, 0.5f});

  ZeroGUI::SetupCanvas(canvas);
  Menu::Update();

  /*  if (!actor->IsA(SDK::ABP_PlayerCharacter_C::StaticClass()))
  continue;

if (!actor->IsA(SDK::ABP_FragGrenadeLethal_C::StaticClass()))
  continue;
//BP_BaseWeapon_classes add
if (!actor->IsA(SDK::ABP_FragGrenadeLethal_C::StaticClass()))
continue;

if (!actor->IsA(SDK::ABP_ConquestCapturePoint_C::StaticClass()))
  continue;*/

  if (G::pLevel != nullptr && G::pLocalPlayer != nullptr &&
      G::pLocalPlayer->AcknowledgedPawn != nullptr && G::pActors != nullptr) {

    SDK::TArray<SDK::AActor *> actors = *G::pActors;

    Cheat::Run(*G::pActors, canvas);
  }

  if (Defines::originalPostRenderFn) {
    Defines::originalPostRenderFn(_this, canvas);
  }
}

static unsigned long FakEntry(HMODULE hModule) {

  AllocConsole();
  FILE *pFile{nullptr};
  freopen_s(&pFile, "CONOUT$", "w", __acrt_iob_func(1));

  U_LOG("[ANGOLA_HOOK] injected %s ", Utils::GetWndowTitle().c_str());
  uintptr_t moduleBase = (uintptr_t)GetModuleHandle(0);

  auto UWorld = Memory::FindPattern((BYTE *)G::Offsets::GWORLD_SIG.signature,
                                    G::Offsets::GWORLD_SIG.mask, 0x3, 0x7);

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

  Defines::originalPostRenderFn =
      reinterpret_cast<decltype(Defines::originalPostRenderFn)>(
          Memory::VMT_Hook(viewportVtable, G::Offsets::PR_IDX_OFFSET,
                           &PostRenderHooked));

  U_LOG("[%p] GWorld", UWorld);
  U_LOG("[%p] UGameViewportClient->DrawTransition()",
        Defines::originalPostRenderFn);

  Chams::wireFrameMaterial = SDK::UObject::FindObject<SDK::UMaterial>(
      "Material WireframeMaterial.WireframeMaterial");

  if (Chams::wireFrameMaterial) {

    Chams::wireFrameMaterial->bDisableDepthTest = 1;
    Chams::wireFrameMaterial->Wireframe = 1;
    Chams::wireFrameMaterial->BlendMode = SDK::EBlendMode::BLEND_Additive;
    Chams::wireFrameMaterial->MaterialDomain = SDK::EMaterialDomain::MD_Surface;
    Chams::wireFrameMaterial->AllowTranslucentCustomDepthWrites = 1;
    Chams::wireFrameMaterial->bIsBlendable = 1;
    Chams::wireFrameMaterial->LightmassSettings.EmissiveBoost = 1.0f;
    Chams::wireFrameMaterial->LightmassSettings.DiffuseBoost = 0;
  }

  Chams::chamsMaterial =
      SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(
          pWorld, Chams::wireFrameMaterial, Utils::ToFName(L"ChamsMaterial"),
          SDK::EMIDCreationFlags::Transient);

  Chams::chamsVisibleMaterial =
      SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(
          pWorld, Chams::wireFrameMaterial,
          Utils::ToFName(L"ChamsVisibleMaterial"),
          SDK::EMIDCreationFlags::Transient);

  Chams::chamsOccludedMaterial =
      SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(
          pWorld, Chams::wireFrameMaterial,
          Utils::ToFName(L"ChamsOccludedMaterial"),
          SDK::EMIDCreationFlags::Transient);

  while (!GetAsyncKeyState(VK_END)) {

    G::pWorld = SDK::UWorld::GetWorld();

    if (G::pWorld == nullptr)
      continue;

    if (G::pWorld->PersistentLevel == nullptr)
      continue;

    G::pLevel = G::pWorld->PersistentLevel;

    if (G::pWorld->OwningGameInstance == nullptr)
      continue;

    G::pLocalPlayer =
        G::pWorld->OwningGameInstance->LocalPlayers[0]->PlayerController;

    if (G::pLocalPlayer == nullptr)
      continue;

    G::pActors = &G::pLevel->Actors;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  viewportVtable[G::Offsets::PR_IDX_OFFSET] = Defines::originalPostRenderFn;
  Defines::originalPostRenderFn = nullptr;

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
