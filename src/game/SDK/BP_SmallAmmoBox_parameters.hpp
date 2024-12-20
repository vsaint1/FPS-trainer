#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_SmallAmmoBox

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function BP_SmallAmmoBox.BP_SmallAmmoBox_C.FindOverlappingActorOnActivation
// 0x0060 (0x0060 - 0x0000)
struct BP_SmallAmmoBox_C_FindOverlappingActorOnActivation final
{
public:
	class ACharacter*                             OverlappingActor;                                  // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AActor*>                         CallFunc_GetOverlappingActors_OverlappingActors;   // 0x0018(0x0010)(ReferenceParm)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 CallFunc_Array_Get_Item;                           // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ACharacter*                             K2Node_DynamicCast_AsCharacter;                    // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_41[0x3];                                       // 0x0041(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0044(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TScriptInterface<class IIPawnActions_C>       K2Node_DynamicCast_AsI_Pawn_Actions;               // 0x0048(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0058(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0059(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_CharacterdNeedsAmmo_bNeedsAmmo;           // 0x005A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation) == 0x000008, "Wrong alignment on BP_SmallAmmoBox_C_FindOverlappingActorOnActivation");
static_assert(sizeof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation) == 0x000060, "Wrong size on BP_SmallAmmoBox_C_FindOverlappingActorOnActivation");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, OverlappingActor) == 0x000000, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::OverlappingActor' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, Temp_int_Loop_Counter_Variable) == 0x000008, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_Add_IntInt_ReturnValue) == 0x00000C, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, Temp_int_Array_Index_Variable) == 0x000010, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_IsValid_ReturnValue) == 0x000014, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_GetOverlappingActors_OverlappingActors) == 0x000018, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_GetOverlappingActors_OverlappingActors' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_IsValid_ReturnValue_1) == 0x000028, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_Array_Get_Item) == 0x000030, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, K2Node_DynamicCast_AsCharacter) == 0x000038, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::K2Node_DynamicCast_AsCharacter' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, K2Node_DynamicCast_bSuccess) == 0x000040, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_Array_Length_ReturnValue) == 0x000044, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, K2Node_DynamicCast_AsI_Pawn_Actions) == 0x000048, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::K2Node_DynamicCast_AsI_Pawn_Actions' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, K2Node_DynamicCast_bSuccess_1) == 0x000058, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_Less_IntInt_ReturnValue) == 0x000059, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_FindOverlappingActorOnActivation, CallFunc_CharacterdNeedsAmmo_bNeedsAmmo) == 0x00005A, "Member 'BP_SmallAmmoBox_C_FindOverlappingActorOnActivation::CallFunc_CharacterdNeedsAmmo_bNeedsAmmo' has a wrong offset!");

// Function BP_SmallAmmoBox.BP_SmallAmmoBox_C.Use
// 0x0048 (0x0048 - 0x0000)
struct BP_SmallAmmoBox_C_Use final
{
public:
	class AActor*                                 Actor;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ACharacter*                             K2Node_DynamicCast_AsCharacter;                    // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IIPawnActions_C>       K2Node_DynamicCast_AsI_Pawn_Actions;               // 0x0018(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IIPawnActions_C>       K2Node_DynamicCast_AsI_Pawn_Actions_1;             // 0x0030(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_DynamicCast_bSuccess_2;                     // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_CharacterdNeedsAmmo_bNeedsAmmo;           // 0x0041(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_SmallAmmoBox_C_Use) == 0x000008, "Wrong alignment on BP_SmallAmmoBox_C_Use");
static_assert(sizeof(BP_SmallAmmoBox_C_Use) == 0x000048, "Wrong size on BP_SmallAmmoBox_C_Use");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, Actor) == 0x000000, "Member 'BP_SmallAmmoBox_C_Use::Actor' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, K2Node_DynamicCast_AsCharacter) == 0x000008, "Member 'BP_SmallAmmoBox_C_Use::K2Node_DynamicCast_AsCharacter' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, K2Node_DynamicCast_bSuccess) == 0x000010, "Member 'BP_SmallAmmoBox_C_Use::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, K2Node_DynamicCast_AsI_Pawn_Actions) == 0x000018, "Member 'BP_SmallAmmoBox_C_Use::K2Node_DynamicCast_AsI_Pawn_Actions' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, K2Node_DynamicCast_bSuccess_1) == 0x000028, "Member 'BP_SmallAmmoBox_C_Use::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, K2Node_DynamicCast_AsI_Pawn_Actions_1) == 0x000030, "Member 'BP_SmallAmmoBox_C_Use::K2Node_DynamicCast_AsI_Pawn_Actions_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, K2Node_DynamicCast_bSuccess_2) == 0x000040, "Member 'BP_SmallAmmoBox_C_Use::K2Node_DynamicCast_bSuccess_2' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_Use, CallFunc_CharacterdNeedsAmmo_bNeedsAmmo) == 0x000041, "Member 'BP_SmallAmmoBox_C_Use::CallFunc_CharacterdNeedsAmmo_bNeedsAmmo' has a wrong offset!");

