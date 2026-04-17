// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KismetPins/SGraphPinColor.h"

/**
 * 
 */

class COLORPALETTEEDITOR_API SPaletteGraphPinColor : public SGraphPinColor
{
public:
	
	SLATE_BEGIN_ARGS(SPaletteGraphPinColor) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj);

protected:

	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override;
	FReply OnClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

private:
	
	TSharedPtr<SWidget> DefaultValueWidget;
};


