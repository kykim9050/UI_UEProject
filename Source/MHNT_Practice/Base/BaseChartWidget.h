// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseChartWidget.generated.h"

/**
 * 
 */
UCLASS()
class MHNT_PRACTICE_API UBaseChartWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    void SetGraphData(const TArray<FVector2D>& InDataPoints);

protected:   
    // Override OnPaint to draw the graph
    virtual int32 NativePaint(
        const FPaintArgs& Args,
        const FGeometry& AllottedGeometry,
        const FSlateRect& MyCullingRect,
        FSlateWindowElementList& OutDrawElements,
        int32 LayerId,
        const FWidgetStyle& InWidgetStyle,
        bool bParentEnabled
    ) const override
    {
        return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
    }

private:

protected:
    // Data points for the graph
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph", meta = (AllowprivateAccess = "true"))
    TArray<FVector2D> DataPoints;
  
private:
};
