#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_SupportClass_A

#include "Basic.hpp"

#include "BP_SupportClass_A_classes.hpp"
#include "BP_SupportClass_A_parameters.hpp"


namespace SDK
{

// Function BP_SupportClass_A.BP_SupportClass_A_C.ExecuteUbergraph_BP_SupportClass_A
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_SupportClass_A_C::ExecuteUbergraph_BP_SupportClass_A(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_SupportClass_A_C", "ExecuteUbergraph_BP_SupportClass_A");

	Params::BP_SupportClass_A_C_ExecuteUbergraph_BP_SupportClass_A Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_SupportClass_A.BP_SupportClass_A_C.ThrowItem
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_SupportClass_A_C::ThrowItem()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_SupportClass_A_C", "ThrowItem");

	UObject::ProcessEvent(Func, nullptr);
}

}

