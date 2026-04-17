// Fill out your copyright notice in the Description page of Project Settings.


#include "SColorPaletteSelector.h"

#include "SColorPaletteEntity.h"
#include "ColorPalette/Core/ColorPaletteCore.h"
#include "ColorPalette/Core/ColorPaletteSettings.h"
#include "Widgets/Layout/SWrapBox.h"


struct FColorPallet;

void SColorPaletteSelector::Construct(const FArguments& InArgs)
{
	OnSelectColor = InArgs._OnSelectColor;
	
	VerticalBox.Reset();
	this->ChildSlot
	.Padding(0,5)
	[
		SAssignNew(VerticalBox, SVerticalBox)	
	];

	if (const UColorPaletteSettings* ColorPaletteSettings = UColorPaletteSettings::Get())
	{
		for (auto Pallet : ColorPaletteSettings->RegisteredPalettes)
		{
			TSharedPtr<SWrapBox> Wrapper = SNew(SWrapBox)
			.UseAllottedWidth(true)
			.InnerSlotPadding(FVector2D(4.0f, 4.0f));
			
			TSharedPtr<SExpandableArea> Area = SNew(SExpandableArea)
				.AccessibleText(FText::FromName(Pallet.Key))
				.HeaderContent()
				[
					SNew(STextBlock).Text(FText::FromName(Pallet.Key))
				]
				.BodyContent()
				[
					Wrapper.ToSharedRef()
				];
			

			
			UDataTable* Table =Pallet.Value.LoadSynchronous();
			if (IsValid(Table))
			{
				TArray<FColorPallet*> ColorsRows;
				Table->GetAllRows<FColorPallet>(TEXT("Get ALl"), ColorsRows);

				for (auto Row : ColorsRows)
				{
					if (!Row) continue;

					FColorPallet CurrentColor = *Row;
					
					Wrapper->AddSlot()
					[
						SNew(SColorPaletteEntity)
						.Color(CurrentColor.Color)
						.OnSelectColor_Lambda([this](FLinearColor Color)
						{
							if (OnSelectColor.IsBound())
							{
								OnSelectColor.Execute(Color);
							}
						})
					];
				}
			}

			VerticalBox->AddSlot()
			.AutoHeight()
			[
				SNew(SBox)
				.Padding(0, 1)
				[
					Area.ToSharedRef()
				]
			];

		}
	}
	
}

