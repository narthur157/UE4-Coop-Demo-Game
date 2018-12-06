// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedSteamSessions/Classes/AdvancedSteamWorkshopLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedSteamWorkshopLibrary() {}
// Cross Module References
	ADVANCEDSTEAMSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSteamSessions_FBPWorkshopFileType();
	UPackage* Z_Construct_UPackage__Script_AdvancedSteamSessions();
	ADVANCEDSTEAMSESSIONS_API UEnum* Z_Construct_UEnum_AdvancedSteamSessions_FBPSteamResult();
	ADVANCEDSTEAMSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails();
	ADVANCEDSTEAMSESSIONS_API UScriptStruct* Z_Construct_UScriptStruct_FBPSteamWorkshopID();
	ADVANCEDSTEAMSESSIONS_API UClass* Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_NoRegister();
	ADVANCEDSTEAMSESSIONS_API UClass* Z_Construct_UClass_UAdvancedSteamWorkshopLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems();
	ADVANCEDSTEAMSESSIONS_API UFunction* Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems();
// End Cross Module References
	static UEnum* FBPWorkshopFileType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AdvancedSteamSessions_FBPWorkshopFileType, Z_Construct_UPackage__Script_AdvancedSteamSessions(), TEXT("FBPWorkshopFileType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_FBPWorkshopFileType(FBPWorkshopFileType_StaticEnum, TEXT("/Script/AdvancedSteamSessions"), TEXT("FBPWorkshopFileType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AdvancedSteamSessions_FBPWorkshopFileType_CRC() { return 1127463250U; }
	UEnum* Z_Construct_UEnum_AdvancedSteamSessions_FBPWorkshopFileType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AdvancedSteamSessions();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("FBPWorkshopFileType"), 0, Get_Z_Construct_UEnum_AdvancedSteamSessions_FBPWorkshopFileType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeCommunity", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeCommunity },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeMicrotransaction", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeMicrotransaction },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeCollection", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeCollection },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeArt", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeArt },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeVideo", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeVideo },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeScreenshot", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeScreenshot },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeGame", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeGame },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeSoftware", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeSoftware },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeConcept", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeConcept },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeWebGuide", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeWebGuide },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeIntegratedGuide", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeIntegratedGuide },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeMerch", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeMerch },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeControllerBinding", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeControllerBinding },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeSteamworksAccessInvite", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeSteamworksAccessInvite },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeSteamVideo", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeSteamVideo },
				{ "FBPWorkshopFileType::k_EWorkshopFileTypeMax", (int64)FBPWorkshopFileType::k_EWorkshopFileTypeMax },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "k_EWorkshopFileTypeMax.ToolTip", "Update k_EWorkshopFileTypeMax if you add values." },
				{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
				{ "ToolTip", "Check these to future proof" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"FBPWorkshopFileType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"FBPWorkshopFileType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* FBPSteamResult_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AdvancedSteamSessions_FBPSteamResult, Z_Construct_UPackage__Script_AdvancedSteamSessions(), TEXT("FBPSteamResult"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_FBPSteamResult(FBPSteamResult_StaticEnum, TEXT("/Script/AdvancedSteamSessions"), TEXT("FBPSteamResult"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AdvancedSteamSessions_FBPSteamResult_CRC() { return 4090458706U; }
	UEnum* Z_Construct_UEnum_AdvancedSteamSessions_FBPSteamResult()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AdvancedSteamSessions();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("FBPSteamResult"), 0, Get_Z_Construct_UEnum_AdvancedSteamSessions_FBPSteamResult_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "FBPSteamResult::k_EResultOK", (int64)FBPSteamResult::k_EResultOK },
				{ "FBPSteamResult::k_EResultFail", (int64)FBPSteamResult::k_EResultFail },
				{ "FBPSteamResult::k_EResultNoConnection", (int64)FBPSteamResult::k_EResultNoConnection },
				{ "FBPSteamResult::k_EResultInvalidPassword", (int64)FBPSteamResult::k_EResultInvalidPassword },
				{ "FBPSteamResult::k_EResultLoggedInElsewhere", (int64)FBPSteamResult::k_EResultLoggedInElsewhere },
				{ "FBPSteamResult::k_EResultInvalidProtocolVer", (int64)FBPSteamResult::k_EResultInvalidProtocolVer },
				{ "FBPSteamResult::k_EResultInvalidParam", (int64)FBPSteamResult::k_EResultInvalidParam },
				{ "FBPSteamResult::k_EResultFileNotFound", (int64)FBPSteamResult::k_EResultFileNotFound },
				{ "FBPSteamResult::k_EResultBusy", (int64)FBPSteamResult::k_EResultBusy },
				{ "FBPSteamResult::k_EResultInvalidState", (int64)FBPSteamResult::k_EResultInvalidState },
				{ "FBPSteamResult::k_EResultInvalidName", (int64)FBPSteamResult::k_EResultInvalidName },
				{ "FBPSteamResult::k_EResultInvalidEmail", (int64)FBPSteamResult::k_EResultInvalidEmail },
				{ "FBPSteamResult::k_EResultDuplicateName", (int64)FBPSteamResult::k_EResultDuplicateName },
				{ "FBPSteamResult::k_EResultAccessDenied", (int64)FBPSteamResult::k_EResultAccessDenied },
				{ "FBPSteamResult::k_EResultTimeout", (int64)FBPSteamResult::k_EResultTimeout },
				{ "FBPSteamResult::k_EResultBanned", (int64)FBPSteamResult::k_EResultBanned },
				{ "FBPSteamResult::k_EResultAccountNotFound", (int64)FBPSteamResult::k_EResultAccountNotFound },
				{ "FBPSteamResult::k_EResultInvalidSteamID", (int64)FBPSteamResult::k_EResultInvalidSteamID },
				{ "FBPSteamResult::k_EResultServiceUnavailable", (int64)FBPSteamResult::k_EResultServiceUnavailable },
				{ "FBPSteamResult::k_EResultNotLoggedOn", (int64)FBPSteamResult::k_EResultNotLoggedOn },
				{ "FBPSteamResult::k_EResultPending", (int64)FBPSteamResult::k_EResultPending },
				{ "FBPSteamResult::k_EResultEncryptionFailure", (int64)FBPSteamResult::k_EResultEncryptionFailure },
				{ "FBPSteamResult::k_EResultInsufficientPrivilege", (int64)FBPSteamResult::k_EResultInsufficientPrivilege },
				{ "FBPSteamResult::k_EResultLimitExceeded", (int64)FBPSteamResult::k_EResultLimitExceeded },
				{ "FBPSteamResult::k_EResultRevoked", (int64)FBPSteamResult::k_EResultRevoked },
				{ "FBPSteamResult::k_EResultExpired", (int64)FBPSteamResult::k_EResultExpired },
				{ "FBPSteamResult::k_EResultAlreadyRedeemed", (int64)FBPSteamResult::k_EResultAlreadyRedeemed },
				{ "FBPSteamResult::k_EResultDuplicateRequest", (int64)FBPSteamResult::k_EResultDuplicateRequest },
				{ "FBPSteamResult::k_EResultAlreadyOwned", (int64)FBPSteamResult::k_EResultAlreadyOwned },
				{ "FBPSteamResult::k_EResultIPNotFound", (int64)FBPSteamResult::k_EResultIPNotFound },
				{ "FBPSteamResult::k_EResultPersistFailed", (int64)FBPSteamResult::k_EResultPersistFailed },
				{ "FBPSteamResult::k_EResultLockingFailed", (int64)FBPSteamResult::k_EResultLockingFailed },
				{ "FBPSteamResult::k_EResultLogonSessionReplaced", (int64)FBPSteamResult::k_EResultLogonSessionReplaced },
				{ "FBPSteamResult::k_EResultConnectFailed", (int64)FBPSteamResult::k_EResultConnectFailed },
				{ "FBPSteamResult::k_EResultHandshakeFailed", (int64)FBPSteamResult::k_EResultHandshakeFailed },
				{ "FBPSteamResult::k_EResultIOFailure", (int64)FBPSteamResult::k_EResultIOFailure },
				{ "FBPSteamResult::k_EResultRemoteDisconnect", (int64)FBPSteamResult::k_EResultRemoteDisconnect },
				{ "FBPSteamResult::k_EResultShoppingCartNotFound", (int64)FBPSteamResult::k_EResultShoppingCartNotFound },
				{ "FBPSteamResult::k_EResultBlocked", (int64)FBPSteamResult::k_EResultBlocked },
				{ "FBPSteamResult::k_EResultIgnored", (int64)FBPSteamResult::k_EResultIgnored },
				{ "FBPSteamResult::k_EResultNoMatch", (int64)FBPSteamResult::k_EResultNoMatch },
				{ "FBPSteamResult::k_EResultAccountDisabled", (int64)FBPSteamResult::k_EResultAccountDisabled },
				{ "FBPSteamResult::k_EResultServiceReadOnly", (int64)FBPSteamResult::k_EResultServiceReadOnly },
				{ "FBPSteamResult::k_EResultAccountNotFeatured", (int64)FBPSteamResult::k_EResultAccountNotFeatured },
				{ "FBPSteamResult::k_EResultAdministratorOK", (int64)FBPSteamResult::k_EResultAdministratorOK },
				{ "FBPSteamResult::k_EResultContentVersion", (int64)FBPSteamResult::k_EResultContentVersion },
				{ "FBPSteamResult::k_EResultTryAnotherCM", (int64)FBPSteamResult::k_EResultTryAnotherCM },
				{ "FBPSteamResult::k_EResultPasswordRequiredToKickSession", (int64)FBPSteamResult::k_EResultPasswordRequiredToKickSession },
				{ "FBPSteamResult::k_EResultAlreadyLoggedInElsewhere", (int64)FBPSteamResult::k_EResultAlreadyLoggedInElsewhere },
				{ "FBPSteamResult::k_EResultSuspended", (int64)FBPSteamResult::k_EResultSuspended },
				{ "FBPSteamResult::k_EResultCancelled", (int64)FBPSteamResult::k_EResultCancelled },
				{ "FBPSteamResult::k_EResultDataCorruption", (int64)FBPSteamResult::k_EResultDataCorruption },
				{ "FBPSteamResult::k_EResultDiskFull", (int64)FBPSteamResult::k_EResultDiskFull },
				{ "FBPSteamResult::k_EResultRemoteCallFailed", (int64)FBPSteamResult::k_EResultRemoteCallFailed },
				{ "FBPSteamResult::k_EResultPasswordUnset", (int64)FBPSteamResult::k_EResultPasswordUnset },
				{ "FBPSteamResult::k_EResultExternalAccountUnlinked", (int64)FBPSteamResult::k_EResultExternalAccountUnlinked },
				{ "FBPSteamResult::k_EResultPSNTicketInvalid", (int64)FBPSteamResult::k_EResultPSNTicketInvalid },
				{ "FBPSteamResult::k_EResultExternalAccountAlreadyLinked", (int64)FBPSteamResult::k_EResultExternalAccountAlreadyLinked },
				{ "FBPSteamResult::k_EResultRemoteFileConflict", (int64)FBPSteamResult::k_EResultRemoteFileConflict },
				{ "FBPSteamResult::k_EResultIllegalPassword", (int64)FBPSteamResult::k_EResultIllegalPassword },
				{ "FBPSteamResult::k_EResultSameAsPreviousValue", (int64)FBPSteamResult::k_EResultSameAsPreviousValue },
				{ "FBPSteamResult::k_EResultAccountLogonDenied", (int64)FBPSteamResult::k_EResultAccountLogonDenied },
				{ "FBPSteamResult::k_EResultCannotUseOldPassword", (int64)FBPSteamResult::k_EResultCannotUseOldPassword },
				{ "FBPSteamResult::k_EResultInvalidLoginAuthCode", (int64)FBPSteamResult::k_EResultInvalidLoginAuthCode },
				{ "FBPSteamResult::k_EResultAccountLogonDeniedNoMail", (int64)FBPSteamResult::k_EResultAccountLogonDeniedNoMail },
				{ "FBPSteamResult::k_EResultHardwareNotCapableOfIPT", (int64)FBPSteamResult::k_EResultHardwareNotCapableOfIPT },
				{ "FBPSteamResult::k_EResultIPTInitError", (int64)FBPSteamResult::k_EResultIPTInitError },
				{ "FBPSteamResult::k_EResultParentalControlRestricted", (int64)FBPSteamResult::k_EResultParentalControlRestricted },
				{ "FBPSteamResult::k_EResultFacebookQueryError", (int64)FBPSteamResult::k_EResultFacebookQueryError },
				{ "FBPSteamResult::k_EResultExpiredLoginAuthCode", (int64)FBPSteamResult::k_EResultExpiredLoginAuthCode },
				{ "FBPSteamResult::k_EResultIPLoginRestrictionFailed", (int64)FBPSteamResult::k_EResultIPLoginRestrictionFailed },
				{ "FBPSteamResult::k_EResultAccountLockedDown", (int64)FBPSteamResult::k_EResultAccountLockedDown },
				{ "FBPSteamResult::k_EResultAccountLogonDeniedVerifiedEmailRequired", (int64)FBPSteamResult::k_EResultAccountLogonDeniedVerifiedEmailRequired },
				{ "FBPSteamResult::k_EResultNoMatchingURL", (int64)FBPSteamResult::k_EResultNoMatchingURL },
				{ "FBPSteamResult::k_EResultBadResponse", (int64)FBPSteamResult::k_EResultBadResponse },
				{ "FBPSteamResult::k_EResultRequirePasswordReEntry", (int64)FBPSteamResult::k_EResultRequirePasswordReEntry },
				{ "FBPSteamResult::k_EResultValueOutOfRange", (int64)FBPSteamResult::k_EResultValueOutOfRange },
				{ "FBPSteamResult::k_EResultUnexpectedError", (int64)FBPSteamResult::k_EResultUnexpectedError },
				{ "FBPSteamResult::k_EResultDisabled", (int64)FBPSteamResult::k_EResultDisabled },
				{ "FBPSteamResult::k_EResultInvalidCEGSubmission", (int64)FBPSteamResult::k_EResultInvalidCEGSubmission },
				{ "FBPSteamResult::k_EResultRestrictedDevice", (int64)FBPSteamResult::k_EResultRestrictedDevice },
				{ "FBPSteamResult::k_EResultRegionLocked", (int64)FBPSteamResult::k_EResultRegionLocked },
				{ "FBPSteamResult::k_EResultRateLimitExceeded", (int64)FBPSteamResult::k_EResultRateLimitExceeded },
				{ "FBPSteamResult::k_EResultAccountLoginDeniedNeedTwoFactor", (int64)FBPSteamResult::k_EResultAccountLoginDeniedNeedTwoFactor },
				{ "FBPSteamResult::k_EResultItemDeleted", (int64)FBPSteamResult::k_EResultItemDeleted },
				{ "FBPSteamResult::k_EResultAccountLoginDeniedThrottle", (int64)FBPSteamResult::k_EResultAccountLoginDeniedThrottle },
				{ "FBPSteamResult::k_EResultTwoFactorCodeMismatch", (int64)FBPSteamResult::k_EResultTwoFactorCodeMismatch },
				{ "FBPSteamResult::k_EResultTwoFactorActivationCodeMismatch", (int64)FBPSteamResult::k_EResultTwoFactorActivationCodeMismatch },
				{ "FBPSteamResult::k_EResultAccountAssociatedToMultiplePartners", (int64)FBPSteamResult::k_EResultAccountAssociatedToMultiplePartners },
				{ "FBPSteamResult::k_EResultNotModified", (int64)FBPSteamResult::k_EResultNotModified },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "k_EResultAccessDenied.ToolTip", "name is not unique" },
				{ "k_EResultAccountAssociatedToMultiplePartners.ToolTip", "activation code for two-factor didn't match" },
				{ "k_EResultAccountDisabled.ToolTip", "nothing matching the request found" },
				{ "k_EResultAccountLoginDeniedNeedTwoFactor.ToolTip", "Temporary rate limit exceeded, try again later, different from k_EResultLimitExceeded which may be permanent" },
				{ "k_EResultAccountLoginDeniedThrottle.ToolTip", "The thing we're trying to access has been deleted" },
				{ "k_EResultAccountLogonDenied.ToolTip", "new value is the same as the old one ( secret question and answer )" },
				{ "k_EResultAccountLogonDeniedNoMail.ToolTip", "account login denied due to auth code invalid" },
				{ "k_EResultAccountNotFeatured.ToolTip", "this service is not accepting content changes right now" },
				{ "k_EResultAccountNotFound.ToolTip", "VAC2 banned" },
				{ "k_EResultAdministratorOK.ToolTip", "account doesn't have value, so this feature isn't available" },
				{ "k_EResultAlreadyLoggedInElsewhere.ToolTip", "You are already logged in elsewhere, this cached credential login has failed." },
				{ "k_EResultAlreadyOwned.ToolTip", "The request is a duplicate and the action has already occurred in the past, ignored this time" },
				{ "k_EResultAlreadyRedeemed.ToolTip", "License/Guest pass the user is trying to access is expired" },
				{ "k_EResultBanned.ToolTip", "operation timed out" },
				{ "k_EResultBlocked.ToolTip", "failed to find the shopping cart requested" },
				{ "k_EResultBusy.ToolTip", "file was not found" },
				{ "k_EResultCancelled.ToolTip", "Long running operation (content download) suspended/paused" },
				{ "k_EResultCannotUseOldPassword.ToolTip", "account login denied due to 2nd factor authentication failure" },
				{ "k_EResultContentVersion.ToolTip", "allowed to take this action, but only because requester is admin" },
				{ "k_EResultDataCorruption.ToolTip", "Operation canceled (typically by user: content download)" },
				{ "k_EResultDisabled.ToolTip", "something happened that we didn't expect to ever happen" },
				{ "k_EResultDiskFull.ToolTip", "Operation canceled because data is ill formed or unrecoverable" },
				{ "k_EResultDuplicateName.ToolTip", "email is invalid" },
				{ "k_EResultDuplicateRequest.ToolTip", "Guest pass has already been redeemed by account, cannot be acked again" },
				{ "k_EResultEncryptionFailure.ToolTip", "Request is pending (may be in process, or waiting on third party)" },
				{ "k_EResultExpired.ToolTip", "Access has been revoked (used for revoked guest passes)" },
				{ "k_EResultExpiredLoginAuthCode.ToolTip", "Facebook query returned an error" },
				{ "k_EResultExternalAccountAlreadyLinked.ToolTip", "PSN ticket was invalid" },
				{ "k_EResultExternalAccountUnlinked.ToolTip", "Password could not be verified as it's unset server side" },
				{ "k_EResultFacebookQueryError.ToolTip", "operation failed due to parental control restrictions for current user" },
				{ "k_EResultFail.ToolTip", "success" },
				{ "k_EResultFileNotFound.ToolTip", "a parameter is incorrect" },
				{ "k_EResultHardwareNotCapableOfIPT.ToolTip", "account login denied due to 2nd factor auth failure - and no mail has been sent" },
				{ "k_EResultIgnored.ToolTip", "a user didn't allow it" },
				{ "k_EResultIllegalPassword.ToolTip", "The sync cannot resume due to a conflict between the local and remote files" },
				{ "k_EResultInsufficientPrivilege.ToolTip", "Encryption or Decryption failed" },
				{ "k_EResultInvalidCEGSubmission.ToolTip", "The requested service has been configured to be unavailable" },
				{ "k_EResultInvalidEmail.ToolTip", "name is invalid" },
				{ "k_EResultInvalidLoginAuthCode.ToolTip", "The requested new password is not legal" },
				{ "k_EResultInvalidName.ToolTip", "called object was in an invalid state" },
				{ "k_EResultInvalidParam.ToolTip", "protocol version is incorrect" },
				{ "k_EResultInvalidPassword.ToolTip", "no/failed network connection\n      k_EResultNoConnectionRetry = 4,                          OBSOLETE - removed" },
				{ "k_EResultInvalidProtocolVer.ToolTip", "same user logged in elsewhere" },
				{ "k_EResultInvalidState.ToolTip", "called method busy - action not taken" },
				{ "k_EResultInvalidSteamID.ToolTip", "account not found" },
				{ "k_EResultIPLoginRestrictionFailed.ToolTip", "account login denied due to auth code expired" },
				{ "k_EResultIPNotFound.ToolTip", "All the games in this guest pass redemption request are already owned by the user" },
				{ "k_EResultItemDeleted.ToolTip", "Need two-factor code to login" },
				{ "k_EResultLimitExceeded.ToolTip", "Insufficient privilege" },
				{ "k_EResultLockingFailed.ToolTip", "failed to write change to the data store" },
				{ "k_EResultLoggedInElsewhere.ToolTip", "password/ticket is invalid" },
				{ "k_EResultLogonSessionReplaced.ToolTip", "failed to acquire access lock for this operation" },
				{ "k_EResultNoConnection.ToolTip", "generic failure" },
				{ "k_EResultNoMatch.ToolTip", "target is ignoring sender" },
				{ "k_EResultNotLoggedOn.ToolTip", "The requested service is currently unavailable" },
				{ "k_EResultNotModified.ToolTip", "account has been associated with multiple partners" },
				{ "k_EResultPasswordRequiredToKickSession.ToolTip", "The current CM can't service the user making a request, user should try another." },
				{ "k_EResultPasswordUnset.ToolTip", "an remote call or IPC call failed" },
				{ "k_EResultPending.ToolTip", "The user is not logged on" },
				{ "k_EResultPersistFailed.ToolTip", "IP address not found" },
				{ "k_EResultPSNTicketInvalid.ToolTip", "External account (PSN, Facebook...) is not linked to a Steam account" },
				{ "k_EResultRateLimitExceeded.ToolTip", "The action could not be complete because it is region restricted" },
				{ "k_EResultRegionLocked.ToolTip", "The device being used is not allowed to perform this action" },
				{ "k_EResultRemoteCallFailed.ToolTip", "Operation canceled - not enough disk space." },
				{ "k_EResultRemoteFileConflict.ToolTip", "External account (PSN, Facebook...) is already linked to some other account, must explicitly request to replace/delete the link first" },
				{ "k_EResultRequirePasswordReEntry.ToolTip", "parse failure, missing field, etc." },
				{ "k_EResultRestrictedDevice.ToolTip", "The set of files submitted to the CEG server are not valid !" },
				{ "k_EResultRevoked.ToolTip", "Too much of a good thing" },
				{ "k_EResultSameAsPreviousValue.ToolTip", "The requested new password is not legal" },
				{ "k_EResultServiceUnavailable.ToolTip", "steamID is invalid" },
				{ "k_EResultSuspended.ToolTip", "You are already logged in elsewhere, you must wait" },
				{ "k_EResultTimeout.ToolTip", "access is denied" },
				{ "k_EResultTryAnotherCM.ToolTip", "A Version mismatch in content transmitted within the Steam protocol." },
				{ "k_EResultTwoFactorActivationCodeMismatch.ToolTip", "two factor code mismatch" },
				{ "k_EResultTwoFactorCodeMismatch.ToolTip", "login attempt failed, try to throttle response to possible attacker" },
				{ "k_EResultUnexpectedError.ToolTip", "the value entered is outside the acceptable range" },
				{ "k_EResultValueOutOfRange.ToolTip", "The user cannot complete the action until they re-enter their password" },
				{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
				{ "ToolTip", "General result codes - Copying steams version over\nCheck these to future proof" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"FBPSteamResult",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"FBPSteamResult",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FBPSteamWorkshopItemDetails::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADVANCEDSTEAMSESSIONS_API uint32 Get_Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails, Z_Construct_UPackage__Script_AdvancedSteamSessions(), TEXT("BPSteamWorkshopItemDetails"), sizeof(FBPSteamWorkshopItemDetails), Get_Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FBPSteamWorkshopItemDetails(FBPSteamWorkshopItemDetails::StaticStruct, TEXT("/Script/AdvancedSteamSessions"), TEXT("BPSteamWorkshopItemDetails"), false, nullptr, nullptr);
static struct FScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamWorkshopItemDetails
{
	FScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamWorkshopItemDetails()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("BPSteamWorkshopItemDetails")),new UScriptStruct::TCppStructOps<FBPSteamWorkshopItemDetails>);
	}
} ScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamWorkshopItemDetails;
	struct Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CreatorSteamID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CreatorSteamID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTagsTruncated_MetaData[];
#endif
		static void NewProp_bTagsTruncated_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTagsTruncated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAcceptedForUse_MetaData[];
#endif
		static void NewProp_bAcceptedForUse_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAcceptedForUse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bBanned_MetaData[];
#endif
		static void NewProp_bBanned_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bBanned;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CalculatedScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CalculatedScore;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VotesDown_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_VotesDown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VotesUp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_VotesUp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemUrl_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ItemUrl;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Description;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Title;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConsumerAppID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ConsumerAppID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CreatorAppID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CreatorAppID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_FileType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_FileType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResultOfRequest_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ResultOfRequest;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ResultOfRequest_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "WorkshopItemDetails Struct" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBPSteamWorkshopItemDetails>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorSteamID_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Steam ID of the user who created this content." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorSteamID = { UE4CodeGen_Private::EPropertyClass::Str, "CreatorSteamID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, CreatorSteamID), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorSteamID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorSteamID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "whether the list of tags was too long to be returned in the provided buffer" },
	};
