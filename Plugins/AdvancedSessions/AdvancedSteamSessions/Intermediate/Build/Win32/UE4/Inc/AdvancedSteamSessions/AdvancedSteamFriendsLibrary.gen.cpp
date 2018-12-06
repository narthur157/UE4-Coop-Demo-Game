// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSteamSessions/Classes/AdvancedSteamFriendsLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedSteamFriendsLibrary() {}
// Cross Module References
	ADVANCEDSTEAMSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSteamSessions_SteamAvatarSize();
	UPackage* Z_Construct_UPackage__Script_AdvancedSteamSessions();
	ADVANCEDSTEAMSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPSteamGroupInfo();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPUniqueNetId();
	ADVANCEDSTEAMSESSIONS_API UClass* Z_Construct_UClass_UAdvancedSteamFriendsLibrary_NoRegister();
	ADVANCEDSTEAMSESSIONS_API UClass* Z_Construct_UClass_UAdvancedSteamFriendsLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBlueprintAsyncResultSwitch();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed();
	ADVANCEDSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo();
// End Cross Module References
	static UEnum* SteamAvatarSize_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AdvancedSteamSessions_SteamAvatarSize, Z_Construct_UPackage__Script_AdvancedSteamSessions(), TEXT("SteamAvatarSize"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_SteamAvatarSize(SteamAvatarSize_StaticEnum, TEXT("/Script/AdvancedSteamSessions"), TEXT("SteamAvatarSize"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AdvancedSteamSessions_SteamAvatarSize_CRC() { return 145321130U; }
	UEnum* Z_Construct_UEnum_AdvancedSteamSessions_SteamAvatarSize()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AdvancedSteamSessions();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("SteamAvatarSize"), 0, Get_Z_Construct_UEnum_AdvancedSteamSessions_SteamAvatarSize_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "SteamAvatarSize::SteamAvatar_Small", (int64)SteamAvatarSize::SteamAvatar_Small },
				{ "SteamAvatarSize::SteamAvatar_Medium", (int64)SteamAvatarSize::SteamAvatar_Medium },
				{ "SteamAvatarSize::SteamAvatar_Large", (int64)SteamAvatarSize::SteamAvatar_Large },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"SteamAvatarSize",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"SteamAvatarSize",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FBPSteamGroupInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADVANCEDSTEAMSESSIONS_API uint32 Get_Z_Construct_UScriptStruct_FBPSteamGroupInfo_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FBPSteamGroupInfo, Z_Construct_UPackage__Script_AdvancedSteamSessions(), TEXT("BPSteamGroupInfo"), sizeof(FBPSteamGroupInfo), Get_Z_Construct_UScriptStruct_FBPSteamGroupInfo_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FBPSteamGroupInfo(FBPSteamGroupInfo::StaticStruct, TEXT("/Script/AdvancedSteamSessions"), TEXT("BPSteamGroupInfo"), false, nullptr, nullptr);
static struct FScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamGroupInfo
{
	FScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamGroupInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("BPSteamGroupInfo")),new UScriptStruct::TCppStructOps<FBPSteamGroupInfo>);
	}
} ScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamGroupInfo;
	struct Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numChatting_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_numChatting;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numInGame_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_numInGame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numOnline_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_numOnline;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GroupTag_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_GroupTag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GroupName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_GroupName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GroupID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GroupID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBPSteamGroupInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numChatting_MetaData[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numChatting = { UE4CodeGen_Private::EPropertyClass::Int, "numChatting", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamGroupInfo, numChatting), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numChatting_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numChatting_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numInGame_MetaData[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numInGame = { UE4CodeGen_Private::EPropertyClass::Int, "numInGame", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamGroupInfo, numInGame), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numInGame_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numInGame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numOnline_MetaData[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numOnline = { UE4CodeGen_Private::EPropertyClass::Int, "numOnline", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamGroupInfo, numOnline), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numOnline_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numOnline_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupTag_MetaData[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupTag = { UE4CodeGen_Private::EPropertyClass::Str, "GroupTag", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamGroupInfo, GroupTag), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupTag_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupTag_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupName_MetaData[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Uint64 representation" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupName = { UE4CodeGen_Private::EPropertyClass::Str, "GroupName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamGroupInfo, GroupName), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupName_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupID_MetaData[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupID = { UE4CodeGen_Private::EPropertyClass::Struct, "GroupID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamGroupInfo, GroupID), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numChatting,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numInGame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_numOnline,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::NewProp_GroupID,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
		nullptr,
		&NewStructOps,
		"BPSteamGroupInfo",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FBPSteamGroupInfo),
		alignof(FBPSteamGroupInfo),
		Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBPSteamGroupInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FBPSteamGroupInfo_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_AdvancedSteamSessions();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("BPSteamGroupInfo"), sizeof(FBPSteamGroupInfo), Get_Z_Construct_UScriptStruct_FBPSteamGroupInfo_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FBPSteamGroupInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FBPSteamGroupInfo_CRC() { return 981231131U; }
	void UAdvancedSteamFriendsLibrary::StaticRegisterNativesUAdvancedSteamFriendsLibrary()
	{
		UClass* Class = UAdvancedSteamFriendsLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateSteamIDFromString", &UAdvancedSteamFriendsLibrary::execCreateSteamIDFromString },
			{ "GetFriendSteamLevel", &UAdvancedSteamFriendsLibrary::execGetFriendSteamLevel },
			{ "GetSteamFriendAvatar", &UAdvancedSteamFriendsLibrary::execGetSteamFriendAvatar },
			{ "GetSteamFriendGamePlayed", &UAdvancedSteamFriendsLibrary::execGetSteamFriendGamePlayed },
			{ "GetSteamGroups", &UAdvancedSteamFriendsLibrary::execGetSteamGroups },
			{ "GetSteamPersonaName", &UAdvancedSteamFriendsLibrary::execGetSteamPersonaName },
			{ "RequestSteamFriendInfo", &UAdvancedSteamFriendsLibrary::execRequestSteamFriendInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventCreateSteamIDFromString_Parms
		{
			FString SteamID64;
			FBPUniqueNetId ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SteamID64_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SteamID64;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventCreateSteamIDFromString_Parms, ReturnValue), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_SteamID64_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_SteamID64 = { UE4CodeGen_Private::EPropertyClass::Str, "SteamID64", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventCreateSteamIDFromString_Parms, SteamID64), METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_SteamID64_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_SteamID64_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::NewProp_SteamID64,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|SteamAPI" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Creates a unique steam id directly from a string holding a uint64 value, useful for testing" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "CreateSteamIDFromString", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(AdvancedSteamFriendsLibrary_eventCreateSteamIDFromString_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventGetFriendSteamLevel_Parms
		{
			FBPUniqueNetId UniqueNetId;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetFriendSteamLevel_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetFriendSteamLevel_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|SteamAPI" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Gets the level of a friends steam account, STEAM ONLY, Returns -1 if the steam level is not known, might need RequestSteamFriendInfo called first." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "GetFriendSteamLevel", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(AdvancedSteamFriendsLibrary_eventGetFriendSteamLevel_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventGetSteamFriendAvatar_Parms
		{
			FBPUniqueNetId UniqueNetId;
			EBlueprintAsyncResultSwitch Result;
			SteamAvatarSize AvatarSize;
			UTexture2D* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_AvatarSize;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_AvatarSize_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendAvatar_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_AvatarSize = { UE4CodeGen_Private::EPropertyClass::Enum, "AvatarSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendAvatar_Parms, AvatarSize), Z_Construct_UEnum_AdvancedSteamSessions_SteamAvatarSize, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_AvatarSize_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendAvatar_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintAsyncResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendAvatar_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_AvatarSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_AvatarSize_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|SteamAPI" },
		{ "CPP_Default_AvatarSize", "SteamAvatar_Medium" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Get a texture of a valid friends avatar, STEAM ONLY, Returns invalid texture if the subsystem hasn't loaded that size of avatar yet" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "GetSteamFriendAvatar", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedSteamFriendsLibrary_eventGetSteamFriendAvatar_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventGetSteamFriendGamePlayed_Parms
		{
			FBPUniqueNetId UniqueNetId;
			EBlueprintResultSwitch Result;
			int32 AppID;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AppID;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_AppID = { UE4CodeGen_Private::EPropertyClass::Int, "AppID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendGamePlayed_Parms, AppID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Enum, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendGamePlayed_Parms, Result), Z_Construct_UEnum_AdvancedSessions_EBlueprintResultSwitch, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_Result_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamFriendGamePlayed_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_AppID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_Result_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|SteamAPI" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", ", FString & GameName" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "GetSteamFriendGamePlayed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedSteamFriendsLibrary_eventGetSteamFriendGamePlayed_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventGetSteamGroups_Parms
		{
			TArray<FBPSteamGroupInfo> SteamGroups;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SteamGroups;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SteamGroups_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::NewProp_SteamGroups = { UE4CodeGen_Private::EPropertyClass::Array, "SteamGroups", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamGroups_Parms, SteamGroups), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::NewProp_SteamGroups_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "SteamGroups", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBPSteamGroupInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::NewProp_SteamGroups,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::NewProp_SteamGroups_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|SteamAPI|SteamGroups" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Get a full list of steam groups" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "GetSteamGroups", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedSteamFriendsLibrary_eventGetSteamGroups_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventGetSteamPersonaName_Parms
		{
			FBPUniqueNetId UniqueNetId;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamPersonaName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventGetSteamPersonaName_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|SteamAPI" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Gets the persona name of a steam ID, STEAM ONLY, Returns empty if no result, might need RequestSteamFriendInfo called first." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "GetSteamPersonaName", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(AdvancedSteamFriendsLibrary_eventGetSteamPersonaName_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics
	{
		struct AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms
		{
			FBPUniqueNetId UniqueNetId;
			bool bRequireNameOnly;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static void NewProp_bRequireNameOnly_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequireNameOnly;
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
	void Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms), &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_bRequireNameOnly_SetBit(void* Obj)
	{
		((AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms*)Obj)->bRequireNameOnly = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_bRequireNameOnly = { UE4CodeGen_Private::EPropertyClass::Bool, "bRequireNameOnly", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms), &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_bRequireNameOnly_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_UniqueNetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_UniqueNetId = { UE4CodeGen_Private::EPropertyClass::Struct, "UniqueNetId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms, UniqueNetId), Z_Construct_UScriptStruct_FBPUniqueNetId, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_UniqueNetId_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_UniqueNetId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_bRequireNameOnly,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::NewProp_UniqueNetId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedFriends|SteamAPI" },
		{ "CPP_Default_bRequireNameOnly", "false" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
		{ "ToolTip", "Preloads the avatar and name of a steam friend, return whether it is already available or not, STEAM ONLY, Takes time to actually load everything after this is called." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamFriendsLibrary, "RequestSteamFriendInfo", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(AdvancedSteamFriendsLibrary_eventRequestSteamFriendInfo_Parms), Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdvancedSteamFriendsLibrary_NoRegister()
	{
		return UAdvancedSteamFriendsLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_CreateSteamIDFromString, "CreateSteamIDFromString" }, // 181650839
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetFriendSteamLevel, "GetFriendSteamLevel" }, // 2799060777
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendAvatar, "GetSteamFriendAvatar" }, // 1789104197
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamFriendGamePlayed, "GetSteamFriendGamePlayed" }, // 211787838
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamGroups, "GetSteamGroups" }, // 1080080147
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_GetSteamPersonaName, "GetSteamPersonaName" }, // 2201689091
		{ &Z_Construct_UFunction_UAdvancedSteamFriendsLibrary_RequestSteamFriendInfo, "RequestSteamFriendInfo" }, // 229287438
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AdvancedSteamFriendsLibrary.h" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamFriendsLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdvancedSteamFriendsLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::ClassParams = {
		&UAdvancedSteamFriendsLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdvancedSteamFriendsLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdvancedSteamFriendsLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdvancedSteamFriendsLibrary, 100190308);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdvancedSteamFriendsLibrary(Z_Construct_UClass_UAdvancedSteamFriendsLibrary, &UAdvancedSteamFriendsLibrary::StaticClass, TEXT("/Script/AdvancedSteamSessions"), TEXT("UAdvancedSteamFriendsLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedSteamFriendsLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
