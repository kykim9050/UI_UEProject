// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseRadarChartWidget.h"

void UBaseRadarChartWidget::convertDataPointsNormal(const int32 datasNum)
{
    int32 num = datasNum;

    // 위치 좌표 형성
    // 데이터 수만큼 나누어 일정한 각도 간격
    mDataPoints.Reserve(num);

    double radUnit = FMath::DegreesToRadians(mItemsRoundTotalDegree / StaticCast<double>(num));
    for (int32 i = 0; i < num; i++)
    {
        mDataPoints.Add(FVector2D{
            FMath::Cos(StaticCast<double>(i) * radUnit),
            FMath::Sin(StaticCast<double>(i) * radUnit) }
            );
    }
}

int32 UBaseRadarChartWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}
