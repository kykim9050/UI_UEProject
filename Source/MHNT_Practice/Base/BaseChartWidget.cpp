// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseChartWidget.h"
#include "Slate/SlateBrushAsset.h"
#include "Engine/Canvas.h"

void UBaseChartWidget::SetGraphData(const TArray<FVector2D>& InDataPoints)
{
    mDataPoints = InDataPoints;

    Invalidate(EInvalidateWidget::Paint); // Force the widget to redraw
}

const FVector2D UBaseChartWidget::findCanvasCenterOffset(const FVector2D& canvasSize) const
{
    FVector2D canvasOffset{ 0., 0. };
    canvasSize.X >= canvasSize.Y ? (canvasOffset.X = canvasSize.X / 2. - canvasSize.Y / 2.) : (canvasOffset.Y = canvasSize.Y / 2. - canvasSize.X / 2.);

    return canvasOffset;
}
