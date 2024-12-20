#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_BaseLethalEquipment

#include "Basic.hpp"

#include "BP_BaseLethalEquipment_classes.hpp"
#include "BP_BaseLethalEquipment_parameters.hpp"


namespace SDK
{

// Function BP_BaseLethalEquipment.BP_BaseLethalEquipment_C.Activate
// (BlueprintCallable, BlueprintEvent)

void ABP_BaseLethalEquipment_C::Activate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_BaseLethalEquipment_C", "Activate");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_BaseLethalEquipment.BP_BaseLethalEquipment_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_BaseLethalEquipment_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_BaseLethalEquipment_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_BaseLethalEquipment.BP_BaseLethalEquipment_C.OnRelease
// (BlueprintCallable, BlueprintEvent)

void ABP_BaseLethalEquipment_C::OnRelease()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_BaseLethalEquipment_C", "OnRelease");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_BaseLethalEquipment.BP_BaseLethalEquipment_C.ReleaseLethal
// (BlueprintCallable, BlueprintEvent)

void ABP_BaseLethalEquipment_C::ReleaseLethal()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_BaseLethalEquipment_C", "ReleaseLethal");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_BaseLethalEquipment.BP_BaseLethalEquipment_C.DropLethal
// (BlueprintCallable, BlueprintEvent)

void ABP_BaseLethalEquipment_C::DropLethal()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_BaseLethalEquipment_C", "DropLethal");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_BaseLethalEquipment.BP_BaseLethalEquipment_C.ExecuteUbergraph_BP_BaseLethalEquipment
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_BaseLethalEquipment_C::ExecuteUbergraph_BP_BaseLethalEquipment(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_BaseLethalEquipment_C", "ExecuteUbergraph_BP_BaseLethalEquipment");

	Params::BP_BaseLethalEquipment_C_ExecuteUbergraph_BP_BaseLethalEquipment Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}

