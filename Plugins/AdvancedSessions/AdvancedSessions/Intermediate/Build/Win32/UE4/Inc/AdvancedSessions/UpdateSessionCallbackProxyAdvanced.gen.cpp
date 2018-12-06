// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSessions/Classes/UpdateSessionCallbackProxyAdvanced.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUpdateSessionCallbackProxyAdvanced() {}
// Cross Module References
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_NoRegister();
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced();
	ENGINE_API UClass* Z_Construct_UClass_UOnlineBlueprintCallProxyBase();
	UPackage* Z_Construct_UPackage__Script_AdvancedSessions();
	ADVANCEDSESSIONS_API UFunction* Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession();
	ADVANCEDSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FSessionPropertyKeyPair();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UFunction* Z_Construct_UDelegateFunction_Engine_EmptyOnlineDelegate__DelegateSignature();
// End Cross Module References
	void UUpdateSessionCallbackProxyAdvanced::StaticRegisterNativesUUpdateSessionCallbackProxyAdvanced()
	{
		UClass* Class = UUpdateSessionCallbackProxyAdvanced::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateSession", &UUpdateSessionCallbackProxyAdvanced::execUpdateSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics
	{
		struct UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms
		{
			UObject* WorldContextObject;
			TArray<FSessionPropertyKeyPair> ExtraSettings;
			int32 PublicConnections;
			int32 PrivateConnections;
			bool bUseLAN;
			bool bAllowInvites;
			bool bAllowJoinInProgress;
			bool bRefreshOnlineData;
			bool bIsDedicatedServer;
			UUpdateSessionCallbackProxyAdvanced* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static void NewProp_bIsDedicatedServer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsDedicatedServer;
		static void NewProp_bRefreshOnlineData_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRefreshOnlineData;
		static void NewProp_bAllowJoinInProgress_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowJoinInProgress;
		static void NewProp_bAllowInvites_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowInvites;
		static void NewProp_bUseLAN_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseLAN;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_PrivateConnections;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_PublicConnections;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExtraSettings_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ExtraSettings;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ExtraSettings_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms, ReturnValue), Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bIsDedicatedServer_SetBit(void* Obj)
	{
		((UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms*)Obj)->bIsDedicatedServer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bIsDedicatedServer = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsDedicatedServer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms), &Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bIsDedicatedServer_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bRefreshOnlineData_SetBit(void* Obj)
	{
		((UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms*)Obj)->bRefreshOnlineData = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bRefreshOnlineData = { UE4CodeGen_Private::EPropertyClass::Bool, "bRefreshOnlineData", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms), &Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bRefreshOnlineData_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowJoinInProgress_SetBit(void* Obj)
	{
		((UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms*)Obj)->bAllowJoinInProgress = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowJoinInProgress = { UE4CodeGen_Private::EPropertyClass::Bool, "bAllowJoinInProgress", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms), &Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowJoinInProgress_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowInvites_SetBit(void* Obj)
	{
		((UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms*)Obj)->bAllowInvites = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowInvites = { UE4CodeGen_Private::EPropertyClass::Bool, "bAllowInvites", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms), &Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowInvites_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bUseLAN_SetBit(void* Obj)
	{
		((UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms*)Obj)->bUseLAN = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bUseLAN = { UE4CodeGen_Private::EPropertyClass::Bool, "bUseLAN", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms), &Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bUseLAN_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_PrivateConnections = { UE4CodeGen_Private::EPropertyClass::Int, "PrivateConnections", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms, PrivateConnections), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_PublicConnections = { UE4CodeGen_Private::EPropertyClass::Int, "PublicConnections", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms, PublicConnections), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings = { UE4CodeGen_Private::EPropertyClass::Array, "ExtraSettings", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms, ExtraSettings), METADATA_PARAMS(Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ExtraSettings", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FSessionPropertyKeyPair, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bIsDedicatedServer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bRefreshOnlineData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowJoinInProgress,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bAllowInvites,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_bUseLAN,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_PrivateConnections,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_PublicConnections,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_ExtraSettings_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ExtraSettings" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Online|AdvancedSessions" },
		{ "CPP_Default_bAllowInvites", "false" },
		{ "CPP_Default_bAllowJoinInProgress", "false" },
		{ "CPP_Default_bIsDedicatedServer", "false" },
		{ "CPP_Default_bRefreshOnlineData", "true" },
		{ "CPP_Default_bUseLAN", "false" },
		{ "CPP_Default_PrivateConnections", "0" },
		{ "CPP_Default_PublicConnections", "100" },
		{ "ModuleRelativePath", "Classes/UpdateSessionCallbackProxyAdvanced.h" },
		{ "ToolTip", "Creates a session with the default online subsystem with advanced optional inputs, you MUST fill in all categories or it will pass in values that you didn't want as default values" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced, "UpdateSession", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(UpdateSessionCallbackProxyAdvanced_eventUpdateSession_Parms), Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_NoRegister()
	{
		return UUpdateSessionCallbackProxyAdvanced::StaticClass();
	}
	struct Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnFailure_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFailure;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UOnlineBlueprintCallProxyBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUpdateSessionCallbackProxyAdvanced_UpdateSession, "UpdateSession" }, // 1805262188
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UpdateSessionCallbackProxyAdvanced.h" },
		{ "ModuleRelativePath", "Classes/UpdateSessionCallbackProxyAdvanced.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnFailure_MetaData[] = {
		{ "ModuleRelativePath", "Classes/UpdateSessionCallbackProxyAdvanced.h" },
		{ "ToolTip", "Called when there was an error updating the session" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnFailure = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnFailure", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UUpdateSessionCallbackProxyAdvanced, OnFailure), Z_Construct_UDelegateFunction_Engine_EmptyOnlineDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnFailure_MetaData, ARRAY_COUNT(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnFailure_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnSuccess_MetaData[] = {
		{ "ModuleRelativePath", "Classes/UpdateSessionCallbackProxyAdvanced.h" },
		{ "ToolTip", "Called when the session was updated successfully" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnSuccess = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnSuccess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UUpdateSessionCallbackProxyAdvanced, OnSuccess), Z_Construct_UDelegateFunction_Engine_EmptyOnlineDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnSuccess_MetaData, ARRAY_COUNT(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnSuccess_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnFailure,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::NewProp_OnSuccess,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUpdateSessionCallbackProxyAdvanced>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::ClassParams = {
		&UUpdateSessionCallbackProxyAdvanced::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008800A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUpdateSessionCallbackProxyAdvanced, 1196758738);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUpdateSessionCallbackProxyAdvanced(Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced, &UUpdateSessionCallbackProxyAdvanced::StaticClass, TEXT("/Script/AdvancedSessions"), TEXT("UUpdateSessionCallbackProxyAdvanced"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUpdateSessionCallbackProxyAdvanced);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
