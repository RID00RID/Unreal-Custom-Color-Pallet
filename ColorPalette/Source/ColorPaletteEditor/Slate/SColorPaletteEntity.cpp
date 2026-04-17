// Fill out your copyright notice in the Description page of Project Settings.


#include "SColorPaletteEntity.h"

#include "Widgets/Colors/SColorBlock.h"


void SColorPaletteEntity::Construct(const FArguments& InArgs)
{
	Color = InArgs._Color;	
	OnSelectColor = InArgs._OnSelectColor;

	ChildSlot
	[
		SNew(SBox)
			.WidthOverride(40.f)
			.HeightOverride(40.f)
			[
				SNew(SBorder)
				.BorderBackgroundColor(Color)
				.BorderImage(FAppStyle::GetBrush("ColorPicker.MultipleValuesBackground"))
			]
	];
}

int32 SColorPaletteEntity::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const ESlateDrawEffect DrawEffects = bParentEnabled ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect;
	FLinearColor InColor = Color;
	

	FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), FAppStyle::Get().GetBrush("ColorPicker.RoundedAlphaBackground"), DrawEffects);
	
	TArray<FSlateGradientStop> GradientStops;
	MakeSection(GradientStops, FVector2D::ZeroVector, AllottedGeometry.GetLocalSize() * 0.5f, InColor, InWidgetStyle, false);
	MakeSection(GradientStops, AllottedGeometry.GetLocalSize() * 0.5f, AllottedGeometry.GetLocalSize(), InColor, InWidgetStyle, true);

	FSlateDrawElement::MakeGradient(
		OutDrawElements,
		LayerId+1,
		AllottedGeometry.ToPaintGeometry(),
		MoveTemp(GradientStops),
		Orient_Vertical,
		DrawEffects,
		FVector4f(4,4,4,4)
	);


	return LayerId + 1;
}

FReply SColorPaletteEntity::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (OnSelectColor.IsBound())
	{
		OnSelectColor.Execute(Color);
	}
	return FReply::Handled();
}

void SColorPaletteEntity::MakeSection(TArray<FSlateGradientStop>& OutGradientStops, FVector2D StartPt, FVector2D EndPt,
                                      FLinearColor InColor, const FWidgetStyle& InWidgetStyle, bool bIgnoreAlpha) const
{
	// determine if it is HDR
	const float MaxRGB = FMath::Max3(InColor.R, InColor.G, InColor.B);
	if (MaxRGB > 1.f)
	{
		const float Alpha = bIgnoreAlpha ? 1.0f : InColor.A;
		FLinearColor NormalizedLinearColor = InColor / MaxRGB;
		NormalizedLinearColor.A = Alpha;
		const FLinearColor DrawNormalizedColor = InWidgetStyle.GetColorAndOpacityTint() * NormalizedLinearColor.ToFColor(true);

		FLinearColor ClampedLinearColor = InColor;
		ClampedLinearColor.A = Alpha * MaxRGB;
		const FLinearColor DrawClampedColor = InWidgetStyle.GetColorAndOpacityTint() * ClampedLinearColor.ToFColor(true);

		OutGradientStops.Add(FSlateGradientStop(StartPt, DrawNormalizedColor));
		OutGradientStops.Add(FSlateGradientStop((StartPt + EndPt) * 0.5f, DrawClampedColor));
		OutGradientStops.Add(FSlateGradientStop(EndPt, DrawNormalizedColor));
	}
	else
	{
		FColor DrawColor = InColor.ToFColor(true);
		if (bIgnoreAlpha)
		{
			DrawColor.A = 255;
		}
		OutGradientStops.Add(FSlateGradientStop(StartPt, InWidgetStyle.GetColorAndOpacityTint() * DrawColor));
		OutGradientStops.Add(FSlateGradientStop(EndPt, InWidgetStyle.GetColorAndOpacityTint() * DrawColor));
	}
}
