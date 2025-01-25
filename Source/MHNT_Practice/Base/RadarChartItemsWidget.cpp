#include "RadarChartItemsWidget.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/RadarChartItemsWidget.h"

void URadarChartItemsWidget::SetItems(const TArray<FText>& itemNames)
{
	// mItemNames 대입
	mItemNames = itemNames;

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames 항목을 토대로 위치 좌표 형성 (Text 코드)
    mDataPoints.Reserve(itemNamesNum);
    for (int32 i = 0; i < itemNamesNum; i++)
    {
        mDataPoints.Add(FVector2D{ 
            StaticCast<double>(i)/ StaticCast<double>(itemNamesNum),
            StaticCast<double>(i)/ StaticCast<double>(itemNamesNum) });
    }

	Invalidate(EInvalidateWidget::Paint);
}

int32 URadarChartItemsWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    // Base LayerId
    int32 currentLayer = LayerId;

    FVector2D canvasSize = AllottedGeometry.GetLocalSize();
    FVector2D canvasOffset = findCanvasCenterOffset(canvasSize);
    // 캔버스의 세로, 가로 중 최소 값으로 통일
    canvasSize = convertCanvasSizeSquare(canvasSize);

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames 텍스트 요소 화면에 표현
    if (itemNamesNum > 0)
    {
        int32 itemIdx = 0;

        for (const FVector2D& Point : mDataPoints)
        {
            FVector2D drawPosition = Point * canvasSize + canvasOffset;
            FVector2D drawSize(20.0f, 20.0f);
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
