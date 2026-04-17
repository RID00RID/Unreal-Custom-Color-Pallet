// Fill out your copyright notice in the Description page of Project Settings.


#include "SPaletteGraphPinColor.h"

#include "ColorPaletteEditor.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Colors/SColorPicker.h"

void SPaletteGraphPinColor::Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InGraphPinObj);
}

TSharedRef<SWidget> SPaletteGraphPinColor::GetDefaultValueWidget()
{
	
	return SAssignNew(DefaultValueWidget, SBorder)
		.BorderImage( FAppStyle::GetBrush("FilledBorder") )
		.Visibility( this, &SGraphPin::GetDefaultValueVisibility )
		.IsEnabled(this, &SGraphPin::GetDefaultValueIsEditable)
		.Padding(1)
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew( SColorBlock )
				.Color( this, &SGraphPinColor::GetColor )
				.ShowBackgroundForAlpha(true)
				.OnMouseButtonDown( this, &SPaletteGraphPinColor::OnClicked )
			]
		];
}

FReply SPaletteGraphPinColor::OnClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		FColorPickerArgs PickerArgs;
		PickerArgs.bIsModal = true;
		PickerArgs.ParentWidget = DefaultValueWidget;
		PickerArgs.DisplayGamma = TAttribute<float>::Create(TAttribute<float>::FGetter::CreateUObject(GEngine, &UEngine::GetDisplayGamma));
		PickerArgs.InitialColor = GetColor();
		PickerArgs.OnColorCommitted = FOnLinearColorValueChanged::CreateSP(this, &SPaletteGraphPinColor::OnColorCommitted);
		PickerArgs.bUseAlpha = true;
		OpenCustomColorPicker(PickerArgs);

		
		return FReply::Handled();
	}
	else
	{
		return FReply::Unhandled();
	}
}



