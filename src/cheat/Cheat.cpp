#include "Cheat.h"

namespace Cheat {
void Run(SDK::TArray<SDK::AActor *> actors, SDK::UCanvas *canvas) {
  auto sSize = Utils::GetScreenSize();

  ZeroGUI::DrawCircle({static_cast<float>(sSize.width / 2),
                       static_cast<float>(sSize.height / 2)},
                      50.0f, 50, {1.0f, 1.0f, 1.0f, 1.0f});

  for (int i = 0; i < actors.Num(); i++) {

    if (!G::pLocalPlayer)
      continue;

    auto *actor = actors[i];

    if (!actor || !actor->RootComponent)
      continue;

    if (Config::Visual::World::bEnabled) {

      if (Config::Visual::World::bPickups) {

        if (actor->IsA(SDK::ABP_PickupWeapon_C::StaticClass())) {

          auto *weapon = static_cast<SDK::ABP_PickupWeapon_C *>(actor);

          if (!weapon)
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

          canvas->K2_DrawText(pFont, Utils::ToWString("Weapon").c_str(),
                              screenPos, {1.f, 1.f}, {1.0f, 1.0f, 1.0f, 0.75f},
                              0.0f, {1.0f, 1.0f}, {200, 200}, true, true, true,
                              {0.0f, 0.0f, 0.0f, 0.45f});

          std::string ammo = std::to_string(weapon->Ammo) + "/??";

          canvas->K2_DrawText(pFont, Utils::ToWString(ammo).c_str(),
                              {screenPos.X, screenPos.Y + 15}, {1.f, 1.f},
                              {1.0f, 1.0f, 1.0f, 0.75f}, 0.0f, {1.0f, 1.0f},
                              {200, 200}, true, true, true,
                              {0.0f, 0.0f, 0.0f, 0.3f});
        }

        if (Config::Visual::World::bGrenades) {

          if (actor->IsA(SDK::ABP_FragGrenadeLethal_C::StaticClass()) ||
              actor->IsA(SDK::ABP_ClaymoreLethal_C::StaticClass()) ||
              actor->IsA(SDK::ABP_BaseLethalEquipment_C::StaticClass())) {

            auto *baseLethal =
                static_cast<SDK::ABP_BaseLethalEquipment_C *>(actor);

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
            auto lethalName = actor->GetName();

            std::regex pattern("BP_(.*?)Lethal_C");
            std::smatch match;

            if (std::regex_search(lethalName, match, pattern)) {
              lethalName = match[1];
            } else {
              lethalName = "LethalUnknown";
            }

            canvas->K2_DrawText(
                pFont, Utils::ToWString(lethalName).c_str(), screenPos,
                {1.f, 1.f}, {1.0f, 1.0f, 1.0f, 0.75f}, 0.0f, {1.0f, 1.0f},
                {200, 200}, true, true, true, {0.0f, 0.0f, 0.0f, 0.5f});
          }

          if (Config::Visual::World::bMap) {

            if (actor->IsA(SDK::ABP_ConquestCapturePoint_C::StaticClass())) {

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

              canvas->K2_DrawText(pFont, L"Capture", screenPos, {1.f, 1.f},
                                  {1.0f, 1.0f, 1.0f, 0.75f}, 0.0f, {1.0f, 1.0f},
                                  {200, 200}, true, true, true,
                                  {0.0f, 0.0f, 0.0f, 0.5f});
            }
          }
        }
      }
    }

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

        Exploit::RapidFire(playerCharacter);

        Exploit::SpeedHack(G::pLocalPlayer);

        Exploit::GodMode(healthComponent);

        Exploit::FlyHack(playerCharacter);

        Exploit::InfiniteAmmo(playerCharacter);

        Exploit::OneHitKill(playerCharacter);

        Exploit::NoRecoil(playerCharacter);

        Exploit::NoSpread(playerCharacter);

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
          sqrt(powf(delta.X, 2) + powf(delta.Y, 2) + powf(delta.Z, 2)) / 1000.f;

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

        ZeroGUI::drawFilledRect(healthBarPos, healthFillWidth, healthBarHeight,
                                {0.f, 1.f, 0.f, 0.8f});
      }

      if (Config::Visual::Player::bSnaplines) {

        canvas->K2_DrawLine({static_cast<float>(sSize.width / 2), 0}, screenPos,
                            1.0f, {1.0f, 1.0f, 1.0f, 1.0f});
      }
    }
  }
}
} // namespace Cheat