// Fill out your copyright notice in the Description page of Project Settings.

#include "ColorPaletteEditor.h"
#include "ColorPaletteEditor/Customization/FColorPaletteCustomization.h"
#include "ColorPaletteEditor/Customization/FSlateColorPaletteCustomization.h"
#include "ColorPaletteEditor/Slate/SColorPaletteSelector.h"
#include "ColorPaletteEditor/Slate/SPaletteColorPicker.h"

#include "Modules/ModuleManager.h"



#define LOCTEXT_NAMESPACE "FColorPaletteEditor"

void FColorPaletteEditor::StartupModule()
{
	
	static FName PropertyEditor("PropertyEditor");
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);
	PropertyModule.RegisterCustomPropertyTypeLayout("LinearColor", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FColorPaletteCustomization::MakeInstance));
	PropertyModule.RegisterCustomPropertyTypeLayout("Color", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FColorPaletteCustomization::MakeInstance));
	PropertyModule.RegisterCustomPropertyTypeLayout(TEXT("SlateColor"), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSlateColorPaletteCustomization::MakeInstance));
	PropertyModule.NotifyCustomizationModuleChanged();

	
	MyFactory = MakeShareable(new FColorPaletteGraphPanelPinFactory());
	FEdGraphUtilities::RegisterVisualPinFactory(MyFactory);

}

void FColorPaletteEditor::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{

		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomPropertyTypeLayout("LinearColor");
		PropertyModule.UnregisterCustomPropertyTypeLayout("Color");
		PropertyModule.UnregisterCustomPropertyTypeLayout("SlateColor");

		PropertyModule.NotifyCustomizationModuleChanged();
	}
}


bool OpenCustomColorPicker(const FColorPickerArgs& Args)
{
	CustomDestroyColorPicker();
	bool Result = false;

#if PLATFORM_DESKTOP
	
	FLinearColor OldColor = Args.InitialColor;
	ensureMsgf(Args.OnColorCommitted.IsBound(), TEXT("OnColorCommitted should be bound to set the color."));
	
	FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();
	FSlateRect Anchor(CursorPos.X, CursorPos.Y, CursorPos.X, CursorPos.Y);
	FVector2D AdjustedSummonLocation = FSlateApplication::Get().CalculatePopupWindowPosition( Anchor, SColorPicker::DEFAULT_WINDOW_SIZE + FVector2D(100.f, 300.f), true, FVector2D::ZeroVector, Orient_Horizontal );

	
	const bool bOverrideNonModalCreation = (SColorPicker::OnColorPickerNonModalCreateOverride.IsBound() && !Args.bIsModal);

	TSharedPtr<SWindow> Window = nullptr;
	TSharedRef<SBorder> WindowContent = SNew(SBorder)
			.BorderImage(FAppStyle::Get().GetBrush("Brushes.Panel"))
			.Padding(FMargin(8.0f, 8.0f));
	
	bool bNeedToAddWindow = true;
	if (!bOverrideNonModalCreation)
	{
		if (Args.bOpenAsMenu && !Args.bIsModal && Args.ParentWidget.IsValid())
		{
			Window = FSlateApplication::Get().PushMenu(
				Args.ParentWidget.ToSharedRef(),
				FWidgetPath(),
				WindowContent,
				AdjustedSummonLocation,
				FPopupTransitionEffect(FPopupTransitionEffect::None),
				false,
				FVector2D(0.f,0.f),
				EPopupMethod::CreateNewWindow,
				false)->GetOwnedWindow();

			bNeedToAddWindow = false;
		}
		else
		{
			Window = SNew(SWindow)
				.AutoCenter(EAutoCenter::None)
				.ScreenPosition(AdjustedSummonLocation)
				.SupportsMaximize(false)
				.SupportsMinimize(false)
				.SizingRule(ESizingRule::Autosized)
				.Title(LOCTEXT("WindowHeader", "Color Picker"))
				[
					WindowContent
				];
		}
	}
	
	TSharedRef<SPaletteColorPicker> CreatedColorPicker = SNew(SPaletteColorPicker)
		.TargetColorAttribute(OldColor)
		.UseAlpha(Args.bUseAlpha)
		.ExpandAdvancedSection(Args.bExpandAdvancedSection)
		.OnlyRefreshOnMouseUp(Args.bOnlyRefreshOnMouseUp && !Args.bIsModal)
		.OnlyRefreshOnOk(Args.bOnlyRefreshOnOk || Args.bIsModal)
		.OnColorCommitted(Args.OnColorCommitted)
		.OnColorPickerCancelled(Args.OnColorPickerCancelled)
		.OnInteractivePickBegin(Args.OnInteractivePickBegin)
		.OnInteractivePickEnd(Args.OnInteractivePickEnd)
		.OnColorPickerWindowClosed(Args.OnColorPickerWindowClosed)
		.ParentWindow(Window)
		.DisplayGamma(Args.DisplayGamma)
		.sRGBOverride(Args.sRGBOverride)
		.OptionalOwningDetailsView(Args.OptionalOwningDetailsView);


	
	TSharedRef<SBox> Content = SNew(SBox)
	.Padding(10.f)
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			CreatedColorPicker
		]
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SColorPaletteSelector)
			.OnSelectColor_Lambda([CreatedColorPicker](FLinearColor Color)
				{
				CreatedColorPicker->UpdateColor(Color);
				})
		]
	];
	
	if (bOverrideNonModalCreation)
	{
		SColorPicker::OnColorPickerNonModalCreateOverride.Execute(CreatedColorPicker);

		Result = true;

		WindowContent->SetContent(Content);
		CustomColorPickerWindow = Window;
	}
	else
	{
		WindowContent->SetContent(Content);

		if (Args.bIsModal)
		{
			FSlateApplication::Get().AddModalWindow(Window.ToSharedRef(), Args.ParentWidget);
		}
		else if (bNeedToAddWindow)
		{
			if (Args.ParentWidget.IsValid())
			{
				FWidgetPath WidgetPath;
				FSlateApplication::Get().GeneratePathToWidgetChecked(Args.ParentWidget.ToSharedRef(), WidgetPath);
				Window = FSlateApplication::Get().AddWindowAsNativeChild(Window.ToSharedRef(), WidgetPath.GetWindow());
			}
			else
			{
				Window = FSlateApplication::Get().AddWindow(Window.ToSharedRef());
			}

			Window->GetOnWindowDeactivatedEvent().AddStatic(&CustomDestroyColorPicker);

		}

		Result = true;

		CustomColorPickerWindow = Window;
	}
	
	CustomGlobalColorPicker = CreatedColorPicker;
#endif

	return Result;
}

void CustomDestroyColorPicker()
{
	if (CustomColorPickerWindow.IsValid())
	{
		CustomColorPickerWindow.Pin()->RequestDestroyWindow();
		CustomColorPickerWindow.Reset();
		CustomGlobalColorPicker.Reset();
	}
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FColorPaletteEditor, ColorPaletteEditor);