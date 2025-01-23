// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Industry/IndustryTBMChartWidget.h"
#include "Slate/SlateBrushAsset.h"
#include "Engine/Canvas.h"

void UIndustryTBMChartWidget::SetGraphData(const TArray<FVector2D>& InDataPoints)
{
    DataPoints = InDataPoints;

    Invalidate(EInvalidateWidget::Paint); // Force the widget to redraw
}

int32 UIndustryTBMChartWidget::NativePaint(
    const FPaintArgs& Args,
    const FGeometry& AllottedGeometry,
    const FSlateRect& MyCullingRect,
    FSlateWindowElementList& OutDrawElements,
    int32 LayerId,
    const FWidgetStyle& InWidgetStyle,
    bool bParentEnabled
) const
{
    // Base LayerId
    int32 CurrentLayer = LayerId;

    // Get the canvas size
    FVector2D CanvasSize = AllottedGeometry.GetLocalSize();

    // Scale points to fit the canvas
    if (DataPoints.Num() > 1)
    {
        for (int32 i = 0; i < DataPoints.Num() - 1; i++)
        {
            FVector2D StartPoint = DataPoints[i] * CanvasSize;
            FVector2D EndPoint = DataPoints[i + 1] * CanvasSize;

            FSlateDrawElement::MakeLines(
                OutDrawElements,
                CurrentLayer,
                AllottedGeometry.ToPaintGeometry(),
                { StartPoint, EndPoint },
                ESlateDrawEffect::None,
                FLinearColor::Red, // Line Color
                true,              // Anti-aliasing
                3.0f               // Line Thickness
            );
        }
    }

    return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, CurrentLayer, InWidgetStyle, bParentEnabled);
}