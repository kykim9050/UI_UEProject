// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseRadarChartWidget.h"
#include "Base/RadarChartItemsWidget.h"

void UBaseRadarChartWidget::SetItems()
{
    mRadarChartItems->SetItems();
}

int32 UBaseRadarChartWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    // Base LayerId
    int32 currentLayer = LayerId;

    // Get the canvas size
    FVector2D canvasSize = AllottedGeometry.GetLocalSize();

    int32 dataPointsNum = mDataPoints.Num();
    // Scale points to fit the canvas
    if (dataPointsNum > 1)
    {
        for (int32 i = 0; i < dataPointsNum; i++)
        {
            FVector2D startPoint = mDataPoints[i] * canvasSize;
            FVector2D endPoint = mDataPoints[(i + 1)% dataPointsNum] * canvasSize;

            FSlateDrawElement::MakeLines(
                OutDrawElements,
                currentLayer,
                AllottedGeometry.ToPaintGeometry(),
                { startPoint, endPoint },
                ESlateDrawEffect::None,
                FLinearColor::Red, // Line Color
                true,              // Anti-aliasing
                3.0f               // Line Thickness
            );
        }
    }

    // ������ ����Ʈ �׸���
    if (dataPointsNum > 0)
    {
        for (const FVector2D& Point : mDataPoints)
        {
            FVector2D drawPosition = Point * canvasSize;

            // ���� ũ��� ���� ����
            FVector2D circleSize(8.0f, 8.0f); // ������ 4.0f
            FSlateBrush circleBrush;
            circleBrush.TintColor = FLinearColor::Green; // ���� ����

            // �� �׸���
            FSlateDrawElement::MakeBox(
                OutDrawElements,
                currentLayer,
                AllottedGeometry.ToPaintGeometry(drawPosition - circleSize / 2.0f, circleSize),
                &circleBrush,
                ESlateDrawEffect::None,
                FLinearColor::Green // ����
            );
        }
    }

    return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, currentLayer, InWidgetStyle, bParentEnabled);
}

void UBaseRadarChartWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (nullptr == mRadarChartItems)
    {
        UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == mRadarChartItems)"), __FUNCTION__, __LINE__);
        return;
    }
}
