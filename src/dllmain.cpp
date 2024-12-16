#include "Utils.h"
#include "game/SDK/BP_BaseWeapon_classes.hpp"
#include "game/SDK/BP_CaptureTheFlag_GM_classes.hpp"
#include "game/SDK/BP_ConquestCapturePoint_classes.hpp"
#include "game/SDK/BP_FragGrenadeLethal_classes.hpp"
#include "game/SDK/BP_HealthComponent_classes.hpp"
#include "game/SDK/BP_PlayerCharacter_classes.hpp"
#include "game/SDK/BP_PlayerState_classes.hpp"
#include "gui/Menu.h"
#include "hooks/Hooks.h"

int localTeam = 0;

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

      if (Config::Esp::Player::bEnabled) {

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

          auto playerState = static_cast<SDK::ABP_PlayerState_C *>(
              playerCharacter->PlayerState);

          if (!playerState)
            continue;

          if (playerCharacter->Controller->Pawn == G::pLocalPlayer->Pawn) {
            localTeam = playerState->Team;
            continue;
          }

          if (localTeam == playerState->Team && !Config::Esp::Player::bTeam)
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

          if (Config::Esp::Player::bName)
            canvas->K2_DrawText(pFont, playerState->PlayerNamePrivate,
                                {screenPos.X, screenPos.Y + 50}, {1.f, 1.f},
                                {1.0f, 0.0f, 0.0f, 1.0f}, 0.0f, {1.0f, 1.0f},
                                {200, 200}, true, true, true,
                                {0.0f, 0.0f, 0.0f, 0.5f});

          auto delta = G::pLocalPlayer->AcknowledgedPawn->RootComponent
                           ->RelativeLocation -
                       worldPos;

          float distance =
              sqrt(powf(delta.X, 2) + powf(delta.Y, 2) + powf(delta.Z, 2)) /
              1000.f;

          if (Config::Esp::Player::bDistance) {

            std::string dist =
                "[" + std::to_string(static_cast<int>(distance)) + "m]";

            canvas->K2_DrawText(pFont, Utils::ToWString(dist).c_str(),
                                {screenPos.X + 35, screenPos.Y + 15},
                                {0.8f, 0.8f}, {1.0f, 1.0f, 1.0f, 0.8f}, 0.0f,
                                {1.0f, 1.0f}, {200, 200}, true, true, true,
                                {0.0f, 0.0f, 0.0f, 0.5f});
          }

          const float baseBoxWidth = 100.0f;
          const float baseBoxHeight = 200.0f;

          float scale = 1.0f / distance;

          float boxWidth = baseBoxWidth * scale;
          float boxHeight = baseBoxHeight * scale;

          if (Config::Esp::Player::bBox) {

            SDK::FVector2D topLeft = {screenPos.X - boxWidth / 2,
                                      screenPos.Y - boxHeight / 2};
            SDK::FVector2D topRight = {screenPos.X + boxWidth / 2,
                                       screenPos.Y - boxHeight / 2};
            SDK::FVector2D bottomLeft = {screenPos.X - boxWidth / 2,
                                         screenPos.Y + boxHeight / 2};
            SDK::FVector2D bottomRight = {screenPos.X + boxWidth / 2,
                                          screenPos.Y + boxHeight / 2};

            // Top-left corner
            canvas->K2_DrawLine(topLeft, {topLeft.X + 10, topLeft.Y}, 1.f,
                                {1.f, 0.f, 0.f, 1.f});
            canvas->K2_DrawLine(topLeft, {topLeft.X, topLeft.Y + 10}, 1.f,
                                {1.f, 0.f, 0.f, 1.f});

            // Top-right corner
            canvas->K2_DrawLine(topRight, {topRight.X - 10, topRight.Y}, 1.f,
                                {1.f, 0.f, 0.f, 1.f});
            canvas->K2_DrawLine(topRight, {topRight.X, topRight.Y + 10}, 1.f,
                                {1.f, 0.f, 0.f, 1.f});

            // Bottom-left corner
            canvas->K2_DrawLine(bottomLeft, {bottomLeft.X + 10, bottomLeft.Y},
                                1.f, {1.f, 0.f, 0.f, 1.f});
            canvas->K2_DrawLine(bottomLeft, {bottomLeft.X, bottomLeft.Y - 10},
                                1.f, {1.f, 0.f, 0.f, 1.f});

            // Bottom-right corner
            canvas->K2_DrawLine(bottomRight,
                                {bottomRight.X - 10, bottomRight.Y}, 1.f,
                                {1.f, 0.f, 0.f, 1.f});
            canvas->K2_DrawLine(bottomRight,
                                {bottomRight.X, bottomRight.Y - 10}, 1.f,
                                {1.f, 0.f, 0.f, 1.f});
          }

          if (Config::Esp::Player::bHealthBar) {

            float healthBarWidth = 40.f;
            float healthBarHeight = 5.f;

            SDK::FVector2D healthBarPos = {screenPos.X - healthBarWidth / 2,
                                           screenPos.Y + boxHeight / 2 + 5};

            ZeroGUI::drawFilledRect(healthBarPos, healthBarWidth,
                                    healthBarHeight, {0.f, 0.f, 0.f, 0.8f});

            float healthFillWidth =
                healthBarWidth * (healthComponent->HP / healthComponent->MaxHP);

            ZeroGUI::drawFilledRect(healthBarPos, healthFillWidth,
                                    healthBarHeight, {0.f, 1.f, 0.f, 0.8f});
          }

          if (Config::Esp::Player::bSnaplines) {

            canvas->K2_DrawLine({static_cast<float>(sSize.width / 2), 0},
                                screenPos, 1.0f, {1.0f, 1.0f, 1.0f, 1.0f});
          }
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

  // Hooks::Remove(viewportVtable, G::Offsets::PR_IDX_OFFSET,
  //               Defines::originalPostRenderFn);

  viewportVtable[0x63] = Defines::originalPostRenderFn;
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