// Function BP_SmallAmmoBox.BP_SmallAmmoBox_C.AddInitialImpulse
// 0x0040 (0x0040 - 0x0000)
struct BP_SmallAmmoBox_C_AddInitialImpulse final
{
public:
	struct FVector                                CallFunc_GetActorForwardVector_ReturnValue;        // 0x0000(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ACharacter*                             K2Node_DynamicCast_AsCharacter;                    // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_Multiply_VectorFloat_ReturnValue;         // 0x001C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Multiply_VectorFloat_ReturnValue_1;       // 0x0028(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Add_VectorVector_ReturnValue;             // 0x0034(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_SmallAmmoBox_C_AddInitialImpulse) == 0x000008, "Wrong alignment on BP_SmallAmmoBox_C_AddInitialImpulse");
static_assert(sizeof(BP_SmallAmmoBox_C_AddInitialImpulse) == 0x000040, "Wrong size on BP_SmallAmmoBox_C_AddInitialImpulse");
static_assert(offsetof(BP_SmallAmmoBox_C_AddInitialImpulse, CallFunc_GetActorForwardVector_ReturnValue) == 0x000000, "Member 'BP_SmallAmmoBox_C_AddInitialImpulse::CallFunc_GetActorForwardVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_AddInitialImpulse, K2Node_DynamicCast_AsCharacter) == 0x000010, "Member 'BP_SmallAmmoBox_C_AddInitialImpulse::K2Node_DynamicCast_AsCharacter' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_AddInitialImpulse, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'BP_SmallAmmoBox_C_AddInitialImpulse::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_AddInitialImpulse, CallFunc_Multiply_VectorFloat_ReturnValue) == 0x00001C, "Member 'BP_SmallAmmoBox_C_AddInitialImpulse::CallFunc_Multiply_VectorFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_AddInitialImpulse, CallFunc_Multiply_VectorFloat_ReturnValue_1) == 0x000028, "Member 'BP_SmallAmmoBox_C_AddInitialImpulse::CallFunc_Multiply_VectorFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_AddInitialImpulse, CallFunc_Add_VectorVector_ReturnValue) == 0x000034, "Member 'BP_SmallAmmoBox_C_AddInitialImpulse::CallFunc_Add_VectorVector_ReturnValue' has a wrong offset!");

// Function BP_SmallAmmoBox.BP_SmallAmmoBox_C.BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature
// 0x00A8 (0x00A8 - 0x0000)
struct BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature final
{
public:
	class UPrimitiveComponent*                    OverlappedComponent;                               // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 OtherActor;                                        // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPrimitiveComponent*                    OtherComp;                                         // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         OtherBodyIndex;                                    // 0x0018(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bFromSweep;                                        // 0x001C(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1D[0x3];                                       // 0x001D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FHitResult                             SweepResult;                                       // 0x0020(0x0088)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)
};
static_assert(alignof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature) == 0x000008, "Wrong alignment on BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature");
static_assert(sizeof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature) == 0x0000A8, "Wrong size on BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature");
static_assert(offsetof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature, OverlappedComponent) == 0x000000, "Member 'BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature::OverlappedComponent' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature, OtherActor) == 0x000008, "Member 'BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature::OtherActor' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature, OtherComp) == 0x000010, "Member 'BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature::OtherComp' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature, OtherBodyIndex) == 0x000018, "Member 'BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature::OtherBodyIndex' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature, bFromSweep) == 0x00001C, "Member 'BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature::bFromSweep' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature, SweepResult) == 0x000020, "Member 'BP_SmallAmmoBox_C_BndEvt__InfluenceSphere_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature::SweepResult' has a wrong offset!");

