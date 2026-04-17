// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ColorPaletteSettings.generated.h"

/**
 * 
 */




UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Color Palette Settings"))
class COLORPALETTE_API UColorPaletteSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UColorPaletteSettings(const FObjectInitializer& ObjectInitializer);
	static const UColorPaletteSettings* Get();

	UFUNCTION(BlueprintPure)
	static UColorPaletteSettings* GetColorPaletteSettings();


	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "General", meta=(RequiredAssetDataTags="RowStructure=/Script/ColorPalette.ColorPallet"))
	TMap<FName, TSoftObjectPtr<UDataTable>> RegisteredPalettes;
	
};
