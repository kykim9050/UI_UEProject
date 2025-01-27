// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseRadarChartWidget.h"
#include "RadarChartWidget.generated.h"

/**
 * 
 */
class URadarChartItemsWidget;
UCLASS()
class MHNT_PRACTICE_API URadarChartWidget : public UBaseRadarChartWidget
{
	GENERATED_BODY()
public:
    void SetItems(const TArray<FText>& itemNames);

protected:
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
    void NativeConstruct() override;

private:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
    TObjectPtr<URadarChartItemsWidget> mRadarChartItems = nullptr;
};
