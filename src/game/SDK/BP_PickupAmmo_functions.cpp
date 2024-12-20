#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_PickupAmmo

#include "Basic.hpp"

#include "BP_PickupAmmo_classes.hpp"
#include "BP_PickupAmmo_parameters.hpp"


namespace SDK
{

// Function BP_PickupAmmo.BP_PickupAmmo_C.PickupMagazines
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           Actor                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_PickupAmmo_C::PickupMagazines(class AActor* Actor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "PickupMagazines");

	Params::BP_PickupAmmo_C_PickupMagazines Parms{};

	Parms.Actor = Actor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_PickupAmmo.BP_PickupAmmo_C.CheckForOverlappingActors
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void ABP_PickupAmmo_C::CheckForOverlappingActors()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "CheckForOverlappingActors");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PickupAmmo.BP_PickupAmmo_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_PickupAmmo_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PickupAmmo.BP_PickupAmmo_C.BndEvt__BP_PickupAmmo_Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              OverlappedComponent                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              OtherComp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   OtherBodyIndex                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bFromSweep                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FHitResult                       SweepResult                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void ABP_PickupAmmo_C::BndEvt__BP_PickupAmmo_Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "BndEvt__BP_PickupAmmo_Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature");

	Params::BP_PickupAmmo_C_BndEvt__BP_PickupAmmo_Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature Parms{};

	Parms.OverlappedComponent = OverlappedComponent;
	Parms.OtherActor = OtherActor;
	Parms.OtherComp = OtherComp;
	Parms.OtherBodyIndex = OtherBodyIndex;
	Parms.bFromSweep = bFromSweep;
	Parms.SweepResult = std::move(SweepResult);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_PickupAmmo.BP_PickupAmmo_C.InitMag
// (BlueprintCallable, BlueprintEvent)

void ABP_PickupAmmo_C::InitMag()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "InitMag");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PickupAmmo.BP_PickupAmmo_C.SimCheck
// (BlueprintCallable, BlueprintEvent)

void ABP_PickupAmmo_C::SimCheck()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "SimCheck");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PickupAmmo.BP_PickupAmmo_C.ExecuteUbergraph_BP_PickupAmmo
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_PickupAmmo_C::ExecuteUbergraph_BP_PickupAmmo(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PickupAmmo_C", "ExecuteUbergraph_BP_PickupAmmo");

	Params::BP_PickupAmmo_C_ExecuteUbergraph_BP_PickupAmmo Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}

