// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorPaletteSettings.h"

UColorPaletteSettings::UColorPaletteSettings(const FObjectInitializer& ObjectInitializer)
{
	
}

const UColorPaletteSettings* UColorPaletteSettings::Get()
{
	return GetDefault<UColorPaletteSettings>();
}

UColorPaletteSettings* UColorPaletteSettings::GetColorPaletteSettings()
{
	return GetMutableDefault<UColorPaletteSettings>();
}
