#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_BaseLethalEquipment

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "ELethalEquipment_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_BaseLethalEquipment.BP_BaseLethalEquipment_C
// 0x0080 (0x02A0 - 0x0220)
class ABP_BaseLethalEquipment_C : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UStaticMeshComponent*                   TPP_Mesh;                                          // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   FPP_Mesh;                                          // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0238(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	struct FTransform                             Offset;                                            // 0x0240(0x0030)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	class UAnimMontage*                           FPP_UseExplosive;                                  // 0x0270(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           TPP_UseExplosive;                                  // 0x0278(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 ExplosiveToSpawn;                                  // 0x0280(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture*                               UI_Icon;                                           // 0x0288(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHasDelayedThrow;                                  // 0x0290(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_291[0x3];                                      // 0x0291(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         TimeToExplode;                                     // 0x0294(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ELethalEquipment                              Type;                                              // 0x0298(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Activate();
	void ReceiveBeginPlay();
	void OnRelease();
	void ReleaseLethal();
	void DropLethal();
	void ExecuteUbergraph_BP_BaseLethalEquipment(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_BaseLethalEquipment_C">();
	}
	static class ABP_BaseLethalEquipment_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_BaseLethalEquipment_C>();
	}
};
static_assert(alignof(ABP_BaseLethalEquipment_C) == 0x000010, "Wrong alignment on ABP_BaseLethalEquipment_C");
static_assert(sizeof(ABP_BaseLethalEquipment_C) == 0x0002A0, "Wrong size on ABP_BaseLethalEquipment_C");
static_assert(offsetof(ABP_BaseLethalEquipment_C, UberGraphFrame) == 0x000220, "Member 'ABP_BaseLethalEquipment_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, TPP_Mesh) == 0x000228, "Member 'ABP_BaseLethalEquipment_C::TPP_Mesh' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, FPP_Mesh) == 0x000230, "Member 'ABP_BaseLethalEquipment_C::FPP_Mesh' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, DefaultSceneRoot) == 0x000238, "Member 'ABP_BaseLethalEquipment_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, Offset) == 0x000240, "Member 'ABP_BaseLethalEquipment_C::Offset' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, FPP_UseExplosive) == 0x000270, "Member 'ABP_BaseLethalEquipment_C::FPP_UseExplosive' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, TPP_UseExplosive) == 0x000278, "Member 'ABP_BaseLethalEquipment_C::TPP_UseExplosive' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, ExplosiveToSpawn) == 0x000280, "Member 'ABP_BaseLethalEquipment_C::ExplosiveToSpawn' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, UI_Icon) == 0x000288, "Member 'ABP_BaseLethalEquipment_C::UI_Icon' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, bHasDelayedThrow) == 0x000290, "Member 'ABP_BaseLethalEquipment_C::bHasDelayedThrow' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, TimeToExplode) == 0x000294, "Member 'ABP_BaseLethalEquipment_C::TimeToExplode' has a wrong offset!");
static_assert(offsetof(ABP_BaseLethalEquipment_C, Type) == 0x000298, "Member 'ABP_BaseLethalEquipment_C::Type' has a wrong offset!");

}

