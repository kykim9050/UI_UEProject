#include "RadarChartItemsWidget.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/RadarChartItemsWidget.h"

void URadarChartItemsWidget::SetItems(const TArray<FText>& itemNames)
{
	// mItemNames ¥Î¿‘
	mItemNames = itemNames;

	Invalidate(EInvalidateWidget::Paint);
}

int32 URadarChartItemsWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}
