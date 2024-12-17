#pragma once
#include "../../Globals.h"
#include "../../Settings.h"
#include "../../Utils.h"


namespace Esp {
inline std::unordered_map<std::int32_t, SDK::FName> boneMap;

void DrawSkeleton(SDK::APawn *pawn, SDK::UCanvas *canvas, bool visibility);

void DrawName(const SDK::FString &pawnName, SDK::UCanvas *canvas,
              SDK::FVector2D pos2D);

void DrawDistance(const SDK::FString &distance, SDK::UCanvas *canvas,
                  SDK::FVector2D pos2D);

void DrawBoxCorner(SDK::UCanvas *canvas, SDK::FVector2D pos2D, float boxWidth,
                   float boxHeight);


} // namespace Esp