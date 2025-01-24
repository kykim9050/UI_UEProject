// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseChartWidget.h"
#include "Slate/SlateBrushAsset.h"
#include "Engine/Canvas.h"

void UBaseChartWidget::SetGraphData(const TArray<FVector2D>& InDataPoints)
{
    mDataPoints = InDataPoints;

    Invalidate(EInvalidateWidget::Paint); // Force the widget to redraw
}