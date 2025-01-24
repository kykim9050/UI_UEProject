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

    // Get the canvas size
    FVector2D canvasSize = AllottedGeometry.GetLocalSize();

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames 텍스트 요소 화면에 표현
    if (itemNamesNum > 0)
    {
        int32 itemIdx = 0;

        for (const FVector2D& Point : mDataPoints)
        {
            FVector2D drawPosition = Point * canvasSize;
            FVector2D drawSize(20.0f, 20.0f);
            const FSlateFontInfo fontInfo = FCoreStyle::GetDefaultFontStyle("Regular", 24);

            FSlateDrawElement::MakeText(
                OutDrawElements,
                LayerId,
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
