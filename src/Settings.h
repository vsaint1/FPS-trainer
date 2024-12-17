#pragma once
#include "Utils.h"

namespace Config {

namespace Exploit {
inline bool bGod = false;
inline bool bFly = false;
inline bool bInfiniteAmmo = false;
inline bool bNoRecoil = false;
inline bool bNoSpread = false;
inline bool bOneHitKill = false;
inline bool bRapidFire = false;
inline bool bSpeedHack = false;
inline bool bMagicBullet = false;
}; // namespace Exploit
namespace Visual {
namespace World {
inline bool bEnabled = false;
inline bool bGrenades = false;
inline bool bMap = false;
inline bool bPickups = false;
}; // namespace World
namespace Player {
inline bool bEnabled = false;
inline bool bBox = false;
inline bool bName = false;
inline bool bTeam = false;
inline bool bDistance = false;
inline bool bSnaplines = false;
inline bool bHealthBar = false;
inline bool bSkeleton = false;
inline bool bChamsEnabled = false;
inline bool bPlayerChams = false;
inline bool bWeaponChams = false;

} // namespace Player
} // namespace Visual
} // namespace Config