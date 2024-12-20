#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WB_CapturePointIcon1

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "ECapturePointState_structs.hpp"
#include "Engine_structs.hpp"
#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function WB_CapturePointIcon1.WB_CapturePointIcon1_C.GetPlayerDistance
// 0x00C0 (0x00C0 - 0x0000)
struct WB_CapturePointIcon1_C_GetPlayerDistance final
{
public:
	class FText                                   ReturnValue;                                       // 0x0000(0x0018)(Parm, OutParm, ReturnParm)
	class APawn*                                  CallFunc_GetPlayerPawn_ReturnValue;                // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0020(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Subtract_VectorVector_ReturnValue;        // 0x002C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_VSize_ReturnValue;                        // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Divide_FloatFloat_ReturnValue;            // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   CallFunc_Conv_FloatToText_ReturnValue;             // 0x0040(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0058(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0098(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x00A8(0x0018)()
};
static_assert(alignof(WB_CapturePointIcon1_C_GetPlayerDistance) == 0x000008, "Wrong alignment on WB_CapturePointIcon1_C_GetPlayerDistance");
static_assert(sizeof(WB_CapturePointIcon1_C_GetPlayerDistance) == 0x0000C0, "Wrong size on WB_CapturePointIcon1_C_GetPlayerDistance");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, ReturnValue) == 0x000000, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_GetPlayerPawn_ReturnValue) == 0x000018, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_GetPlayerPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000020, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_Subtract_VectorVector_ReturnValue) == 0x00002C, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_Subtract_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_VSize_ReturnValue) == 0x000038, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_VSize_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_Divide_FloatFloat_ReturnValue) == 0x00003C, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_Divide_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_Conv_FloatToText_ReturnValue) == 0x000040, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_Conv_FloatToText_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, K2Node_MakeStruct_FormatArgumentData) == 0x000058, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, K2Node_MakeArray_Array) == 0x000098, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_GetPlayerDistance, CallFunc_Format_ReturnValue) == 0x0000A8, "Member 'WB_CapturePointIcon1_C_GetPlayerDistance::CallFunc_Format_ReturnValue' has a wrong offset!");

// Function WB_CapturePointIcon1.WB_CapturePointIcon1_C.Set Icon
// 0x0008 (0x0008 - 0x0000)
struct WB_CapturePointIcon1_C_Set_Icon final
{
public:
	class UTexture2D*                             Icon_0;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WB_CapturePointIcon1_C_Set_Icon) == 0x000008, "Wrong alignment on WB_CapturePointIcon1_C_Set_Icon");
static_assert(sizeof(WB_CapturePointIcon1_C_Set_Icon) == 0x000008, "Wrong size on WB_CapturePointIcon1_C_Set_Icon");
static_assert(offsetof(WB_CapturePointIcon1_C_Set_Icon, Icon_0) == 0x000000, "Member 'WB_CapturePointIcon1_C_Set_Icon::Icon_0' has a wrong offset!");

// Function WB_CapturePointIcon1.WB_CapturePointIcon1_C.SetIconColor
// 0x0001 (0x0001 - 0x0000)
struct WB_CapturePointIcon1_C_SetIconColor final
{
public:
	ECapturePointState                            Team;                                              // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WB_CapturePointIcon1_C_SetIconColor) == 0x000001, "Wrong alignment on WB_CapturePointIcon1_C_SetIconColor");
static_assert(sizeof(WB_CapturePointIcon1_C_SetIconColor) == 0x000001, "Wrong size on WB_CapturePointIcon1_C_SetIconColor");
static_assert(offsetof(WB_CapturePointIcon1_C_SetIconColor, Team) == 0x000000, "Member 'WB_CapturePointIcon1_C_SetIconColor::Team' has a wrong offset!");

// Function WB_CapturePointIcon1.WB_CapturePointIcon1_C.ExecuteUbergraph_WB_CapturePointIcon1
// 0x0138 (0x0138 - 0x0000)
struct WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1 final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECapturePointState                            Temp_byte_Variable;                                // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           Temp_struct_Variable;                              // 0x0008(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Temp_struct_Variable_1;                            // 0x0018(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Temp_struct_Variable_2;                            // 0x0028(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Temp_struct_Variable_3;                            // 0x0038(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Temp_struct_Variable_4;                            // 0x0048(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsAnimationPlaying_ReturnValue;           // 0x0058(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_59[0x7];                                       // 0x0059(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             K2Node_CustomEvent_Icon;                           // 0x0068(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSlateBrush                            K2Node_MakeStruct_SlateBrush;                      // 0x0070(0x0088)()
	ECapturePointState                            K2Node_CustomEvent_Team;                           // 0x00F8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F9[0x3];                                       // 0x00F9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           K2Node_Select_Default;                             // 0x00FC(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_10C[0x4];                                      // 0x010C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x0110(0x0028)()
};
static_assert(alignof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1) == 0x000008, "Wrong alignment on WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1");
static_assert(sizeof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1) == 0x000138, "Wrong size on WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, EntryPoint) == 0x000000, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::EntryPoint' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, Temp_byte_Variable) == 0x000004, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, Temp_struct_Variable) == 0x000008, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::Temp_struct_Variable' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, Temp_struct_Variable_1) == 0x000018, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::Temp_struct_Variable_1' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, Temp_struct_Variable_2) == 0x000028, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::Temp_struct_Variable_2' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, Temp_struct_Variable_3) == 0x000038, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::Temp_struct_Variable_3' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, Temp_struct_Variable_4) == 0x000048, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::Temp_struct_Variable_4' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, CallFunc_IsAnimationPlaying_ReturnValue) == 0x000058, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::CallFunc_IsAnimationPlaying_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, CallFunc_PlayAnimation_ReturnValue) == 0x000060, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::CallFunc_PlayAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, K2Node_CustomEvent_Icon) == 0x000068, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::K2Node_CustomEvent_Icon' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, K2Node_MakeStruct_SlateBrush) == 0x000070, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::K2Node_MakeStruct_SlateBrush' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, K2Node_CustomEvent_Team) == 0x0000F8, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::K2Node_CustomEvent_Team' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, K2Node_Select_Default) == 0x0000FC, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1, K2Node_MakeStruct_SlateColor) == 0x000110, "Member 'WB_CapturePointIcon1_C_ExecuteUbergraph_WB_CapturePointIcon1::K2Node_MakeStruct_SlateColor' has a wrong offset!");

}

