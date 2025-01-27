#include "RadarChartItemsWidget.h"
// Fill out your copyright notice in the Description page of Project Settings.
#include "Fonts/FontMeasure.h"

void URadarChartItemsWidget::SetItems(const TArray<FText>& itemNames)
{
	// mItemNames ����
	mItemNames = itemNames;

    convertDataPointsNormal(itemNames.Num());

    updateScreen();
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

        // ��Ʈ ����� �������� �����ϱ� ���� FSlateFontMeasure Ŭ���� ���
        TSharedRef<FSlateFontMeasure> fontMeasure = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();

        for (const FVector2D& Point : mDataPoints)
        {
            FVector2D drawPosition = Point * canvasSize + canvasOffset;
            const FSlateFontInfo fontInfo = FCoreStyle::GetDefaultFontStyle("Regular", mItemTextSize);

            FVector2D calculatedTextSize = fontMeasure->Measure(mItemNames[itemIdx], fontInfo);

            FSlateDrawElement::MakeText(
                OutDrawElements,
                currentLayer,
                // drawPosition �������� �ؽ�Ʈ �߾� ���� 
                AllottedGeometry.ToPaintGeometry(drawPosition - (calculatedTextSize * 0.5), calculatedTextSize),
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
