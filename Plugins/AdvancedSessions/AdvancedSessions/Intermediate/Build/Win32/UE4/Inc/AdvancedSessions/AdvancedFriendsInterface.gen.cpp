// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSessions/Classes/AdvancedFriendsInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedFriendsInterface() {}
// Cross Module References
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedFriendsInterface_NoRegister();
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedFriendsInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_AdvancedSessions();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPUniqueNetId();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBPLoginStatus();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted();
	ONLINESUBSYSTEMUTILS_API UScriptStruct* Z_Construct_UScriptStruct_FBlueprintSessionResult();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived();
// End Cross Module References
	void IAdvancedFriendsInterface::OnPlayerLoginChanged(int32 PlayerNum)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnPlayerLoginChanged instead.");
	}
	void IAdvancedFriendsInterface::OnPlayerLoginStatusChanged(EBPLoginStatus PreviousStatus, EBPLoginStatus NewStatus, FBPUniqueNetId PlayerUniqueNetID)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnPlayerLoginStatusChanged instead.");
	}
	void IAdvancedFriendsInterface::OnPlayerVoiceStateChanged(FBPUniqueNetId PlayerId, bool bIsTalking)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnPlayerVoiceStateChanged instead.");
	}
	void IAdvancedFriendsInterface::OnSessionInviteAccepted(FBPUniqueNetId PersonInvited, FBlueprintSessionResult const& SearchResult)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnSessionInviteAccepted instead.");
	}
	void IAdvancedFriendsInterface::OnSessionInviteReceived(FBPUniqueNetId PersonInviting, FBlueprintSessionResult const& SearchResult)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnSessionInviteReceived instead.");
	}
	void UAdvancedFriendsInterface::StaticRegisterNativesUAdvancedFriendsInterface()
	{
	}
	struct Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics
	{
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_PlayerNum;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::NewProp_PlayerNum = { UE4CodeGen_Private::EPropertyClass::Int, "PlayerNum", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnPlayerLoginChanged_Parms, PlayerNum), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::NewProp_PlayerNum,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnPlayerLoginChanged" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsInterface.h" },
		{ "ToolTip", "Called when the designated LocalUser has changed login state" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsInterface, "OnPlayerLoginChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(AdvancedFriendsInterface_eventOnPlayerLoginChanged_Parms), Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerUniqueNetID;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_NewStatus;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewStatus_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_PreviousStatus;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PreviousStatus_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_PlayerUniqueNetID = { UE4CodeGen_Private::EPropertyClass::Struct, "PlayerUniqueNetID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnPlayerLoginStatusChanged_Parms, PlayerUniqueNetID), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_NewStatus = { UE4CodeGen_Private::EPropertyClass::Enum, "NewStatus", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnPlayerLoginStatusChanged_Parms, NewStatus), Z_Construct_UEnum_AdvancedSessions_EBPLoginStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_NewStatus_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_PreviousStatus = { UE4CodeGen_Private::EPropertyClass::Enum, "PreviousStatus", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnPlayerLoginStatusChanged_Parms, PreviousStatus), Z_Construct_UEnum_AdvancedSessions_EBPLoginStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_PreviousStatus_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_PlayerUniqueNetID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_NewStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_NewStatus_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_PreviousStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::NewProp_PreviousStatus_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnPlayerLoginStatusChanged" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsInterface.h" },
		{ "ToolTip", "Called when the designated LocalUser has changed login state" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsInterface, "OnPlayerLoginStatusChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(AdvancedFriendsInterface_eventOnPlayerLoginStatusChanged_Parms), Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics
	{
		static void NewProp_bIsTalking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsTalking;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::NewProp_bIsTalking_SetBit(void* Obj)
	{
		((AdvancedFriendsInterface_eventOnPlayerVoiceStateChanged_Parms*)Obj)->bIsTalking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::NewProp_bIsTalking = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsTalking", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedFriendsInterface_eventOnPlayerVoiceStateChanged_Parms), &Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::NewProp_bIsTalking_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::NewProp_PlayerId = { UE4CodeGen_Private::EPropertyClass::Struct, "PlayerId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnPlayerVoiceStateChanged_Parms, PlayerId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::NewProp_bIsTalking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::NewProp_PlayerId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnPlayerVoiceStateChanged" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsInterface.h" },
		{ "ToolTip", "Called when the designated LocalUser has accepted a session invite, use JoinSession on result to connect" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsInterface, "OnPlayerVoiceStateChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(AdvancedFriendsInterface_eventOnPlayerVoiceStateChanged_Parms), Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SearchResult;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PersonInvited;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_SearchResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_SearchResult = { UE4CodeGen_Private::EPropertyClass::Struct, "SearchResult", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnSessionInviteAccepted_Parms, SearchResult), Z_Construct_UScriptStruct_FBlueprintSessionResult, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_SearchResult_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_SearchResult_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_PersonInvited = { UE4CodeGen_Private::EPropertyClass::Struct, "PersonInvited", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnSessionInviteAccepted_Parms, PersonInvited), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_SearchResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::NewProp_PersonInvited,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnSessionInviteAccepted" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsInterface.h" },
		{ "ToolTip", "Called when the designated LocalUser has accepted a session invite, use JoinSession on result to connect" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsInterface, "OnSessionInviteAccepted", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420800, sizeof(AdvancedFriendsInterface_eventOnSessionInviteAccepted_Parms), Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SearchResult;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PersonInviting;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_SearchResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_SearchResult = { UE4CodeGen_Private::EPropertyClass::Struct, "SearchResult", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnSessionInviteReceived_Parms, SearchResult), Z_Construct_UScriptStruct_FBlueprintSessionResult, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_SearchResult_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_SearchResult_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_PersonInviting = { UE4CodeGen_Private::EPropertyClass::Struct, "PersonInviting", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsInterface_eventOnSessionInviteReceived_Parms, PersonInviting), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_SearchResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::NewProp_PersonInviting,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnSessionInviteReceived" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsInterface.h" },
		{ "ToolTip", "Called when the designated LocalUser has accepted a session invite, use JoinSession on result to connect" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsInterface, "OnSessionInviteReceived", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420800, sizeof(AdvancedFriendsInterface_eventOnSessionInviteReceived_Parms), Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdvancedFriendsInterface_NoRegister()
	{
		return UAdvancedFriendsInterface::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedFriendsInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedFriendsInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedFriendsInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginChanged, "OnPlayerLoginChanged" }, // 3539247751
		{ &Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged, "OnPlayerLoginStatusChanged" }, // 2311601866
		{ &Z_Construct_UFunction_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged, "OnPlayerVoiceStateChanged" }, // 2403773254
		{ &Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteAccepted, "OnSessionInviteAccepted" }, // 4023503297
		{ &Z_Construct_UFunction_UAdvancedFriendsInterface_OnSessionInviteReceived, "OnSessionInviteReceived" }, // 648340131
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedFriendsInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/AdvancedFriendsInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedFriendsInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IAdvancedFriendsInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedFriendsInterface_Statics::ClassParams = {
		&UAdvancedFriendsInterface::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000840A1u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdvancedFriendsInterface_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdvancedFriendsInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdvancedFriendsInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdvancedFriendsInterface_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdvancedFriendsInterface, 704613518);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdvancedFriendsInterface(Z_Construct_UClass_UAdvancedFriendsInterface, &UAdvancedFriendsInterface::StaticClass, TEXT("/Script/AdvancedSessions"), TEXT("UAdvancedFriendsInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedFriendsInterface);
	static FName NAME_UAdvancedFriendsInterface_OnPlayerLoginChanged = FName(TEXT("OnPlayerLoginChanged"));
	void IAdvancedFriendsInterface::Execute_OnPlayerLoginChanged(UObject* O, int32 PlayerNum)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UAdvancedFriendsInterface::StaticClass()));
		AdvancedFriendsInterface_eventOnPlayerLoginChanged_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UAdvancedFriendsInterface_OnPlayerLoginChanged);
		if (Func)
		{
			Parms.PlayerNum=PlayerNum;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged = FName(TEXT("OnPlayerLoginStatusChanged"));
	void IAdvancedFriendsInterface::Execute_OnPlayerLoginStatusChanged(UObject* O, EBPLoginStatus PreviousStatus, EBPLoginStatus NewStatus, FBPUniqueNetId PlayerUniqueNetID)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UAdvancedFriendsInterface::StaticClass()));
		AdvancedFriendsInterface_eventOnPlayerLoginStatusChanged_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UAdvancedFriendsInterface_OnPlayerLoginStatusChanged);
		if (Func)
		{
			Parms.PreviousStatus=PreviousStatus;
			Parms.NewStatus=NewStatus;
			Parms.PlayerUniqueNetID=PlayerUniqueNetID;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged = FName(TEXT("OnPlayerVoiceStateChanged"));
	void IAdvancedFriendsInterface::Execute_OnPlayerVoiceStateChanged(UObject* O, FBPUniqueNetId PlayerId, bool bIsTalking)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UAdvancedFriendsInterface::StaticClass()));
		AdvancedFriendsInterface_eventOnPlayerVoiceStateChanged_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UAdvancedFriendsInterface_OnPlayerVoiceStateChanged);
		if (Func)
		{
			Parms.PlayerId=PlayerId;
			Parms.bIsTalking=bIsTalking;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UAdvancedFriendsInterface_OnSessionInviteAccepted = FName(TEXT("OnSessionInviteAccepted"));
	void IAdvancedFriendsInterface::Execute_OnSessionInviteAccepted(UObject* O, FBPUniqueNetId PersonInvited, FBlueprintSessionResult const& SearchResult)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UAdvancedFriendsInterface::StaticClass()));
		AdvancedFriendsInterface_eventOnSessionInviteAccepted_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UAdvancedFriendsInterface_OnSessionInviteAccepted);
		if (Func)
		{
			Parms.PersonInvited=PersonInvited;
			Parms.SearchResult=SearchResult;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UAdvancedFriendsInterface_OnSessionInviteReceived = FName(TEXT("OnSessionInviteReceived"));
	void IAdvancedFriendsInterface::Execute_OnSessionInviteReceived(UObject* O, FBPUniqueNetId PersonInviting, FBlueprintSessionResult const& SearchResult)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UAdvancedFriendsInterface::StaticClass()));
		AdvancedFriendsInterface_eventOnSessionInviteReceived_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UAdvancedFriendsInterface_OnSessionInviteReceived);
		if (Func)
		{
			Parms.PersonInviting=PersonInviting;
			Parms.SearchResult=SearchResult;
			O->ProcessEvent(Func, &Parms);
		}
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
