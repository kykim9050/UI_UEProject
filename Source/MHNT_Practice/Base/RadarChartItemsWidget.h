// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseChartWidget.h"
#include "RadarChartItemsWidget.generated.h"

/**
 * 
 */
UCLASS()
class MHNT_PRACTICE_API URadarChartItemsWidget : public UBaseChartWidget
{
	GENERATED_BODY()
public:
    void SetItems(const TArray<FText>& itemNames);

protected:
    // Override OnPaint to draw the graph
    int32 NativePaint(
        const FPaintArgs& Args,
        const FGeometry& AllottedGeometry,
        const FSlateRect& MyCullingRect,
        FSlateWindowElementList& OutDrawElements,
        int32 LayerId,
        const FWidgetStyle& InWidgetStyle,
        bool bParentEnabled
    ) const override;

    const FVector2D findCanvasCenterOffset(const FVector2D& canvasSize) const override;

private:

protected:

private:
    /// <summary>
    /// 표시할 항목 명들
    /// </summary>
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph", meta = (AllowprivateAccess = "true"))
    TArray<FText> mItemNames;

    float mItemTextSize = 10.f;

    double mItemsRoundTotalDegree = 360.0;
};
