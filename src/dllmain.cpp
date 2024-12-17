#include "cheat/esp/Esp.h"
#include "cheat/esp/chams.h"
#include "game/SDK/BP_BaseWeapon_classes.hpp"
#include "game/SDK/BP_CaptureTheFlag_GM_classes.hpp"
#include "game/SDK/BP_ConquestCapturePoint_classes.hpp"
#include "game/SDK/BP_FragGrenadeLethal_classes.hpp"
#include "game/SDK/BP_HealthComponent_classes.hpp"
#include "game/SDK/BP_PlayerCharacter_classes.hpp"
#include "game/SDK/BP_PlayerState_classes.hpp"
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

  static SDK::FVector2D center{300.0f, 300.0f};
  static float size = 50.0f;
  static float thickness = 1.0f;

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

    for (int i = 0; i < actors.Num(); i++) {

      if (!G::pLocalPlayer)
        continue;

      auto *actor = actors[i];

      if (!actor || !actor->RootComponent)
        continue;

      if (actor->IsA(SDK::ABP_PlayerCharacter_C::StaticClass())) {

        SDK::ABP_PlayerCharacter_C *playerCharacter =
            static_cast<SDK::ABP_PlayerCharacter_C *>(actor);

        auto uHealthComponent = playerCharacter->GetComponentByClass(
            SDK::UBP_HealthComponent_C::StaticClass());

        if (!uHealthComponent)
          continue;

        auto healthComponent =
            static_cast<SDK::UBP_HealthComponent_C *>(uHealthComponent);

        if (healthComponent->HP == 0)
          continue;

        auto playerState =
            static_cast<SDK::ABP_PlayerState_C *>(playerCharacter->PlayerState);

        if (!playerState)
          continue;

        if (playerCharacter->Controller == nullptr)
          continue;

        if (playerCharacter->Controller->Pawn == G::pLocalPlayer->Pawn) {

          G::localPlayerTeam = playerState->Team;

          if (Config::Exploit::bRapidFire) {

            playerCharacter->CurrentWeapon->FireRate = 0.0010f;
          }

          if (Config::Exploit::bSpeedHack) {
            G::pLocalPlayer->Character->CharacterMovement->MaxAcceleration =
                9999.f;
            G::pLocalPlayer->Character->CharacterMovement->MaxWalkSpeed =
                1500.0f;
          }

          if (Config::Exploit::bGod) {

            healthComponent->MaxHP = 1337.0f;
            healthComponent->HP = 1337.0f;
          }

          if (Config::Exploit::bFly) {

            playerCharacter->ClientCheatFly();
          }

          if (Config::Exploit::bInfiniteAmmo) {

            playerCharacter->CurrentWeapon->AmmoPerMag = 100;
            playerCharacter->CurrentWeapon->ActualAmmo = 999;
          }

          if (Config::Exploit::bOneHitKill) {
            playerCharacter->CurrentWeapon->Damage = 100;
          }

          if (Config::Exploit::bNoRecoil) {

            playerCharacter->CurrentWeapon->WeaponHorizontalRecoilMax = 0;
            playerCharacter->CurrentWeapon->WeaponHorizontalRecoilMin = 0;
            playerCharacter->CurrentWeapon->WeaponVerticalRecoilMax = 0;
            playerCharacter->CurrentWeapon->WeaponVerticalRecoilMin = 0;
          }

          if (Config::Exploit::bNoSpread) {
            playerCharacter->CurrentWeapon->AimingSpread = 0;
            playerCharacter->CurrentWeapon->WeaponSpread = 0;
          }

          continue;
        }

        if (G::localPlayerTeam == playerState->Team &&
            !Config::Visual::Player::bTeam)
          continue;

        auto worldPos = actor->RootComponent->RelativeLocation;

        if (worldPos.IsZero()) {
          continue;
        }

        SDK::FVector2D screenPos;
        bool bInScreen = G::pLocalPlayer->ProjectWorldLocationToScreen(
            worldPos, &screenPos, false);

        if (!bInScreen) {
          continue;
        }

        auto localPlayerPov =
            G::pLocalPlayer->PlayerCameraManager->CameraCache.POV.Location;
        bool bVisible = G::pLocalPlayer->LineOfSightTo(playerCharacter,
                                                       localPlayerPov, false);

        if (Config::Visual::Player::bSkeleton) {

          Esp::DrawSkeleton(playerCharacter, canvas, bVisible);
        }

        if (Config::Visual::Player::bPlayerChams) {

          Chams::ApplyChams(playerCharacter->Mesh, Chams::chamsMaterial,
                            {0.0f, 1.0f, 0.0f, 0.6f}, {1.f, 0.0f, 0.0f, 0.6f},
                            bVisible);
        }

        if (Config::Visual::Player::bWeaponChams) {
        }

        auto delta =
            G::pLocalPlayer->AcknowledgedPawn->RootComponent->RelativeLocation -
            worldPos;

        float distance =
            sqrt(powf(delta.X, 2) + powf(delta.Y, 2) + powf(delta.Z, 2)) /
            1000.f;

        if (Config::Visual::Player::bDistance) {

          std::string dist =
              "[" + std::to_string(static_cast<int>(distance)) + "m]";

          Esp::DrawDistance(Utils::ToWString(dist).c_str(), canvas,
                            {screenPos.X + 35, screenPos.Y + 15});
        }
        const float baseBoxWidth = 100.0f;
        const float baseBoxHeight = 200.0f;

        float scale = 1.0f / distance;

        float boxWidth = baseBoxWidth * scale;
        float boxHeight = baseBoxHeight * scale;

        if (Config::Visual::Player::bBox) {

          Esp::DrawBoxCorner(canvas, screenPos, boxWidth, boxHeight);
        }

        if (Config::Visual::Player::bName) {
          float offset = 15.f;

          SDK::FVector2D namePos = {screenPos.X - boxWidth / 2 + offset,
                                    screenPos.Y - boxHeight / 2 - offset};

          auto name = !playerState->Name_0 ? L"UKNOWN" : playerState->Name_0;

          canvas->K2_DrawText(pFont, name, namePos, {1.f, 1.f},
                              {1.0f, 1.0f, 1.0f, 0.75f}, 0.0f, {1.0f, 1.0f},
                              {200, 200}, true, true, true,
                              {0.0f, 0.0f, 0.0f, 0.5f});
        }

        if (Config::Visual::Player::bHealthBar) {

          float healthBarWidth = 40.f;
          float healthBarHeight = 5.f;

          SDK::FVector2D healthBarPos = {screenPos.X - healthBarWidth / 2,
                                         screenPos.Y + boxHeight / 2 + 5};

          ZeroGUI::drawFilledRect(healthBarPos, healthBarWidth, healthBarHeight,
                                  {0.f, 0.f, 0.f, 0.8f});

          float healthFillWidth =
              healthBarWidth * (healthComponent->HP / healthComponent->MaxHP);

          ZeroGUI::drawFilledRect(healthBarPos, healthFillWidth,
                                  healthBarHeight, {0.f, 1.f, 0.f, 0.8f});
        }

        if (Config::Visual::Player::bSnaplines) {

          canvas->K2_DrawLine({static_cast<float>(sSize.width / 2), 0},
                              screenPos, 1.0f, {1.0f, 1.0f, 1.0f, 1.0f});
        }
      }
    }
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
