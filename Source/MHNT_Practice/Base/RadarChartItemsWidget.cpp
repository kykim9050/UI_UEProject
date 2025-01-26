#include "RadarChartItemsWidget.h"
// Fill out your copyright notice in the Description page of Project Settings.
#include "Fonts/FontMeasure.h"

void URadarChartItemsWidget::SetItems(const TArray<FText>& itemNames)
{
	// mItemNames 대입
	mItemNames = itemNames;

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames 항목을 토대로 위치 좌표 형성
    // 데이터 수만큼 나누어 일정한 각도 간격
    mDataPoints.Reserve(itemNamesNum);

    double radUnit = FMath::DegreesToRadians(mItemsRoundTotalDegree / StaticCast<double>(itemNamesNum));
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
    // 캔버스 좌측 상단 기준이 0,0인 상태에서 0.5,0.5가 중심이 되도록 이동해야 함
    FVector2D canvasOffset = findCanvasCenterOffset(canvasSize);
    // drawPosition에 곱해질 스케일
    canvasSize = convertCanvasSizeSquare(canvasSize) / 2.;

    int32 itemNamesNum = mItemNames.Num();
    // mItemNames 텍스트 요소 화면에 표현
    if (itemNamesNum > 0)
    {
        int32 itemIdx = 0;

        // 폰트 사이즈를 동적으로 측정하기 위한 FSlateFontMeasure 클래스 사용
        TSharedRef<FSlateFontMeasure> fontMeasure = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();

        for (const FVector2D& Point : mDataPoints)
        {
            FVector2D drawPosition = Point * canvasSize + canvasOffset;
            const FSlateFontInfo fontInfo = FCoreStyle::GetDefaultFontStyle("Regular", mItemTextSize);

            FVector2D calculatedTextSize = fontMeasure->Measure(mItemNames[itemIdx], fontInfo);

            FSlateDrawElement::MakeText(
                OutDrawElements,
                currentLayer,
                // drawPosition 기준으로 텍스트 중앙 정렬 
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
