#pragma once
#include "../../Globals.h"
#include "../../Settings.h"
#include "../../Utils.h"

namespace Chams {

inline SDK::UMaterial *wireFrameMaterial = nullptr;

inline  SDK::UMaterialInstanceDynamic *chamsMaterial = nullptr;
inline  SDK::UMaterialInstanceDynamic *chamsVisibleMaterial = nullptr;
inline SDK::UMaterialInstanceDynamic *chamsOccludedMaterial = nullptr;

void CreateMaterial(SDK::UWorld* world,const char* materialName);

void ApplyChams(SDK::USkeletalMeshComponent *mesh,
                SDK::UMaterialInstanceDynamic *materialDyn,
                SDK::FLinearColor visibleColor, SDK::FLinearColor occludedColor,
                bool visibility);

} // namespace Chams