// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Colors/SColorPicker.h"

/**
 * 
 */
class COLORPALETTEEDITOR_API SPaletteColorPicker : public SColorPicker
{
	
public:
	
	void UpdateColor(FLinearColor NewValue)
	{
		SetNewTargetColorRGB(NewValue, true);
	}
};