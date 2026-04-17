// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Customizations/ColorStructCustomization.h"

class SPaletteColorPicker;


class COLORPALETTEEDITOR_API FColorPaletteCustomization : public FColorStructCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance()
	{
		return MakeShareable(new FColorPaletteCustomization);
	}

protected:
	
	virtual void MakeHeaderRow(TSharedRef<IPropertyHandle>& InStructPropertyHandle, FDetailWidgetRow& Row) override;
	virtual void CreateCustomColorPicker();
	virtual TSharedRef<SWidget> CreateCustomColorWidget(TWeakPtr<IPropertyHandle> InStructWeakHandlePtr);
	FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

private:
	
	TSharedPtr<SPaletteColorPicker> CreatedColorPicker;
};