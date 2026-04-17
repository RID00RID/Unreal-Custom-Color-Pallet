// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ColorPaletteCore.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct COLORPALETTE_API FColorPallet : public FTableRowBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ColorUtilities")
	FLinearColor Color;
};



UCLASS()
class COLORPALETTE_API UColorPaletteCore : public UObject
{
	GENERATED_BODY()
};
