// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class APlayerController;
class UEndSessionCallbackProxy;
#ifdef ADVANCEDSESSIONS_EndSessionCallbackProxy_generated_h
#error "EndSessionCallbackProxy.generated.h already included, missing '#pragma once' in EndSessionCallbackProxy.h"
#endif
#define ADVANCEDSESSIONS_EndSessionCallbackProxy_generated_h

#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndSession) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UEndSessionCallbackProxy**)Z_Param__Result=UEndSessionCallbackProxy::EndSession(Z_Param_WorldContextObject,Z_Param_PlayerController); \
		P_NATIVE_END; \
	}


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndSession) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UEndSessionCallbackProxy**)Z_Param__Result=UEndSessionCallbackProxy::EndSession(Z_Param_WorldContextObject,Z_Param_PlayerController); \
		P_NATIVE_END; \
	}


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEndSessionCallbackProxy(); \
	friend struct Z_Construct_UClass_UEndSessionCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UEndSessionCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UEndSessionCallbackProxy)


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUEndSessionCallbackProxy(); \
	friend struct Z_Construct_UClass_UEndSessionCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UEndSessionCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UEndSessionCallbackProxy)


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UEndSessionCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEndSessionCallbackProxy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UEndSessionCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEndSessionCallbackProxy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UEndSessionCallbackProxy(UEndSessionCallbackProxy&&); \
	ADVANCEDSESSIONS_API UEndSessionCallbackProxy(const UEndSessionCallbackProxy&); \
public:


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UEndSessionCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UEndSessionCallbackProxy(UEndSessionCallbackProxy&&); \
	ADVANCEDSESSIONS_API UEndSessionCallbackProxy(const UEndSessionCallbackProxy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UEndSessionCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEndSessionCallbackProxy); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEndSessionCallbackProxy)


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_PRIVATE_PROPERTY_OFFSET
#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_8_PROLOG
#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_PRIVATE_PROPERTY_OFFSET \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_RPC_WRAPPERS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_INCLASS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_PRIVATE_PROPERTY_OFFSET \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_INCLASS_NO_PURE_DECLS \
	PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class EndSessionCallbackProxy."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PluginExpProject_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_EndSessionCallbackProxy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