#endif
	void Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated_SetBit(void* Obj)
	{
		((FBPSteamWorkshopItemDetails*)Obj)->bTagsTruncated = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated = { UE4CodeGen_Private::EPropertyClass::Bool, "bTagsTruncated", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FBPSteamWorkshopItemDetails), &Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "developer has specifically flagged this item as accepted in the Workshop" },
	};
#endif
	void Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse_SetBit(void* Obj)
	{
		((FBPSteamWorkshopItemDetails*)Obj)->bAcceptedForUse = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse = { UE4CodeGen_Private::EPropertyClass::Bool, "bAcceptedForUse", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FBPSteamWorkshopItemDetails), &Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "whether the file was banned" },
	};
#endif
	void Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned_SetBit(void* Obj)
	{
		((FBPSteamWorkshopItemDetails*)Obj)->bBanned = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned = { UE4CodeGen_Private::EPropertyClass::Bool, "bBanned", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FBPSteamWorkshopItemDetails), &Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CalculatedScore_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Calculated score" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CalculatedScore = { UE4CodeGen_Private::EPropertyClass::Float, "CalculatedScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, CalculatedScore), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CalculatedScore_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CalculatedScore_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesDown_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesDown = { UE4CodeGen_Private::EPropertyClass::Int, "VotesDown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, VotesDown), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesDown_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesDown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesUp_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Votes will be unlikely to go above signed limited" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesUp = { UE4CodeGen_Private::EPropertyClass::Int, "VotesUp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, VotesUp), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesUp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesUp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ItemUrl_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Url for a video of website" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ItemUrl = { UE4CodeGen_Private::EPropertyClass::Str, "ItemUrl", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, ItemUrl), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ItemUrl_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ItemUrl_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Description of item" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Description = { UE4CodeGen_Private::EPropertyClass::Str, "Description", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, Description), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Description_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Description_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Title_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Title of item" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Title = { UE4CodeGen_Private::EPropertyClass::Str, "Title", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, Title), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Title_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Title_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ConsumerAppID_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ConsumerAppID = { UE4CodeGen_Private::EPropertyClass::Int, "ConsumerAppID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, ConsumerAppID), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ConsumerAppID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ConsumerAppID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorAppID_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "These two are listed as baked to an int, but is stored as a uint, think its safe to keep int" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorAppID = { UE4CodeGen_Private::EPropertyClass::Int, "CreatorAppID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, CreatorAppID), METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorAppID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorAppID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Type of file" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType = { UE4CodeGen_Private::EPropertyClass::Enum, "FileType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, FileType), Z_Construct_UEnum_AdvancedSteamSessions_FBPWorkshopFileType, METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest_MetaData[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Result of obtaining the details" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest = { UE4CodeGen_Private::EPropertyClass::Enum, "ResultOfRequest", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000015, 1, nullptr, STRUCT_OFFSET(FBPSteamWorkshopItemDetails, ResultOfRequest), Z_Construct_UEnum_AdvancedSteamSessions_FBPSteamResult, METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorSteamID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bTagsTruncated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bAcceptedForUse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_bBanned,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CalculatedScore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesDown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_VotesUp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ItemUrl,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Description,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_Title,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ConsumerAppID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_CreatorAppID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_FileType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::NewProp_ResultOfRequest_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
		nullptr,
		&NewStructOps,
		"BPSteamWorkshopItemDetails",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FBPSteamWorkshopItemDetails),
		alignof(FBPSteamWorkshopItemDetails),
		Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_AdvancedSteamSessions();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("BPSteamWorkshopItemDetails"), sizeof(FBPSteamWorkshopItemDetails), Get_Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FBPSteamWorkshopItemDetails_CRC() { return 1287372985U; }
class UScriptStruct* FBPSteamWorkshopID::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADVANCEDSTEAMSESSIONS_API uint32 Get_Z_Construct_UScriptStruct_FBPSteamWorkshopID_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FBPSteamWorkshopID, Z_Construct_UPackage__Script_AdvancedSteamSessions(), TEXT("BPSteamWorkshopID"), sizeof(FBPSteamWorkshopID), Get_Z_Construct_UScriptStruct_FBPSteamWorkshopID_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FBPSteamWorkshopID(FBPSteamWorkshopID::StaticStruct, TEXT("/Script/AdvancedSteamSessions"), TEXT("BPSteamWorkshopID"), false, nullptr, nullptr);
static struct FScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamWorkshopID
{
	FScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamWorkshopID()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("BPSteamWorkshopID")),new UScriptStruct::TCppStructOps<FBPSteamWorkshopID>);
	}
} ScriptStruct_AdvancedSteamSessions_StaticRegisterNativesFBPSteamWorkshopID;
	struct Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Using a custom struct because uint32 isn't blueprint supported and I don't want to cast to int32\ndue to the size of the workshop it could end up overflowing?" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBPSteamWorkshopID>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
		nullptr,
		&NewStructOps,
		"BPSteamWorkshopID",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FBPSteamWorkshopID),
		alignof(FBPSteamWorkshopID),
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBPSteamWorkshopID()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FBPSteamWorkshopID_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_AdvancedSteamSessions();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("BPSteamWorkshopID"), sizeof(FBPSteamWorkshopID), Get_Z_Construct_UScriptStruct_FBPSteamWorkshopID_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FBPSteamWorkshopID_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FBPSteamWorkshopID_CRC() { return 3376508407U; }
	void UAdvancedSteamWorkshopLibrary::StaticRegisterNativesUAdvancedSteamWorkshopLibrary()
	{
		UClass* Class = UAdvancedSteamWorkshopLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetNumSubscribedWorkshopItems", &UAdvancedSteamWorkshopLibrary::execGetNumSubscribedWorkshopItems },
			{ "GetSubscribedWorkshopItems", &UAdvancedSteamWorkshopLibrary::execGetSubscribedWorkshopItems },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics
	{
		struct AdvancedSteamWorkshopLibrary_eventGetNumSubscribedWorkshopItems_Parms
		{
			int32 NumberOfItems;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NumberOfItems;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::NewProp_NumberOfItems = { UE4CodeGen_Private::EPropertyClass::Int, "NumberOfItems", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedSteamWorkshopLibrary_eventGetNumSubscribedWorkshopItems_Parms, NumberOfItems), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::NewProp_NumberOfItems,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamWorkshopLibrary, "GetNumSubscribedWorkshopItems", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedSteamWorkshopLibrary_eventGetNumSubscribedWorkshopItems_Parms), Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics
	{
		struct AdvancedSteamWorkshopLibrary_eventGetSubscribedWorkshopItems_Parms
		{
			int32 NumberOfItems;
			TArray<FBPSteamWorkshopID> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NumberOfItems;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AdvancedSteamWorkshopLibrary_eventGetSubscribedWorkshopItems_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBPSteamWorkshopID, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::NewProp_NumberOfItems = { UE4CodeGen_Private::EPropertyClass::Int, "NumberOfItems", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(AdvancedSteamWorkshopLibrary_eventGetSubscribedWorkshopItems_Parms, NumberOfItems), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::NewProp_NumberOfItems,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "Online|AdvancedSteamWorkshop" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
		{ "ToolTip", "Returns IDs for subscribed workshop items, TArray length dictates how many" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedSteamWorkshopLibrary, "GetSubscribedWorkshopItems", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AdvancedSteamWorkshopLibrary_eventGetSubscribedWorkshopItems_Parms), Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_NoRegister()
	{
		return UAdvancedSteamWorkshopLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvancedSteamSessions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetNumSubscribedWorkshopItems, "GetNumSubscribedWorkshopItems" }, // 302791122
		{ &Z_Construct_UFunction_UAdvancedSteamWorkshopLibrary_GetSubscribedWorkshopItems, "GetSubscribedWorkshopItems" }, // 471118294
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AdvancedSteamWorkshopLibrary.h" },
		{ "ModuleRelativePath", "Classes/AdvancedSteamWorkshopLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdvancedSteamWorkshopLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::ClassParams = {
		&UAdvancedSteamWorkshopLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdvancedSteamWorkshopLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdvancedSteamWorkshopLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdvancedSteamWorkshopLibrary, 3440844729);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdvancedSteamWorkshopLibrary(Z_Construct_UClass_UAdvancedSteamWorkshopLibrary, &UAdvancedSteamWorkshopLibrary::StaticClass, TEXT("/Script/AdvancedSteamSessions"), TEXT("UAdvancedSteamWorkshopLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedSteamWorkshopLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
