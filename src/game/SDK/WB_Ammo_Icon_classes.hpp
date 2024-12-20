#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WB_Ammo_Icon

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "EFiringMode_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_Ammo_Icon.WB_Ammo_Icon_C
// 0x0020 (0x0280 - 0x0260)
class UWB_Ammo_Icon_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0260(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       OnStart_Icon_Anim;                                 // 0x0268(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Icon;                                              // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FTimerHandle                           HideWidgetTimer;                                   // 0x0278(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void OnOwnerDeath();
	void ShowHitMarker(bool bVehicle);
	void ShowKillMarker();
	void UpdateFiringMode(EFiringMode NewFiringMode);
	void UpdateHP(float NewHP, float MaxHP);
	void UpdateCurrentBullets(int32 CurrentBullets, int32 BulletsPerMag);
	void UpdateTotalBullets(int32 TotalBullets);
	void ShowHitOverlay();
	void UpdateMatchTimer(float TimeInSeconds);
	void UpdateGameModeScores(int32 TeamAPoints, int32 TeamBPoints, int32 PointsToWin);
	void UpdateKillFeed(class APlayerState* Killer, class APlayerState* Victim, const class UDamageType* DamageType, class APlayerState* Assist, bool bHeadshot);
	void ShowScore(float Score, const class FText& Reason);
	void HideWeaponInfo();
	void UpdateObjectiveMarkers(class ABP_Base_Objective_C* ObjectiveToUpdate, bool PlayIconAnim, int32 Team);
	void ShowInteractProgressBar(float InteractTime);
	void HideInteractProgressBar();
	void ShowHealOverlay();
	void ShowInteractInfo(const class FText& Description);
	void HideInteractInfo();
	void ShowAbilityCooldownTime(float TimeRemaining);
	void UpdateExplosives(int32 ExplosivesAmount, class UTexture* Icon_0);
	void UpdateRushScores(int32 Reinforcements, int32 TotalReinforcements);
	void UpdateDeathmatchScores(const class FString& WinnerName, int32 WinnerKills, int32 KillsToWin);
	void UpdateTeamIcon(class UTexture* TeamIcon);
	void ShowCrouchIcon();
	void ShowStandingIcon();
	void UpdateSkillIcon(class UTexture2D* SkillIcon);
	void SetWidgetVisibility();
	void ShowWidget();
	void HideWidget();
	void ExecuteUbergraph_WB_Ammo_Icon(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_Ammo_Icon_C">();
	}
	static class UWB_Ammo_Icon_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_Ammo_Icon_C>();
	}
};
static_assert(alignof(UWB_Ammo_Icon_C) == 0x000008, "Wrong alignment on UWB_Ammo_Icon_C");
static_assert(sizeof(UWB_Ammo_Icon_C) == 0x000280, "Wrong size on UWB_Ammo_Icon_C");
static_assert(offsetof(UWB_Ammo_Icon_C, UberGraphFrame) == 0x000260, "Member 'UWB_Ammo_Icon_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWB_Ammo_Icon_C, OnStart_Icon_Anim) == 0x000268, "Member 'UWB_Ammo_Icon_C::OnStart_Icon_Anim' has a wrong offset!");
static_assert(offsetof(UWB_Ammo_Icon_C, Icon) == 0x000270, "Member 'UWB_Ammo_Icon_C::Icon' has a wrong offset!");
static_assert(offsetof(UWB_Ammo_Icon_C, HideWidgetTimer) == 0x000278, "Member 'UWB_Ammo_Icon_C::HideWidgetTimer' has a wrong offset!");

}

