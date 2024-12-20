#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_BaseCharacter

#include "Basic.hpp"

#include "EEquipedWeapon_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "ELethalEquipment_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_BaseCharacter.BP_BaseCharacter_C
// 0x0040 (0x0500 - 0x04C0)
class ABP_BaseCharacter_C : public ACharacter
{
public:
	uint8                                         Pad_4B8[0x8];                                      // 0x04B8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x04C0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	EEquipedWeapon                                EquippedWeapon;                                    // 0x04C8(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	bool                                          bRunning;                                          // 0x04C9(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay)
	bool                                          bAiming;                                           // 0x04CA(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay)
	bool                                          bUsingTPP;                                         // 0x04CB(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay)
	uint8                                         Pad_4CC[0x4];                                      // 0x04CC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ABP_BaseWeapon_C*                       CurrentWeapon;                                     // 0x04D0(0x0008)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, RepNotify, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	bool                                          bDead;                                             // 0x04D8(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, RepNotify, NoDestructor, AdvancedDisplay)
	uint8                                         Pad_4D9[0x7];                                      // 0x04D9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnDeath;                                           // 0x04E0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	float                                         Right;                                             // 0x04F0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	float                                         Up;                                                // 0x04F4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	bool                                          bLeaningRight;                                     // 0x04F8(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bLeaningLeft;                                      // 0x04F9(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bUsingLethal;                                      // 0x04FA(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	ELethalEquipment                              LethalType;                                        // 0x04FB(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void OnDeadRep();
	void OnRep_bDead();
	void OnRep_CurrentWeapon();
	void OnCurrentWeaponChanged();
	void OnPawnDead();
	void OnEquippedWeaponChanged();
	void ExecuteUbergraph_BP_BaseCharacter(int32 EntryPoint);
	void OnDeath__DelegateSignature();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_BaseCharacter_C">();
	}
	static class ABP_BaseCharacter_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_BaseCharacter_C>();
	}
};
static_assert(alignof(ABP_BaseCharacter_C) == 0x000010, "Wrong alignment on ABP_BaseCharacter_C");
static_assert(sizeof(ABP_BaseCharacter_C) == 0x000500, "Wrong size on ABP_BaseCharacter_C");
static_assert(offsetof(ABP_BaseCharacter_C, UberGraphFrame) == 0x0004C0, "Member 'ABP_BaseCharacter_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, EquippedWeapon) == 0x0004C8, "Member 'ABP_BaseCharacter_C::EquippedWeapon' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bRunning) == 0x0004C9, "Member 'ABP_BaseCharacter_C::bRunning' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bAiming) == 0x0004CA, "Member 'ABP_BaseCharacter_C::bAiming' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bUsingTPP) == 0x0004CB, "Member 'ABP_BaseCharacter_C::bUsingTPP' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, CurrentWeapon) == 0x0004D0, "Member 'ABP_BaseCharacter_C::CurrentWeapon' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bDead) == 0x0004D8, "Member 'ABP_BaseCharacter_C::bDead' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, OnDeath) == 0x0004E0, "Member 'ABP_BaseCharacter_C::OnDeath' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, Right) == 0x0004F0, "Member 'ABP_BaseCharacter_C::Right' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, Up) == 0x0004F4, "Member 'ABP_BaseCharacter_C::Up' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bLeaningRight) == 0x0004F8, "Member 'ABP_BaseCharacter_C::bLeaningRight' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bLeaningLeft) == 0x0004F9, "Member 'ABP_BaseCharacter_C::bLeaningLeft' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, bUsingLethal) == 0x0004FA, "Member 'ABP_BaseCharacter_C::bUsingLethal' has a wrong offset!");
static_assert(offsetof(ABP_BaseCharacter_C, LethalType) == 0x0004FB, "Member 'ABP_BaseCharacter_C::LethalType' has a wrong offset!");

}

