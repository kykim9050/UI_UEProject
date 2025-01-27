// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseChartWidget.h"
#include "BaseRadarChartWidget.generated.h"

/**
 * 
 */
class URadarChartItemsWidget;
UCLASS()
class MHNT_PRACTICE_API UBaseRadarChartWidget : public UBaseChartWidget
{
    GENERATED_BODY()
public:

protected:
    void convertDataPointsNormal(const int32 datasNum);

    virtual int32 NativePaint(
        const FPaintArgs& Args,
        const FGeometry& AllottedGeometry,
        const FSlateRect& MyCullingRect,
        FSlateWindowElementList& OutDrawElements,
        int32 LayerId,
        const FWidgetStyle& InWidgetStyle,
        bool bParentEnabled
    ) const override;

private:

protected:
    /// <summary>
    /// 방사형 그래프의 범위 최대 각도 (0~360 )
    /// </summary>
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph", meta = (AllowprivateAccess = "true"))
    double mItemsRoundTotalDegree = 360.0;

private:
};
