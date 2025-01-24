// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseChartWidget.h"
#include "BaseLineChartWidget.generated.h"

/**
 * 
 */
UCLASS()
class MHNT_PRACTICE_API UBaseLineChartWidget : public UBaseChartWidget
{
	GENERATED_BODY()
public:

protected:
    // Override OnPaint to draw the graph
    virtual int32 NativePaint(
        const FPaintArgs& Args,
        const FGeometry& AllottedGeometry,
        const FSlateRect& MyCullingRect,
        FSlateWindowElementList& OutDrawElements,
        int32 LayerId,
        const FWidgetStyle& InWidgetStyle,
        bool bParentEnabled
    ) const override;

private:

protected:

private:

};
