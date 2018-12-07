// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBPOnlineRecentPlayer;
class UObject;
struct FBPUniqueNetId;
class UGetRecentPlayersCallbackProxy;
#ifdef ADVANCEDSESSIONS_GetRecentPlayersCallbackProxy_generated_h
#error "GetRecentPlayersCallbackProxy.generated.h already included, missing '#pragma once' in GetRecentPlayersCallbackProxy.h"
#endif
#define ADVANCEDSESSIONS_GetRecentPlayersCallbackProxy_generated_h

#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_10_DELEGATE \
struct _Script_AdvancedSessions_eventBlueprintGetRecentPlayersDelegate_Parms \
{ \
	TArray<FBPOnlineRecentPlayer> Results; \
}; \
static inline void FBlueprintGetRecentPlayersDelegate_DelegateWrapper(const FMulticastScriptDelegate& BlueprintGetRecentPlayersDelegate, TArray<FBPOnlineRecentPlayer> const& Results) \
{ \
	_Script_AdvancedSessions_eventBlueprintGetRecentPlayersDelegate_Parms Parms; \
	Parms.Results=Results; \
	BlueprintGetRecentPlayersDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAndStoreRecentPlayersList) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT_REF(FBPUniqueNetId,Z_Param_Out_UniqueNetId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UGetRecentPlayersCallbackProxy**)Z_Param__Result=UGetRecentPlayersCallbackProxy::GetAndStoreRecentPlayersList(Z_Param_WorldContextObject,Z_Param_Out_UniqueNetId); \
		P_NATIVE_END; \
	}


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAndStoreRecentPlayersList) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT_REF(FBPUniqueNetId,Z_Param_Out_UniqueNetId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UGetRecentPlayersCallbackProxy**)Z_Param__Result=UGetRecentPlayersCallbackProxy::GetAndStoreRecentPlayersList(Z_Param_WorldContextObject,Z_Param_Out_UniqueNetId); \
		P_NATIVE_END; \
	}


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGetRecentPlayersCallbackProxy(); \
	friend struct Z_Construct_UClass_UGetRecentPlayersCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UGetRecentPlayersCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UGetRecentPlayersCallbackProxy)


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUGetRecentPlayersCallbackProxy(); \
	friend struct Z_Construct_UClass_UGetRecentPlayersCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UGetRecentPlayersCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UGetRecentPlayersCallbackProxy)


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetRecentPlayersCallbackProxy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UGetRecentPlayersCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetRecentPlayersCallbackProxy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(UGetRecentPlayersCallbackProxy&&); \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const UGetRecentPlayersCallbackProxy&); \
public:


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(UGetRecentPlayersCallbackProxy&&); \
	ADVANCEDSESSIONS_API UGetRecentPlayersCallbackProxy(const UGetRecentPlayersCallbackProxy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UGetRecentPlayersCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetRecentPlayersCallbackProxy); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetRecentPlayersCallbackProxy)


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_PRIVATE_PROPERTY_OFFSET
#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_12_PROLOG
#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_PRIVATE_PROPERTY_OFFSET \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_PRIVATE_PROPERTY_OFFSET \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_INCLASS_NO_PURE_DECLS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h_15_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GetRecentPlayersCallbackProxy."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_GetRecentPlayersCallbackProxy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