// Function BP_SmallAmmoBox.BP_SmallAmmoBox_C.ExecuteUbergraph_BP_SmallAmmoBox
// 0x0130 (0x0130 - 0x0000)
struct BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IIPlayerState_C>       K2Node_DynamicCast_AsI_Player_State;               // 0x0018(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0030(0x0008)(NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetPlayerTeamFromPlayerState_Team;        // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_HasAuthority_ReturnValue;                 // 0x003C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3D[0x3];                                       // 0x003D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UPrimitiveComponent*                    K2Node_ComponentBoundEvent_OverlappedComponent;    // 0x0040(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 K2Node_ComponentBoundEvent_OtherActor;             // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPrimitiveComponent*                    K2Node_ComponentBoundEvent_OtherComp;              // 0x0050(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_ComponentBoundEvent_OtherBodyIndex;         // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ComponentBoundEvent_bFromSweep;             // 0x005C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5D[0x3];                                       // 0x005D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FHitResult                             K2Node_ComponentBoundEvent_SweepResult;            // 0x0060(0x0088)(ConstParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)
	bool                                          CallFunc_HasAuthority_ReturnValue_1;               // 0x00E8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E9[0x7];                                       // 0x00E9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APawn*                                  K2Node_DynamicCast_AsPawn;                         // 0x00F0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x00F8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_NotEqual_ObjectObject_ReturnValue;        // 0x00F9(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_FA[0x2];                                       // 0x00FA(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetPlayerTeamFromPlayerState_Team_1;      // 0x00FC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_IntInt_ReturnValue;            // 0x0100(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0101(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_102[0x2];                                      // 0x0102(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_GetComponentVelocity_ReturnValue;         // 0x0104(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_VectorVector_ReturnValue;        // 0x0110(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_HasAuthority_ReturnValue_2;               // 0x0111(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_112[0x2];                                      // 0x0112(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_1;            // 0x0114(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_124[0x4];                                      // 0x0124(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue_1;        // 0x0128(0x0008)(NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox) == 0x000008, "Wrong alignment on BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox");
static_assert(sizeof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox) == 0x000130, "Wrong size on BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, EntryPoint) == 0x000000, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::EntryPoint' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_DynamicCast_AsI_Player_State) == 0x000018, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_DynamicCast_AsI_Player_State' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000030, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_GetPlayerTeamFromPlayerState_Team) == 0x000038, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_GetPlayerTeamFromPlayerState_Team' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_HasAuthority_ReturnValue) == 0x00003C, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_HasAuthority_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_ComponentBoundEvent_OverlappedComponent) == 0x000040, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_ComponentBoundEvent_OverlappedComponent' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_ComponentBoundEvent_OtherActor) == 0x000048, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_ComponentBoundEvent_OtherActor' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_ComponentBoundEvent_OtherComp) == 0x000050, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_ComponentBoundEvent_OtherComp' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_ComponentBoundEvent_OtherBodyIndex) == 0x000058, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_ComponentBoundEvent_OtherBodyIndex' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_ComponentBoundEvent_bFromSweep) == 0x00005C, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_ComponentBoundEvent_bFromSweep' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_ComponentBoundEvent_SweepResult) == 0x000060, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_ComponentBoundEvent_SweepResult' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_HasAuthority_ReturnValue_1) == 0x0000E8, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_HasAuthority_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_DynamicCast_AsPawn) == 0x0000F0, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_DynamicCast_AsPawn' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_DynamicCast_bSuccess_1) == 0x0000F8, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_NotEqual_ObjectObject_ReturnValue) == 0x0000F9, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_NotEqual_ObjectObject_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_GetPlayerTeamFromPlayerState_Team_1) == 0x0000FC, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_GetPlayerTeamFromPlayerState_Team_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_EqualEqual_IntInt_ReturnValue) == 0x000100, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_EqualEqual_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_BooleanAND_ReturnValue) == 0x000101, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_GetComponentVelocity_ReturnValue) == 0x000104, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_GetComponentVelocity_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_NotEqual_VectorVector_ReturnValue) == 0x000110, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_NotEqual_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_HasAuthority_ReturnValue_2) == 0x000111, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_HasAuthority_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, K2Node_CreateDelegate_OutputDelegate_1) == 0x000114, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox, CallFunc_K2_SetTimerDelegate_ReturnValue_1) == 0x000128, "Member 'BP_SmallAmmoBox_C_ExecuteUbergraph_BP_SmallAmmoBox::CallFunc_K2_SetTimerDelegate_ReturnValue_1' has a wrong offset!");

}

