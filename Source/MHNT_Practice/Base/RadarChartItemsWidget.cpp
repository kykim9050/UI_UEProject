#include "RadarChartItemsWidget.h"
// Fill out your copyright notice in the Description page of Project Settings.


void URadarChartItemsWidget::SetItems(const TArray<FText>& itemNames)
{
	// mItemNames ����
	mItemNames = itemNames;

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames �׸��� ���� ��ġ ��ǥ ���� (Text �ڵ�)
    mDataPoints.Reserve(itemNamesNum);

    double radUnit = FMath::DegreesToRadians(360.0 / StaticCast<double>(itemNamesNum));
    for (int32 i = 0; i < itemNamesNum; i++)
    {
        mDataPoints.Add(FVector2D{ 
            FMath::Cos(StaticCast<double>(i) * radUnit),
            FMath::Sin(StaticCast<double>(i) * radUnit)}
            );
    }

	Invalidate(EInvalidateWidget::Paint);
}

int32 URadarChartItemsWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    // Base LayerId
    int32 currentLayer = LayerId;

    FVector2D canvasSize = AllottedGeometry.GetLocalSize();
    // ĵ���� ���� ��� ������ 0,0�� ���¿��� 0.5,0.5�� �߽��� �ǵ��� �̵��ؾ� ��
    FVector2D canvasOffset = findCanvasCenterOffset(canvasSize);
    // drawPosition�� ������ ������
    canvasSize = convertCanvasSizeSquare(canvasSize) / 2.;

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames �ؽ�Ʈ ��� ȭ�鿡 ǥ��
    if (itemNamesNum > 0)
    {
        int32 itemIdx = 0;

        for (const FVector2D& Point : mDataPoints)
        {
            FVector2D drawPosition = Point * canvasSize + canvasOffset;
            FVector2D drawSize(1.0f, 1.0f);
            const FSlateFontInfo fontInfo = FCoreStyle::GetDefaultFontStyle("Regular", mItemTextSize);

            FSlateDrawElement::MakeText(
                OutDrawElements,
                currentLayer,
                AllottedGeometry.ToPaintGeometry(drawPosition, drawSize),
                mItemNames[itemIdx++],
                fontInfo,
                ESlateDrawEffect::None,
                FLinearColor::Gray
            );
        }
    }

	return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, currentLayer, InWidgetStyle, bParentEnabled);
}

const FVector2D URadarChartItemsWidget::findCanvasCenterOffset(const FVector2D& canvasSize) const
{
    FVector2D canvasOffset = canvasSize / 2.;

    return canvasOffset;
}
