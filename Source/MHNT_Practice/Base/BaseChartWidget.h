// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseChartWidget.generated.h"

/**
 * 
 */
UCLASS()
class MHNT_PRACTICE_API UBaseChartWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    void SetGraphData(const TArray<FVector2D>& InDataPoints);

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
    ) const override
    {
        return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
    }

    /// <summary>
    /// ĵ������ �߽���ǥ�� �̵��ϱ� ���� �ʿ��� ������ ������ ���
    /// </summary>
    /// <param name="canvasSize"></param>
    /// <returns></returns>
    virtual const FVector2D findCanvasCenterOffset(const FVector2D& canvasSize) const;

    /// <summary>
    /// �־��� ������� ���� ū ���簢������ ĵ���� ������ ��ȯ
    /// </summary>
    /// <param name="canvasSize"></param>
    /// <returns></returns>
    const FVector2D convertCanvasSizeSquare(const FVector2D& canvasSize) const;
    
    /// <summary>
    /// ���� �ٽ� �׸���
    /// </summary>
    void updateScreen();
private:

protected:
    // Data points for the graph
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph", meta = (AllowprivateAccess = "true"))
    TArray<FVector2D> mDataPoints;
  
private:
};
