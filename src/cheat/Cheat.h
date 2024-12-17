#pragma once
#include "../game/SDK/BP_BaseWeapon_classes.hpp"
#include "../game/SDK/BP_CaptureTheFlag_GM_classes.hpp"
#include "../game/SDK/BP_ConquestCapturePoint_classes.hpp"
#include "../game/SDK/BP_FragGrenadeLethal_classes.hpp"
#include "../game/SDK/BP_HealthComponent_classes.hpp"
#include "../game/SDK/BP_PlayerCharacter_classes.hpp"
#include "../game/SDK/BP_PlayerState_classes.hpp"
#include "../game/SDK/BP_BaseLethalEquipment_classes.hpp"
#include "../game/SDK/BP_FragGrenadeLethal_classes.hpp"
#include "../game/SDK/BP_ClaymoreLethal_classes.hpp"
#include "../game/SDK/BP_PickupWeapon_classes.hpp"
#include "../game/SDK/BP_PickupAmmo_classes.hpp"
#include "../gui/ZeroGUI.h"
#include "esp/Esp.h"
#include "esp/chams.h"
#include "exploits/Exploits.h"

namespace Cheat {

void Run(SDK::TArray<SDK::AActor *> actors, SDK::UCanvas *canvas);

}