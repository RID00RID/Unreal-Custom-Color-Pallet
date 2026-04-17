// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class COLORPALETTEEDITOR_API SColorPaletteSelector : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SColorPaletteSelector) {}
		SLATE_EVENT(FOnLinearColorValueChanged, OnSelectColor)
	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs);
	
protected:
	
	TSharedPtr<SVerticalBox> VerticalBox;
	FOnLinearColorValueChanged OnSelectColor;
};
