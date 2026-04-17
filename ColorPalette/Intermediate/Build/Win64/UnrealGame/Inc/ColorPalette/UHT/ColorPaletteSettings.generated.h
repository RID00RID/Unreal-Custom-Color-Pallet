// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/ColorPaletteSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UColorPaletteSettings;
#ifdef COLORPALETTE_ColorPaletteSettings_generated_h
#error "ColorPaletteSettings.generated.h already included, missing '#pragma once' in ColorPaletteSettings.h"
#endif
#define COLORPALETTE_ColorPaletteSettings_generated_h

#define FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetColorPaletteSettings);


#define FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUColorPaletteSettings(); \
	friend struct Z_Construct_UClass_UColorPaletteSettings_Statics; \
public: \
	DECLARE_CLASS(UColorPaletteSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ColorPalette"), NO_API) \
	DECLARE_SERIALIZER(UColorPaletteSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UColorPaletteSettings(UColorPaletteSettings&&); \
	UColorPaletteSettings(const UColorPaletteSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UColorPaletteSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UColorPaletteSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UColorPaletteSettings) \
	NO_API virtual ~UColorPaletteSettings();


#define FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_16_PROLOG
#define FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_INCLASS_NO_PURE_DECLS \
	FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COLORPALETTE_API UClass* StaticClass<class UColorPaletteSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitProject_AshenSkies_Plugins_ColorPalette_Source_ColorPalette_Core_ColorPaletteSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
