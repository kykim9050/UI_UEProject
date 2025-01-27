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
    void SetDatas(const int32 max, const TArray<int32>& datas);

    FORCEINLINE URadarChartItemsWidget* GetRadarChartItemsWidget() const
    {
        return mRadarChartItems.Get();
    }

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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph", meta = (AllowprivateAccess = "true"))
    TArray<int32> mDatas;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
    TObjectPtr<URadarChartItemsWidget> mRadarChartItems = nullptr;

    /// <summary>
    /// 표시할 데이터의 최대 값
    /// </summary>
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph", meta = (AllowprivateAccess = "true"))
    int32 mMaxDataVal = -1;
};
