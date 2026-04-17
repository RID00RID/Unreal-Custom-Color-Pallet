// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class COLORPALETTEEDITOR_API SColorPaletteEntity : public SCompoundWidget
{
	
public:
	
	SLATE_BEGIN_ARGS(SColorPaletteEntity) {}
		SLATE_ARGUMENT(FLinearColor, Color)
		SLATE_EVENT(FOnLinearColorValueChanged, OnSelectColor)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

protected:

	FLinearColor Color;
	FOnLinearColorValueChanged OnSelectColor;

private:

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void MakeSection(TArray<FSlateGradientStop>& OutGradientStops, FVector2D StartPt, FVector2D EndPt, FLinearColor Color, const FWidgetStyle& InWidgetStyle, bool bIgnoreAlpha) const;
};
