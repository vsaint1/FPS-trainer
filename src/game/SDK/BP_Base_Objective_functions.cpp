#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Base_Objective

#include "Basic.hpp"

#include "BP_Base_Objective_classes.hpp"
#include "BP_Base_Objective_parameters.hpp"


namespace SDK
{

// Function BP_Base_Objective.BP_Base_Objective_C.CreateObjectiveMarker
// (BlueprintCallable, BlueprintEvent)

void ABP_Base_Objective_C::CreateObjectiveMarker()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Base_Objective_C", "CreateObjectiveMarker");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Base_Objective.BP_Base_Objective_C.ExecuteUbergraph_BP_Base_Objective
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_Base_Objective_C::ExecuteUbergraph_BP_Base_Objective(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Base_Objective_C", "ExecuteUbergraph_BP_Base_Objective");

	Params::BP_Base_Objective_C_ExecuteUbergraph_BP_Base_Objective Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Base_Objective.BP_Base_Objective_C.UpdateObjective__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void ABP_Base_Objective_C::UpdateObjective__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Base_Objective_C", "UpdateObjective__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}

}

