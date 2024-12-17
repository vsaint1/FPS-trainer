#include "Chams.h"

namespace Chams {

void ApplyChams(SDK::USkeletalMeshComponent *mesh,
                SDK::UMaterialInstanceDynamic *materialDyn,
                SDK::FLinearColor visibleColor, SDK::FLinearColor occludedColor,
                bool visibility) {

  if (!Config::Visual::Player::bChamsEnabled)
    return;

  if (Chams::wireFrameMaterial == nullptr)
    return;

  if (Chams::chamsVisibleMaterial == nullptr)
    return;

  if (Chams::chamsOccludedMaterial == nullptr)
    return;

  auto mats = mesh->GetMaterials();

  mesh->bRenderCustomDepth = true;
  mesh->CustomDepthStencilValue = 1;

  if (visibility) {

    chamsVisibleMaterial->SetVectorParameterValue(Utils::ToFName(L"Color"),
                                                  visibleColor);

    chamsVisibleMaterial->SetScalarParameterValue(
        Utils::ToFName(L"OutlineThickness"), 2.0f);

    chamsVisibleMaterial->SetVectorParameterValue(
        Utils::ToFName(L"OutlineColor"), {1.f, 1.0f, 1.0f, 1.0f});

    for (int i = 0; i < mats.Num(); i++) {
      if (mats[i] && mats[i] != chamsVisibleMaterial) {
        mesh->SetMaterial(i, chamsVisibleMaterial);
      }
    }

  } else {

    chamsOccludedMaterial->SetVectorParameterValue(Utils::ToFName(L"Color"),
                                                   occludedColor);

    chamsVisibleMaterial->SetScalarParameterValue(
        Utils::ToFName(L"OutlineThickness"), 2.0f);

    chamsVisibleMaterial->SetVectorParameterValue(
        Utils::ToFName(L"OutlineColor"), {1.f, 1.0f, 1.0f, 1.0f});

    for (int i = 0; i < mats.Num(); i++) {
      if (mats[i] && mats[i] != chamsOccludedMaterial) {
        mesh->SetMaterial(i, chamsOccludedMaterial);
      }
    }
  }
}
} // namespace Chams