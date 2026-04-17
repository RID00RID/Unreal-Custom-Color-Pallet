// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EdGraphUtilities.h"
#include "SGraphPin.h"
#include "ColorPaletteEditor/PinStyle/SPaletteGraphPinColor.h"

/**
 * 
 */
class COLORPALETTEEDITOR_API FColorPaletteGraphPanelPinFactory : public FGraphPanelPinFactory
{
public:
	virtual TSharedPtr<SGraphPin> CreatePin(UEdGraphPin* Pin) const override
	{
		if (Pin->PinType.PinCategory == "struct")
		{
			if (Pin->PinType.PinSubCategoryObject == TBaseStructure<FLinearColor>::Get())
			{
				return SNew(SPaletteGraphPinColor, Pin);
			}
		}

		return nullptr;
	}
};
