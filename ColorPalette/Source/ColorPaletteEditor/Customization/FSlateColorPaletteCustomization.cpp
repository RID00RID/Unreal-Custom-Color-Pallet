// Fill out your copyright notice in the Description page of Project Settings.


#include "FSlateColorPaletteCustomization.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"


void FSlateColorPaletteCustomization::CustomizeHeader(TSharedRef<class IPropertyHandle> InStructPropertyHandle,class FDetailWidgetRow& InHeaderRow,IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	static const FName ColorUseRuleKey(TEXT("ColorUseRule"));
	static const FName SpecifiedColorKey(TEXT("SpecifiedColor"));

	StructPropertyHandle = InStructPropertyHandle;

	ColorRuleHandle = InStructPropertyHandle->GetChildHandle(ColorUseRuleKey);
	SpecifiedColorHandle = InStructPropertyHandle->GetChildHandle(SpecifiedColorKey);

	check(ColorRuleHandle.IsValid());
	check(SpecifiedColorHandle.IsValid());

	ColorRuleHandle->MarkHiddenByCustomization();
	FColorPaletteCustomization::CustomizeHeader(SpecifiedColorHandle.ToSharedRef(), InHeaderRow,StructCustomizationUtils);
	
	sRGBOverride = true;
}

void FSlateColorPaletteCustomization::MakeHeaderRow(TSharedRef<class IPropertyHandle>& InStructPropertyHandle,FDetailWidgetRow& Row)
{
	Row
	.NameContent()
	[
		SNew(STextBlock)
		.Font(IDetailLayoutBuilder::GetDetailFont())
		.Text(StructPropertyHandle->GetPropertyDisplayName())
		.ToolTipText(StructPropertyHandle->GetToolTipText())
	]
	.ValueContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SBox)
			.WidthOverride(250.f)
			[

				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					CreateCustomColorWidget(StructPropertyHandle)
				]

				+ SHorizontalBox::Slot()
				  .AutoWidth()
				  .Padding(2.f, 0.f, 0.f, 0.f)
				[
					SNew(SCheckBox)
					[
						SNew(STextBlock)
						.Font(IDetailLayoutBuilder::GetDetailFont())
						.Text(FText::FromString("Inherit"))
						.ToolTipText(FText::FromString("Uses the foreground color inherited down the widget hierarchy"))
					]
				]
			]
		]
	];
}


