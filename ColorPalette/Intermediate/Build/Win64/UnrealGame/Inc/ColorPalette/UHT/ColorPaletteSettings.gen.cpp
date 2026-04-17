// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ColorPalette/Core/ColorPaletteSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeColorPaletteSettings() {}

// Begin Cross Module References
COLORPALETTE_API UClass* Z_Construct_UClass_UColorPaletteSettings();
COLORPALETTE_API UClass* Z_Construct_UClass_UColorPaletteSettings_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
UPackage* Z_Construct_UPackage__Script_ColorPalette();
// End Cross Module References

// Begin Class UColorPaletteSettings Function GetColorPaletteSettings
struct Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics
{
	struct ColorPaletteSettings_eventGetColorPaletteSettings_Parms
	{
		UColorPaletteSettings* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/ColorPaletteSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ColorPaletteSettings_eventGetColorPaletteSettings_Parms, ReturnValue), Z_Construct_UClass_UColorPaletteSettings_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UColorPaletteSettings, nullptr, "GetColorPaletteSettings", nullptr, nullptr, Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::ColorPaletteSettings_eventGetColorPaletteSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::ColorPaletteSettings_eventGetColorPaletteSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UColorPaletteSettings::execGetColorPaletteSettings)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UColorPaletteSettings**)Z_Param__Result=UColorPaletteSettings::GetColorPaletteSettings();
	P_NATIVE_END;
}
// End Class UColorPaletteSettings Function GetColorPaletteSettings

// Begin Class UColorPaletteSettings
void UColorPaletteSettings::StaticRegisterNativesUColorPaletteSettings()
{
	UClass* Class = UColorPaletteSettings::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetColorPaletteSettings", &UColorPaletteSettings::execGetColorPaletteSettings },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UColorPaletteSettings);
UClass* Z_Construct_UClass_UColorPaletteSettings_NoRegister()
{
	return UColorPaletteSettings::StaticClass();
}
struct Z_Construct_UClass_UColorPaletteSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "DisplayName", "Color Palette Settings" },
		{ "IncludePath", "Core/ColorPaletteSettings.h" },
		{ "ModuleRelativePath", "Core/ColorPaletteSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegisteredPalettes_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Core/ColorPaletteSettings.h" },
		{ "RequiredAssetDataTags", "RowStructure=/Script/ColorPalette.ColorPallet" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_RegisteredPalettes_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_RegisteredPalettes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RegisteredPalettes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UColorPaletteSettings_GetColorPaletteSettings, "GetColorPaletteSettings" }, // 1453204391
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UColorPaletteSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UColorPaletteSettings_Statics::NewProp_RegisteredPalettes_ValueProp = { "RegisteredPalettes", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UColorPaletteSettings_Statics::NewProp_RegisteredPalettes_Key_KeyProp = { "RegisteredPalettes_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UColorPaletteSettings_Statics::NewProp_RegisteredPalettes = { "RegisteredPalettes", nullptr, (EPropertyFlags)0x0014000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UColorPaletteSettings, RegisteredPalettes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegisteredPalettes_MetaData), NewProp_RegisteredPalettes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UColorPaletteSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UColorPaletteSettings_Statics::NewProp_RegisteredPalettes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UColorPaletteSettings_Statics::NewProp_RegisteredPalettes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UColorPaletteSettings_Statics::NewProp_RegisteredPalettes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UColorPaletteSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UColorPaletteSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ColorPalette,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UColorPaletteSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UColorPaletteSettings_Statics::ClassParams = {
	&UColorPaletteSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UColorPaletteSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UColorPaletteSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UColorPaletteSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UColorPaletteSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UColorPaletteSettings()
{
	if (!Z_Registration_Info_UClass_UColorPaletteSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UColorPaletteSettings.OuterSingleton, Z_Construct_UClass_UColorPaletteSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UColorPaletteSettings.OuterSingleton;
}
template<> COLORPALETTE_API UClass* StaticClass<UColorPaletteSettings>()
{
	return UColorPaletteSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UColorPaletteSettings);
UColorPaletteSettings::~UColorPaletteSettings() {}
// End Class UColorPaletteSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UColorPaletteSettings, UColorPaletteSettings::StaticClass, TEXT("UColorPaletteSettings"), &Z_Registration_Info_UClass_UColorPaletteSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UColorPaletteSettings), 3242459351U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_263710852(TEXT("/Script/ColorPalette"),
	Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
