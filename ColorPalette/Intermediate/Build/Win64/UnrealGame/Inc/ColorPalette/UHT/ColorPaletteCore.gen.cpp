// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ColorPalette/Core/ColorPaletteCore.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeColorPaletteCore() {}

// Begin Cross Module References
COLORPALETTE_API UClass* Z_Construct_UClass_UColorPaletteCore();
COLORPALETTE_API UClass* Z_Construct_UClass_UColorPaletteCore_NoRegister();
COLORPALETTE_API UScriptStruct* Z_Construct_UScriptStruct_FColorPallet();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_ColorPalette();
// End Cross Module References

// Begin ScriptStruct FColorPallet
static_assert(std::is_polymorphic<FColorPallet>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FColorPallet cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ColorPallet;
class UScriptStruct* FColorPallet::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ColorPallet.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ColorPallet.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FColorPallet, (UObject*)Z_Construct_UPackage__Script_ColorPalette(), TEXT("ColorPallet"));
	}
	return Z_Registration_Info_UScriptStruct_ColorPallet.OuterSingleton;
}
template<> COLORPALETTE_API UScriptStruct* StaticStruct<FColorPallet>()
{
	return FColorPallet::StaticStruct();
}
struct Z_Construct_UScriptStruct_FColorPallet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Core/ColorPaletteCore.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
		{ "Category", "ColorUtilities" },
		{ "ModuleRelativePath", "Core/ColorPaletteCore.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FColorPallet>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FColorPallet_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FColorPallet, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Color_MetaData), NewProp_Color_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FColorPallet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FColorPallet_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorPallet_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FColorPallet_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ColorPalette,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"ColorPallet",
	Z_Construct_UScriptStruct_FColorPallet_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorPallet_Statics::PropPointers),
	sizeof(FColorPallet),
	alignof(FColorPallet),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorPallet_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FColorPallet_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FColorPallet()
{
	if (!Z_Registration_Info_UScriptStruct_ColorPallet.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ColorPallet.InnerSingleton, Z_Construct_UScriptStruct_FColorPallet_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ColorPallet.InnerSingleton;
}
// End ScriptStruct FColorPallet

// Begin Class UColorPaletteCore
void UColorPaletteCore::StaticRegisterNativesUColorPaletteCore()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UColorPaletteCore);
UClass* Z_Construct_UClass_UColorPaletteCore_NoRegister()
{
	return UColorPaletteCore::StaticClass();
}
struct Z_Construct_UClass_UColorPaletteCore_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Core/ColorPaletteCore.h" },
		{ "ModuleRelativePath", "Core/ColorPaletteCore.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UColorPaletteCore>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UColorPaletteCore_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ColorPalette,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UColorPaletteCore_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UColorPaletteCore_Statics::ClassParams = {
	&UColorPaletteCore::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UColorPaletteCore_Statics::Class_MetaDataParams), Z_Construct_UClass_UColorPaletteCore_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UColorPaletteCore()
{
	if (!Z_Registration_Info_UClass_UColorPaletteCore.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UColorPaletteCore.OuterSingleton, Z_Construct_UClass_UColorPaletteCore_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UColorPaletteCore.OuterSingleton;
}
template<> COLORPALETTE_API UClass* StaticClass<UColorPaletteCore>()
{
	return UColorPaletteCore::StaticClass();
}
UColorPaletteCore::UColorPaletteCore(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UColorPaletteCore);
UColorPaletteCore::~UColorPaletteCore() {}
// End Class UColorPaletteCore

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteCore_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FColorPallet::StaticStruct, Z_Construct_UScriptStruct_FColorPallet_Statics::NewStructOps, TEXT("ColorPallet"), &Z_Registration_Info_UScriptStruct_ColorPallet, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FColorPallet), 47797225U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UColorPaletteCore, UColorPaletteCore::StaticClass, TEXT("UColorPaletteCore"), &Z_Registration_Info_UClass_UColorPaletteCore, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UColorPaletteCore), 3864185382U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteCore_h_1466124760(TEXT("/Script/ColorPalette"),
	Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteCore_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteCore_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteCore_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteCore_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
