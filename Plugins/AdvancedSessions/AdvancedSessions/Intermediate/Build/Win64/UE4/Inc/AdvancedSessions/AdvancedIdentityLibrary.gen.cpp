// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSessions/Classes/AdvancedIdentityLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedIdentityLibrary() {}
// Cross Module References
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedIdentityLibrary_NoRegister();
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedIdentityLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AdvancedSessions();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPUserOnlineAccount();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBPLoginStatus();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPUniqueNetId();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute();
// End Cross Module References
	void UAdvancedIdentityLibrary::StaticRegisterNativesUAdvancedIdentityLibrary()
	{
		UClass* Class = UAdvancedIdentityLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAllUserAccounts", &UAdvancedIdentityLibrary::execGetAllUserAccounts },
			{ "GetLoginStatus", &UAdvancedIdentityLibrary::execGetLoginStatus },
			{ "GetPlayerAuthToken", &UAdvancedIdentityLibrary::execGetPlayerAuthToken },
			{ "GetPlayerNickname", &UAdvancedIdentityLibrary::execGetPlayerNickname },
			{ "GetUserAccount", &UAdvancedIdentityLibrary::execGetUserAccount },
			{ "GetUserAccountAccessToken", &UAdvancedIdentityLibrary::execGetUserAccountAccessToken },
			{ "GetUserAccountAttribute", &UAdvancedIdentityLibrary::execGetUserAccountAttribute },
			{ "GetUserAccountAuthAttribute", &UAdvancedIdentityLibrary::execGetUserAccountAuthAttribute },
			{ "GetUserAccountDisplayName", &UAdvancedIdentityLibrary::execGetUserAccountDisplayName },
			{ "GetUserAccountRealName", &UAdvancedIdentityLibrary::execGetUserAccountRealName },
			{ "GetUserID", &UAdvancedIdentityLibrary::execGetUserID },
			{ "SetUserAccountAttribute", &UAdvancedIdentityLibrary::execSetUserAccountAttribute },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics
	{
		struct AdvancedIdentityLibrary_eventGetAllUserAccounts_Parms
		{
			TArray<FBPUserOnlineAccount> AccountInfos;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AccountInfos;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfos_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetAllUserAccounts_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_AccountInfos = { UE4CodeGen_Private::EPropertyClass::Array, "AccountInfos", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetAllUserAccounts_Parms, AccountInfos), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_AccountInfos_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfos", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_AccountInfos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::NewProp_AccountInfos_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get all known users accounts" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetAllUserAccounts", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventGetAllUserAccounts_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics
	{
		struct AdvancedIdentityLibrary_eventGetLoginStatus_Parms
		{
			FBPUniqueNetId UniqueNetID;
			EBPLoginStatus LoginStatus;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_LoginStatus;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_LoginStatus_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UniqueNetID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UniqueNetID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetLoginStatus_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_LoginStatus = { UE4CodeGen_Private::EPropertyClass::Enum, "LoginStatus", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetLoginStatus_Parms, LoginStatus), Z_Construct_UEnum_AdvancedSessions_EBPLoginStatus, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_LoginStatus_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_UniqueNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_UniqueNetID = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetLoginStatus_Parms, UniqueNetID), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_UniqueNetID_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_UniqueNetID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_LoginStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_LoginStatus_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::NewProp_UniqueNetID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get the login status of a local player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetLoginStatus", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventGetLoginStatus_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics
	{
		struct AdvancedIdentityLibrary_eventGetPlayerAuthToken_Parms
		{
			APlayerController* PlayerController;
			FString AuthToken;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AuthToken;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetPlayerAuthToken_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_AuthToken = { UE4CodeGen_Private::EPropertyClass::Str, "AuthToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetPlayerAuthToken_Parms, AuthToken), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetPlayerAuthToken_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_AuthToken,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get the auth token for a local player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetPlayerAuthToken", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventGetPlayerAuthToken_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics
	{
		struct AdvancedIdentityLibrary_eventGetPlayerNickname_Parms
		{
			FBPUniqueNetId UniqueNetID;
			FString PlayerNickname;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PlayerNickname;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UniqueNetID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UniqueNetID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_PlayerNickname = { UE4CodeGen_Private::EPropertyClass::Str, "PlayerNickname", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetPlayerNickname_Parms, PlayerNickname), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_UniqueNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_UniqueNetID = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetPlayerNickname_Parms, UniqueNetID), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_UniqueNetID_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_UniqueNetID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_PlayerNickname,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::NewProp_UniqueNetID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get a players nickname" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetPlayerNickname", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(AdvancedIdentityLibrary_eventGetPlayerNickname_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserAccount_Parms
		{
			FBPUniqueNetId UniqueNetId;
			FBPUserOnlineAccount AccountInfo;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UniqueNetId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UniqueNetId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccount_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccount_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccount_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_AccountInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get a users account" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserAccount", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventGetUserAccount_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserAccountAccessToken_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FString AccessToken;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AccessToken;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccessToken = { UE4CodeGen_Private::EPropertyClass::Str, "AccessToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAccessToken_Parms, AccessToken), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAccessToken_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccessToken,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get a user account access token" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserAccountAccessToken", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(AdvancedIdentityLibrary_eventGetUserAccountAccessToken_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserAccountAttribute_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FString AttributeName;
			FString AttributeValue;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AttributeValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AttributeName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAttribute_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeValue = { UE4CodeGen_Private::EPropertyClass::Str, "AttributeValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAttribute_Parms, AttributeValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeName = { UE4CodeGen_Private::EPropertyClass::Str, "AttributeName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAttribute_Parms, AttributeName), METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAttribute_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AttributeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get user account attribute (depends on subsystem)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserAccountAttribute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventGetUserAccountAttribute_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserAccountAuthAttribute_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FString AttributeName;
			FString AuthAttribute;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AuthAttribute;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AttributeName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAuthAttribute_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AuthAttribute = { UE4CodeGen_Private::EPropertyClass::Str, "AuthAttribute", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAuthAttribute_Parms, AuthAttribute), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AttributeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AttributeName = { UE4CodeGen_Private::EPropertyClass::Str, "AttributeName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAuthAttribute_Parms, AttributeName), METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AttributeName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AttributeName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountAuthAttribute_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AuthAttribute,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AttributeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get a user account Auth attribute (depends on subsystem)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserAccountAuthAttribute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventGetUserAccountAuthAttribute_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserAccountDisplayName_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FString DisplayName;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DisplayName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_DisplayName = { UE4CodeGen_Private::EPropertyClass::Str, "DisplayName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountDisplayName_Parms, DisplayName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountDisplayName_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_DisplayName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get user account display name if possible" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserAccountDisplayName", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(AdvancedIdentityLibrary_eventGetUserAccountDisplayName_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserAccountRealName_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FString UserName;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_UserName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_UserName = { UE4CodeGen_Private::EPropertyClass::Str, "UserName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountRealName_Parms, UserName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserAccountRealName_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_UserName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get user accounts real name if possible" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserAccountRealName", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(AdvancedIdentityLibrary_eventGetUserAccountRealName_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics
	{
		struct AdvancedIdentityLibrary_eventGetUserID_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FBPUniqueNetId UniqueNetID;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UniqueNetID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_UniqueNetID = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserID_Parms, UniqueNetID), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventGetUserID_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_UniqueNetID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Get user ID" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "GetUserID", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(AdvancedIdentityLibrary_eventGetUserID_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics
	{
		struct AdvancedIdentityLibrary_eventSetUserAccountAttribute_Parms
		{
			FBPUserOnlineAccount AccountInfo;
			FString AttributeName;
			FString NewAttributeValue;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewAttributeValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NewAttributeValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AttributeName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AccountInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AccountInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventSetUserAccountAttribute_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_NewAttributeValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_NewAttributeValue = { UE4CodeGen_Private::EPropertyClass::Str, "NewAttributeValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventSetUserAccountAttribute_Parms, NewAttributeValue), METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_NewAttributeValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_NewAttributeValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AttributeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AttributeName = { UE4CodeGen_Private::EPropertyClass::Str, "AttributeName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventSetUserAccountAttribute_Parms, AttributeName), METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AttributeName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AttributeName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AccountInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AccountInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "AccountInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedIdentityLibrary_eventSetUserAccountAttribute_Parms, AccountInfo), Z_Construct_UScriptStruct_FBPUserOnlineAccount, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AccountInfo_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AccountInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_NewAttributeValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AttributeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::NewProp_AccountInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedIdentity|UserAccount" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
		{ "ToolTip", "Set a user account attribute (depends on subsystem)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedIdentityLibrary, "SetUserAccountAttribute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedIdentityLibrary_eventSetUserAccountAttribute_Parms), Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdvancedIdentityLibrary_NoRegister()
	{
		return UAdvancedIdentityLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedIdentityLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetAllUserAccounts, "GetAllUserAccounts" }, // 651724239
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetLoginStatus, "GetLoginStatus" }, // 3305050891
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerAuthToken, "GetPlayerAuthToken" }, // 638082511
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetPlayerNickname, "GetPlayerNickname" }, // 224204333
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccount, "GetUserAccount" }, // 2091486213
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAccessToken, "GetUserAccountAccessToken" }, // 2565361562
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAttribute, "GetUserAccountAttribute" }, // 1904408623
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountAuthAttribute, "GetUserAccountAuthAttribute" }, // 3127821637
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountDisplayName, "GetUserAccountDisplayName" }, // 1846958526
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserAccountRealName, "GetUserAccountRealName" }, // 501440391
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_GetUserID, "GetUserID" }, // 3264035776
		{ &Z_Construct_UFunction_UAdvancedIdentityLibrary_SetUserAccountAttribute, "SetUserAccountAttribute" }, // 1058042700
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AdvancedIdentityLibrary.h" },
		{ "ModuleRelativePath", "Classes/AdvancedIdentityLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdvancedIdentityLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::ClassParams = {
		&UAdvancedIdentityLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdvancedIdentityLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdvancedIdentityLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdvancedIdentityLibrary, 2651398949);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdvancedIdentityLibrary(Z_Construct_UClass_UAdvancedIdentityLibrary, &UAdvancedIdentityLibrary::StaticClass, TEXT("/Script/AdvancedSessions"), TEXT("UAdvancedIdentityLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedIdentityLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
