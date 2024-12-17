#include "Esp.h"

namespace Esp {

void DrawSkeleton(SDK::APawn *pawn, SDK::UCanvas *canvas, bool visibility) {

  if (!pawn)
    return;

  if (!pawn->Controller)
    return;

  if (!pawn->Controller->Character)
    return;

  SDK::USkeletalMeshComponent *mesh = pawn->Controller->Character->Mesh;

  if (!mesh)
    return;

  const int32_t numBones = mesh->GetNumBones();

  for (int32_t boneIndex = 2; boneIndex < numBones; ++boneIndex) {
    if (boneIndex >= 60)
      continue;

    SDK::FName boneName = mesh->GetBoneName(boneIndex);

    SDK::FVector boneWorldPos = mesh->GetSocketLocation(boneName);
    SDK::FVector2D boneScreenPos;

    SDK::FLinearColor visibleColor =
        visibility ? SDK::FLinearColor(0.0f, 1.0f, 0.0f, 1.0f)
                   : SDK::FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);

    if (G::pLocalPlayer->ProjectWorldLocationToScreen(boneWorldPos,
                                                      &boneScreenPos, false)) {
      // U_LOG("Bone: %s | ScreenPos: (%.1f, %.1f)",
      // boneName.ToString().c_str(),
      //       boneScreenPos.X, boneScreenPos.Y);

      SDK::FName parentBoneName = mesh->GetParentBone(boneName);

      SDK::FVector parentBoneWorldPos = mesh->GetSocketLocation(parentBoneName);
      SDK::FVector2D parentBoneScreenPos;

      if (G::pLocalPlayer->ProjectWorldLocationToScreen(
              parentBoneWorldPos, &parentBoneScreenPos, false)) {
        canvas->K2_DrawLine(boneScreenPos, parentBoneScreenPos, 1.0f,
                            visibleColor);
      }
    }

    if (boneMap.find(boneIndex) == boneMap.end()) {
      boneMap.insert({boneIndex, boneName});
    }
  }
}

void DrawName(const SDK::FString &playerName, SDK::UCanvas *canvas,
              SDK::FVector2D pos2D) {

  SDK::FString name = !playerName ? L"UNKNOWN" : playerName;

  canvas->K2_DrawText(pFont, name, {pos2D.X, pos2D.Y + 40}, {1.f, 1.f},
                      {1.0f, 1.0f, 1.0f, 0.75f}, 0.0f, {1.0f, 1.0f}, {200, 200},
                      true, true, true, {0.0f, 0.0f, 0.0f, 0.5f});
}
void DrawDistance(const SDK::FString &distance, SDK::UCanvas *canvas,
                  SDK::FVector2D pos2D) {
  if (!Config::Visual::Player::bEnabled)
    return;

  canvas->K2_DrawText(pFont, distance, pos2D, {0.8f, 0.8f},
                      {0.8f, 0.7f, 0.0f, 0.8f}, 0.0f, {1.0f, 1.0f}, {200, 200},
                      true, true, true, {0.0f, 0.0f, 0.0f, 0.5f});
}
void DrawBoxCorner(SDK::UCanvas *canvas, SDK::FVector2D pos2D, float boxWidth,
                   float boxHeight) {
  if (!Config::Visual::Player::bEnabled)
    return;

  SDK::FVector2D topLeft = {pos2D.X - boxWidth / 2, pos2D.Y - boxHeight / 2};
  SDK::FVector2D topRight = {pos2D.X + boxWidth / 2, pos2D.Y - boxHeight / 2};
  SDK::FVector2D bottomLeft = {pos2D.X - boxWidth / 2, pos2D.Y + boxHeight / 2};
  SDK::FVector2D bottomRight = {pos2D.X + boxWidth / 2,
                                pos2D.Y + boxHeight / 2};

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
  canvas->K2_DrawLine(bottomLeft, {bottomLeft.X + 10, bottomLeft.Y}, 1.f,
                      {1.f, 0.f, 0.f, 1.f});
  canvas->K2_DrawLine(bottomLeft, {bottomLeft.X, bottomLeft.Y - 10}, 1.f,
                      {1.f, 0.f, 0.f, 1.f});

  // Bottom-right corner
  canvas->K2_DrawLine(bottomRight, {bottomRight.X - 10, bottomRight.Y}, 1.f,
                      {1.f, 0.f, 0.f, 1.f});
  canvas->K2_DrawLine(bottomRight, {bottomRight.X, bottomRight.Y - 10}, 1.f,
                      {1.f, 0.f, 0.f, 1.f});
}

} // namespace Esp