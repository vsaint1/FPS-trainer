#include "Chams.h"

namespace Chams {

void CreateMaterial(SDK::UWorld *world, const char *materialName) {
  Chams::wireFrameMaterial =
      SDK::UObject::FindObject<SDK::UMaterial>(materialName);

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
          world, Chams::wireFrameMaterial, Utils::ToFName(L"ChamsMaterial"),
          SDK::EMIDCreationFlags::Transient);

  Chams::chamsVisibleMaterial =
      SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(
          world, Chams::wireFrameMaterial,
          Utils::ToFName(L"ChamsVisibleMaterial"),
          SDK::EMIDCreationFlags::Transient);

  Chams::chamsOccludedMaterial =
      SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(
          world, Chams::wireFrameMaterial,
          Utils::ToFName(L"ChamsOccludedMaterial"),
          SDK::EMIDCreationFlags::Transient);
}

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