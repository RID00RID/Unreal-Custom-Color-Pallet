// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColorPaletteEditor/Factoryes/ColorPaletteGraphPanelPinFactory.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Colors/SColorPicker.h"


class SPaletteColorPicker;

class FColorPaletteEditor : public IModuleInterface
{
public:


	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


	TSharedPtr<FColorPaletteGraphPanelPinFactory> MyFactory;

};


static TWeakPtr<SWindow> CustomColorPickerWindow;
static TWeakPtr<SPaletteColorPicker> CustomGlobalColorPicker;
bool OpenCustomColorPicker(const FColorPickerArgs& Args);
void CustomDestroyColorPicker();