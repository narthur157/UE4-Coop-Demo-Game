// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSessions/Classes/AdvancedFriendsLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedFriendsLibrary() {}
// Cross Module References
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedFriendsLibrary_NoRegister();
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedFriendsLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AdvancedSessions();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPFriendInfo();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPUniqueNetId();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPOnlineRecentPlayer();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends();
// End Cross Module References
	void UAdvancedFriendsLibrary::StaticRegisterNativesUAdvancedFriendsLibrary()
	{
		UClass* Class = UAdvancedFriendsLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFriend", &UAdvancedFriendsLibrary::execGetFriend },
			{ "GetStoredFriendsList", &UAdvancedFriendsLibrary::execGetStoredFriendsList },
			{ "GetStoredRecentPlayersList", &UAdvancedFriendsLibrary::execGetStoredRecentPlayersList },
			{ "IsAFriend", &UAdvancedFriendsLibrary::execIsAFriend },
			{ "SendSessionInviteToFriend", &UAdvancedFriendsLibrary::execSendSessionInviteToFriend },
			{ "SendSessionInviteToFriends", &UAdvancedFriendsLibrary::execSendSessionInviteToFriends },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics
	{
		struct AdvancedFriendsLibrary_eventGetFriend_Parms
		{
			APlayerController* PlayerController;
			FBPUniqueNetId FriendUniqueNetId;
			FBPFriendInfo Friend;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Friend;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FriendUniqueNetId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FriendUniqueNetId;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_Friend = { UE4CodeGen_Private::EPropertyClass::Struct, "Friend", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetFriend_Parms, Friend), Z_Construct_UScriptStruct_FBPFriendInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_FriendUniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_FriendUniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "FriendUniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetFriend_Parms, FriendUniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_FriendUniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_FriendUniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetFriend_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_Friend,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_FriendUniqueNetId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|FriendsList" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
		{ "ToolTip", "Get a friend from the previously read/saved friends list (Must Call GetFriends first for this to return anything)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsLibrary, "GetFriend", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedFriendsLibrary_eventGetFriend_Parms), Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics
	{
		struct AdvancedFriendsLibrary_eventGetStoredFriendsList_Parms
		{
			APlayerController* PlayerController;
			TArray<FBPFriendInfo> FriendsList;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FriendsList;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FriendsList_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::NewProp_FriendsList = { UE4CodeGen_Private::EPropertyClass::Array, "FriendsList", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetStoredFriendsList_Parms, FriendsList), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::NewProp_FriendsList_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "FriendsList", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBPFriendInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetStoredFriendsList_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::NewProp_FriendsList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::NewProp_FriendsList_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|FriendsList" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
		{ "ToolTip", "Get the previously read/saved friends list (Must Call GetFriends first for this to return anything)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsLibrary, "GetStoredFriendsList", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedFriendsLibrary_eventGetStoredFriendsList_Parms), Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics
	{
		struct AdvancedFriendsLibrary_eventGetStoredRecentPlayersList_Parms
		{
			FBPUniqueNetId UniqueNetId;
			TArray<FBPOnlineRecentPlayer> PlayersList;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PlayersList;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayersList_Inner;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UniqueNetId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::NewProp_PlayersList = { UE4CodeGen_Private::EPropertyClass::Array, "PlayersList", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetStoredRecentPlayersList_Parms, PlayersList), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::NewProp_PlayersList_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "PlayersList", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBPOnlineRecentPlayer, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventGetStoredRecentPlayersList_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::NewProp_PlayersList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::NewProp_PlayersList_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|RecentPlayersList" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
		{ "ToolTip", "Get the previously read/saved recent players list (Must Call GetRecentPlayers first for this to return anything)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsLibrary, "GetStoredRecentPlayersList", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedFriendsLibrary_eventGetStoredRecentPlayersList_Parms), Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics
	{
		struct AdvancedFriendsLibrary_eventIsAFriend_Parms
		{
			APlayerController* PlayerController;
			FBPUniqueNetId UniqueNetId;
			bool IsFriend;
		};
		static void NewProp_IsFriend_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsFriend;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UniqueNetId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UniqueNetId;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_IsFriend_SetBit(void* Obj)
	{
		((AdvancedFriendsLibrary_eventIsAFriend_Parms*)Obj)->IsFriend = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_IsFriend = { UE4CodeGen_Private::EPropertyClass::Bool, "IsFriend", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedFriendsLibrary_eventIsAFriend_Parms), &Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_IsFriend_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventIsAFriend_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventIsAFriend_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_IsFriend,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_UniqueNetId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|FriendsList" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
		{ "ToolTip", "Check if a UniqueNetId is a friend" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsLibrary, "IsAFriend", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(AdvancedFriendsLibrary_eventIsAFriend_Parms), Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics
	{
		struct AdvancedFriendsLibrary_eventSendSessionInviteToFriend_Parms
		{
			APlayerController* PlayerController;
			FBPUniqueNetId FriendUniqueNetId;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FriendUniqueNetId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FriendUniqueNetId;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventSendSessionInviteToFriend_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_FriendUniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_FriendUniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "FriendUniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventSendSessionInviteToFriend_Parms, FriendUniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_FriendUniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_FriendUniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventSendSessionInviteToFriend_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_FriendUniqueNetId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|FriendsList" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
		{ "ToolTip", "Sends an Invite to the current online session to a friend" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsLibrary, "SendSessionInviteToFriend", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedFriendsLibrary_eventSendSessionInviteToFriend_Parms), Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics
	{
		struct AdvancedFriendsLibrary_eventSendSessionInviteToFriends_Parms
		{
			APlayerController* PlayerController;
			TArray<FBPUniqueNetId> Friends;
			EBlueprintResultSwitch Result;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Friends_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Friends;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Friends_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventSendSessionInviteToFriends_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends = { UE4CodeGen_Private::EPropertyClass::Array, "Friends", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventSendSessionInviteToFriends_Parms, Friends), METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Friends", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedFriendsLibrary_eventSendSessionInviteToFriends_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_Friends_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|FriendsList" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
		{ "ToolTip", "Sends an Invite to the current online session to a list of friends" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedFriendsLibrary, "SendSessionInviteToFriends", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedFriendsLibrary_eventSendSessionInviteToFriends_Parms), Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdvancedFriendsLibrary_NoRegister()
	{
		return UAdvancedFriendsLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedFriendsLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedFriendsLibrary_GetFriend, "GetFriend" }, // 3524327450
		{ &Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredFriendsList, "GetStoredFriendsList" }, // 918275731
		{ &Z_Construct_UFunction_UAdvancedFriendsLibrary_GetStoredRecentPlayersList, "GetStoredRecentPlayersList" }, // 3072126702
		{ &Z_Construct_UFunction_UAdvancedFriendsLibrary_IsAFriend, "IsAFriend" }, // 933613365
		{ &Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriend, "SendSessionInviteToFriend" }, // 824115251
		{ &Z_Construct_UFunction_UAdvancedFriendsLibrary_SendSessionInviteToFriends, "SendSessionInviteToFriends" }, // 229646796
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AdvancedFriendsLibrary.h" },
		{ "ModuleRelativePath", "Classes/AdvancedFriendsLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdvancedFriendsLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::ClassParams = {
		&UAdvancedFriendsLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdvancedFriendsLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdvancedFriendsLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdvancedFriendsLibrary, 618844696);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdvancedFriendsLibrary(Z_Construct_UClass_UAdvancedFriendsLibrary, &UAdvancedFriendsLibrary::StaticClass, TEXT("/Script/AdvancedSessions"), TEXT("UAdvancedFriendsLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedFriendsLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
