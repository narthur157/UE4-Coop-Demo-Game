// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSessions/Classes/AdvancedExternalUILibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedExternalUILibrary() {}
// Cross Module References
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedExternalUILibrary_NoRegister();
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedExternalUILibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AdvancedSessions();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPUniqueNetId();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI();
// End Cross Module References
	void UAdvancedExternalUILibrary::StaticRegisterNativesUAdvancedExternalUILibrary()
	{
		UClass* Class = UAdvancedExternalUILibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseWebURLUI", &UAdvancedExternalUILibrary::execCloseWebURLUI },
			{ "ShowAccountUpgradeUI", &UAdvancedExternalUILibrary::execShowAccountUpgradeUI },
			{ "ShowFriendsUI", &UAdvancedExternalUILibrary::execShowFriendsUI },
			{ "ShowInviteUI", &UAdvancedExternalUILibrary::execShowInviteUI },
			{ "ShowLeaderBoardUI", &UAdvancedExternalUILibrary::execShowLeaderBoardUI },
			{ "ShowProfileUI", &UAdvancedExternalUILibrary::execShowProfileUI },
			{ "ShowWebURLUI", &UAdvancedExternalUILibrary::execShowWebURLUI },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedExternalUI" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that shows a web URL" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "CloseWebURLUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics
	{
		struct AdvancedExternalUILibrary_eventShowAccountUpgradeUI_Parms
		{
			FBPUniqueNetId PlayerRequestingAccountUpgradeUI;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerRequestingAccountUpgradeUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerRequestingAccountUpgradeUI;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowAccountUpgradeUI_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_PlayerRequestingAccountUpgradeUI_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_PlayerRequestingAccountUpgradeUI = { UE4CodeGen_Private::EPropertyClass::Struct, "PlayerRequestingAccountUpgradeUI", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowAccountUpgradeUI_Parms, PlayerRequestingAccountUpgradeUI), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_PlayerRequestingAccountUpgradeUI_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_PlayerRequestingAccountUpgradeUI_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::NewProp_PlayerRequestingAccountUpgradeUI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedExternalUI" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that shows the account upgrade UI (doesn't work with steam)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "ShowAccountUpgradeUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedExternalUILibrary_eventShowAccountUpgradeUI_Parms), Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics
	{
		struct AdvancedExternalUILibrary_eventShowFriendsUI_Parms
		{
			APlayerController* PlayerController;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowFriendsUI_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowFriendsUI_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedExternalUI" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that handles the Friends list" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "ShowFriendsUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedExternalUILibrary_eventShowFriendsUI_Parms), Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics
	{
		struct AdvancedExternalUILibrary_eventShowInviteUI_Parms
		{
			APlayerController* PlayerController;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowInviteUI_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowInviteUI_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedExternalUI" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that handles inviting people to your game" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "ShowInviteUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedExternalUILibrary_eventShowInviteUI_Parms), Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics
	{
		struct AdvancedExternalUILibrary_eventShowLeaderBoardUI_Parms
		{
			FString LeaderboardName;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowLeaderBoardUI_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::NewProp_LeaderboardName = { UE4CodeGen_Private::EPropertyClass::Str, "LeaderboardName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowLeaderBoardUI_Parms, LeaderboardName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::NewProp_LeaderboardName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedExternalUI" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that shows the leaderboard (doesn't work with steam)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "ShowLeaderBoardUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedExternalUILibrary_eventShowLeaderBoardUI_Parms), Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics
	{
		struct AdvancedExternalUILibrary_eventShowProfileUI_Parms
		{
			FBPUniqueNetId PlayerViewingProfile;
			FBPUniqueNetId PlayerToViewProfileOf;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerToViewProfileOf_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerToViewProfileOf;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerViewingProfile_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerViewingProfile;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowProfileUI_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerToViewProfileOf_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerToViewProfileOf = { UE4CodeGen_Private::EPropertyClass::Struct, "PlayerToViewProfileOf", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowProfileUI_Parms, PlayerToViewProfileOf), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerToViewProfileOf_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerToViewProfileOf_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerViewingProfile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerViewingProfile = { UE4CodeGen_Private::EPropertyClass::Struct, "PlayerViewingProfile", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowProfileUI_Parms, PlayerViewingProfile), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerViewingProfile_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerViewingProfile_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerToViewProfileOf,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::NewProp_PlayerViewingProfile,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedExternalUI" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that shows the profile of a uniquenetid" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "ShowProfileUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedExternalUILibrary_eventShowProfileUI_Parms), Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics
	{
		struct AdvancedExternalUILibrary_eventShowWebURLUI_Parms
		{
			FString URLToShow;
			EBlueprintResultSwitch Result;
			TArray<FString> AllowedDomains;
			bool bEmbedded;
			bool bShowBackground;
			bool bShowCloseButton;
			int32 OffsetX;
			int32 OffsetY;
			int32 SizeX;
			int32 SizeY;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SizeY;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SizeX;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OffsetY;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OffsetX;
		static void NewProp_bShowCloseButton_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowCloseButton;
		static void NewProp_bShowBackground_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowBackground;
		static void NewProp_bEmbedded_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEmbedded;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AllowedDomains;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AllowedDomains_Inner;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_URLToShow;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_SizeY = { UE4CodeGen_Private::EPropertyClass::Int, "SizeY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, SizeY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_SizeX = { UE4CodeGen_Private::EPropertyClass::Int, "SizeX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, SizeX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_OffsetY = { UE4CodeGen_Private::EPropertyClass::Int, "OffsetY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, OffsetY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_OffsetX = { UE4CodeGen_Private::EPropertyClass::Int, "OffsetX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, OffsetX), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowCloseButton_SetBit(void* Obj)
	{
		((AdvancedExternalUILibrary_eventShowWebURLUI_Parms*)Obj)->bShowCloseButton = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowCloseButton = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowCloseButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedExternalUILibrary_eventShowWebURLUI_Parms), &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowCloseButton_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowBackground_SetBit(void* Obj)
	{
		((AdvancedExternalUILibrary_eventShowWebURLUI_Parms*)Obj)->bShowBackground = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowBackground = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowBackground", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedExternalUILibrary_eventShowWebURLUI_Parms), &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowBackground_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bEmbedded_SetBit(void* Obj)
	{
		((AdvancedExternalUILibrary_eventShowWebURLUI_Parms*)Obj)->bEmbedded = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bEmbedded = { UE4CodeGen_Private::EPropertyClass::Bool, "bEmbedded", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedExternalUILibrary_eventShowWebURLUI_Parms), &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bEmbedded_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_AllowedDomains = { UE4CodeGen_Private::EPropertyClass::Array, "AllowedDomains", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, AllowedDomains), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_AllowedDomains_Inner = { UE4CodeGen_Private::EPropertyClass::Str, "AllowedDomains", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_URLToShow = { UE4CodeGen_Private::EPropertyClass::Str, "URLToShow", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedExternalUILibrary_eventShowWebURLUI_Parms, URLToShow), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_SizeY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_SizeX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_OffsetY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_OffsetX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowCloseButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bShowBackground,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_bEmbedded,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_AllowedDomains,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_AllowedDomains_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::NewProp_URLToShow,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "AllowedDomains" },
		{ "Category", "Online|AdvancedExternalUI" },
		{ "CPP_Default_bEmbedded", "false" },
		{ "CPP_Default_bShowBackground", "false" },
		{ "CPP_Default_bShowCloseButton", "false" },
		{ "CPP_Default_OffsetX", "0" },
		{ "CPP_Default_OffsetY", "0" },
		{ "CPP_Default_SizeX", "0" },
		{ "CPP_Default_SizeY", "0" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
		{ "ToolTip", "Show the UI that shows a web URL" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedExternalUILibrary, "ShowWebURLUI", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedExternalUILibrary_eventShowWebURLUI_Parms), Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdvancedExternalUILibrary_NoRegister()
	{
		return UAdvancedExternalUILibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedExternalUILibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_CloseWebURLUI, "CloseWebURLUI" }, // 2891528319
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowAccountUpgradeUI, "ShowAccountUpgradeUI" }, // 186226645
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowFriendsUI, "ShowFriendsUI" }, // 1141716788
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowInviteUI, "ShowInviteUI" }, // 181599712
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowLeaderBoardUI, "ShowLeaderBoardUI" }, // 1766777975
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowProfileUI, "ShowProfileUI" }, // 1258716484
		{ &Z_Construct_UFunction_UAdvancedExternalUILibrary_ShowWebURLUI, "ShowWebURLUI" }, // 1298889381
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AdvancedExternalUILibrary.h" },
		{ "ModuleRelativePath", "Classes/AdvancedExternalUILibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdvancedExternalUILibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::ClassParams = {
		&UAdvancedExternalUILibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdvancedExternalUILibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdvancedExternalUILibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdvancedExternalUILibrary, 1018092336);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdvancedExternalUILibrary(Z_Construct_UClass_UAdvancedExternalUILibrary, &UAdvancedExternalUILibrary::StaticClass, TEXT("/Script/AdvancedSessions"), TEXT("UAdvancedExternalUILibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedExternalUILibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
