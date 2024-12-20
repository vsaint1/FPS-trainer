#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ImpactGrenadeLethal

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BP_BaseLethalEquipment_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ImpactGrenadeLethal.BP_ImpactGrenadeLethal_C
// 0x0020 (0x02C0 - 0x02A0)
class ABP_ImpactGrenadeLethal_C final : public ABP_BaseLethalEquipment_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_BP_ImpactGrenadeLethal_C;           // 0x02A0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FTimerHandle                           CookGrenadeTimer;                                  // 0x02A8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class UWB_CookingGrenade_C*                   CookingGrenadeWidget;                              // 0x02B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bReleased;                                         // 0x02B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void Activate();
	void OnRelease();
	void ReleaseLethal();
	void UserConstructionScript();
	void ExplodeGrenade();
	void Server_SpawnGrenade(float TimeLeft, const struct FVector& Spawn_Transform_Location);
	void Reset();
	void Client_ReduceLethalAmmo();
	void DropLethal();
	void ExecuteUbergraph_BP_ImpactGrenadeLethal(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ImpactGrenadeLethal_C">();
	}
	static class ABP_ImpactGrenadeLethal_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ImpactGrenadeLethal_C>();
	}
};
static_assert(alignof(ABP_ImpactGrenadeLethal_C) == 0x000010, "Wrong alignment on ABP_ImpactGrenadeLethal_C");
static_assert(sizeof(ABP_ImpactGrenadeLethal_C) == 0x0002C0, "Wrong size on ABP_ImpactGrenadeLethal_C");
static_assert(offsetof(ABP_ImpactGrenadeLethal_C, UberGraphFrame_BP_ImpactGrenadeLethal_C) == 0x0002A0, "Member 'ABP_ImpactGrenadeLethal_C::UberGraphFrame_BP_ImpactGrenadeLethal_C' has a wrong offset!");
static_assert(offsetof(ABP_ImpactGrenadeLethal_C, CookGrenadeTimer) == 0x0002A8, "Member 'ABP_ImpactGrenadeLethal_C::CookGrenadeTimer' has a wrong offset!");
static_assert(offsetof(ABP_ImpactGrenadeLethal_C, CookingGrenadeWidget) == 0x0002B0, "Member 'ABP_ImpactGrenadeLethal_C::CookingGrenadeWidget' has a wrong offset!");
static_assert(offsetof(ABP_ImpactGrenadeLethal_C, bReleased) == 0x0002B8, "Member 'ABP_ImpactGrenadeLethal_C::bReleased' has a wrong offset!");

}

