// Fill out your copyright notice in the Description page of Project Settings.


#include "FColorPaletteCustomization.h"

#include "ColorPaletteEditor.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Colors/SColorPicker.h"



void FColorPaletteCustomization::MakeHeaderRow(TSharedRef<IPropertyHandle>& InStructPropertyHandle, FDetailWidgetRow& Row)
{
	TSharedPtr<SWidget> ColorWidget;
	float ContentWidth = 125.0f;

	TWeakPtr<IPropertyHandle> StructWeakHandlePtr = StructPropertyHandle;

	if (InStructPropertyHandle->HasMetaData("InlineColorPicker"))
	{
		ColorWidget = CreateInlineColorPicker(StructWeakHandlePtr);
		ContentWidth = 384.0f;
	}
	else
	{
		ColorWidget = CreateCustomColorWidget(StructWeakHandlePtr);
	}

	Row.NameContent()
	[
		StructPropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.MinDesiredWidth(ContentWidth)
	[
		ColorWidget.ToSharedRef()
	];
}

TSharedRef<SWidget> FColorPaletteCustomization::CreateCustomColorWidget(TWeakPtr<IPropertyHandle> InStructWeakHandlePtr)
{
	return SNew(SBox)
		.Padding(FMargin(0.0f, 0.0f, 4.0f, 0.0f))
		.VAlign(VAlign_Center)
		[
			SAssignNew(ColorWidgetBackgroundBorder, SBorder)
			.Padding(1)
			.BorderImage(FAppStyle::Get().GetBrush("ColorPicker.RoundedSolidBackground"))
			.BorderBackgroundColor(this, &FColorPaletteCustomization::GetColorWidgetBorderColor)
			.VAlign(VAlign_Center)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.VAlign(VAlign_Center)
				[
					SAssignNew(ColorPickerParentWidget, SColorBlock)
					.AlphaBackgroundBrush(FAppStyle::Get().GetBrush("ColorPicker.RoundedAlphaBackground"))
					.Color(this, &FColorPaletteCustomization::OnGetColorForColorBlock)
					.ShowBackgroundForAlpha(true)
					.AlphaDisplayMode(bIgnoreAlpha ? EColorBlockAlphaDisplayMode::Ignore : EColorBlockAlphaDisplayMode::Separate)
					.OnMouseButtonDown(this, &FColorPaletteCustomization::OnMouseButtonDown)
					.Size(FVector2D(70.0f, 20.0f))
					.CornerRadius(FVector4(4.0f, 4.0f, 4.0f, 4.0f))
					.IsEnabled(this, &FColorPaletteCustomization::IsValueEnabled, InStructWeakHandlePtr)
				]
				+ SOverlay::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(SBorder)
					.Visibility(this, &FColorPaletteCustomization::GetMultipleValuesTextVisibility)
					.BorderImage(FAppStyle::Get().GetBrush("ColorPicker.MultipleValuesBackground"))
					.VAlign(VAlign_Center)
					.ForegroundColor(FAppStyle::Get().GetWidgetStyle<FEditableTextBoxStyle>("NormalEditableTextBox").ForegroundColor)
					.Padding(FMargin(12.0f, 2.0f))
					[
						SNew(STextBlock)
						.Text(NSLOCTEXT("PropertyEditor", "MultipleValues", "Multiple Values"))
						.Font(IDetailLayoutBuilder::GetDetailFont())
					]
				]
			]
		];
}

FReply FColorPaletteCustomization::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() != EKeys::LeftMouseButton)
	{
		return FReply::Unhandled();
	}
	
	const bool bCanShowColorPicker = !StructPropertyHandle.IsValid() || 
	                                 (StructPropertyHandle->GetProperty() != nullptr && 
	                                  !StructPropertyHandle->IsEditConst());
	
	if (bCanShowColorPicker)
	{
		CreateCustomColorPicker();
	}

	return FReply::Handled();
}

void FColorPaletteCustomization::CreateCustomColorPicker()
{
	TransactionIndex = GEditor->BeginTransaction(FText::Format(INVTEXT("Edit {0}"), StructPropertyHandle->GetPropertyDisplayName()));

	GatherSavedPreColorPickerColors();

	FLinearColor InitialColor;
	GetColorAsLinear(InitialColor);

	const bool bOnlyRefreshOnMouseUp = StructPropertyHandle->HasMetaData("OnlyUpdateOnInteractionEnd");

	FColorPickerArgs PickerArgs;
	PickerArgs.bUseAlpha = !bIgnoreAlpha;
	PickerArgs.bOnlyRefreshOnMouseUp = bOnlyRefreshOnMouseUp;
	PickerArgs.sRGBOverride = sRGBOverride;
	PickerArgs.DisplayGamma = TAttribute<float>::Create(TAttribute<float>::FGetter::CreateUObject(GEngine, &UEngine::GetDisplayGamma));
	PickerArgs.OnColorCommitted = FOnLinearColorValueChanged::CreateSP(this, &FColorPaletteCustomization::OnSetColorFromColorPicker);
	PickerArgs.OnColorPickerCancelled = FOnColorPickerCancelled::CreateSP(this, &FColorPaletteCustomization::OnColorPickerCancelled);
	PickerArgs.OnColorPickerWindowClosed = FOnWindowClosed::CreateSP(this, &FColorPaletteCustomization::OnColorPickerWindowClosed);
	PickerArgs.OnInteractivePickBegin = FSimpleDelegate::CreateSP(this, &FColorPaletteCustomization::OnColorPickerInteractiveBegin);
	PickerArgs.OnInteractivePickEnd = FSimpleDelegate::CreateSP(this, &FColorPaletteCustomization::OnColorPickerInteractiveEnd);
	PickerArgs.InitialColor = InitialColor;
	PickerArgs.ParentWidget = ColorPickerParentWidget;
	PickerArgs.OptionalOwningDetailsView = ColorPickerParentWidget;
	
	FWidgetPath ParentWidgetPath;
	if (FSlateApplication::Get().FindPathToWidget(ColorPickerParentWidget.ToSharedRef(), ParentWidgetPath))
	{
		PickerArgs.bOpenAsMenu = FSlateApplication::Get().FindMenuInWidgetPath(ParentWidgetPath).IsValid();
	}

	OpenCustomColorPicker(PickerArgs);
}