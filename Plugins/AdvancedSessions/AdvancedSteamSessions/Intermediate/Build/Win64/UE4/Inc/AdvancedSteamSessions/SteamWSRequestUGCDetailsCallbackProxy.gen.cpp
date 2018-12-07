// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSteamSessions/Classes/SteamWSRequestUGCDetailsCallbackProxy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSteamWSRequestUGCDetailsCallbackProxy() {}
// Cross Module References
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_AdvancedSteamSessions();
	ADVANCEDSTEAMSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails();
	ADVANCEDSTEAMSESSIONS_API UClass* Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_NoRegister();
	ADVANCEDSTEAMSESSIONS_API UClass* Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy();
	ENGINE_API UClass* Z_Construct_UClass_UOnlineBlueprintCallProxyBase();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails();
	ADVANCEDSTEAMSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPSteamWorkshopID();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics
	{
		struct _Script_AdvancedSteamSessions_eventBlueprintWorkshopDetailsDelegate_Parms
		{
			FBPSteamWorkshopItemDetails WorkShopDetails;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorkShopDetails_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorkShopDetails;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::NewProp_WorkShopDetails_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::NewProp_WorkShopDetails = { UE4CodeGen_Private::EPropertyClass::Struct, "WorkShopDetails", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_AdvancedSteamSessions_eventBlueprintWorkshopDetailsDelegate_Parms, WorkShopDetails), Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails, METADATA_PARAMS(Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::NewProp_WorkShopDetails_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::NewProp_WorkShopDetails_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::NewProp_WorkShopDetails,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/SteamWSRequestUGCDetailsCallbackProxy.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_AdvancedSteamSessions, "BlueprintWorkshopDetailsDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_AdvancedSteamSessions_eventBlueprintWorkshopDetailsDelegate_Parms), Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void USteamWSRequestUGCDetailsCallbackProxy::StaticRegisterNativesUSteamWSRequestUGCDetailsCallbackProxy()
	{
		UClass* Class = USteamWSRequestUGCDetailsCallbackProxy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetWorkshopItemDetails", &USteamWSRequestUGCDetailsCallbackProxy::execGetWorkshopItemDetails },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics
	{
		struct SteamWSRequestUGCDetailsCallbackProxy_eventGetWorkshopItemDetails_Parms
		{
			UObject* WorldContextObject;
			FBPSteamWorkshopID WorkShopID;
			USteamWSRequestUGCDetailsCallbackProxy* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorkShopID;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(SteamWSRequestUGCDetailsCallbackProxy_eventGetWorkshopItemDetails_Parms, ReturnValue), Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::NewProp_WorkShopID = { UE4CodeGen_Private::EPropertyClass::Struct, "WorkShopID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SteamWSRequestUGCDetailsCallbackProxy_eventGetWorkshopItemDetails_Parms, WorkShopID), Z_Construct_UScriptStruct_FBPSteamWorkshopID, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SteamWSRequestUGCDetailsCallbackProxy_eventGetWorkshopItemDetails_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::NewProp_WorkShopID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/SteamWSRequestUGCDetailsCallbackProxy.h" },
		{ "ToolTip", "Ends the current session" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy, "GetWorkshopItemDetails", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(SteamWSRequestUGCDetailsCallbackProxy_eventGetWorkshopItemDetails_Parms), Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_NoRegister()
	{
		return USteamWSRequestUGCDetailsCallbackProxy::StaticClass();
	}
	struct Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics
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
	UObject* (*const Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UOnlineBlueprintCallProxyBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USteamWSRequestUGCDetailsCallbackProxy_GetWorkshopItemDetails, "GetWorkshopItemDetails" }, // 1316777722
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SteamWSRequestUGCDetailsCallbackProxy.h" },
		{ "ModuleRelativePath", "Classes/SteamWSRequestUGCDetailsCallbackProxy.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnFailure_MetaData[] = {
		{ "ModuleRelativePath", "Classes/SteamWSRequestUGCDetailsCallbackProxy.h" },
		{ "ToolTip", "Called when there is an unsuccessful results return" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnFailure = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnFailure", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(USteamWSRequestUGCDetailsCallbackProxy, OnFailure), Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnFailure_MetaData, ARRAY_COUNT(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnFailure_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnSuccess_MetaData[] = {
		{ "ModuleRelativePath", "Classes/SteamWSRequestUGCDetailsCallbackProxy.h" },
		{ "ToolTip", "Called when there is a successful results return" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnSuccess = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnSuccess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(USteamWSRequestUGCDetailsCallbackProxy, OnSuccess), Z_Construct_UDelegateFunction_AdvancedSteamSessions_BlueprintWorkshopDetailsDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnSuccess_MetaData, ARRAY_COUNT(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnSuccess_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnFailure,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::NewProp_OnSuccess,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USteamWSRequestUGCDetailsCallbackProxy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::ClassParams = {
		&USteamWSRequestUGCDetailsCallbackProxy::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008800A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USteamWSRequestUGCDetailsCallbackProxy, 4257197542);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USteamWSRequestUGCDetailsCallbackProxy(Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy, &USteamWSRequestUGCDetailsCallbackProxy::StaticClass, TEXT("/Script/AdvancedSteamSessions"), TEXT("USteamWSRequestUGCDetailsCallbackProxy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USteamWSRequestUGCDetailsCallbackProxy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
