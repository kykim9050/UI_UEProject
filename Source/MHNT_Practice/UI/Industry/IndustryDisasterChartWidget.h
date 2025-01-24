// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Industry/Base/BaseIndustryWidget.h"
#include "IndustryDisasterChartWidget.generated.h"

/**
 * 
 */
class URadarChartItemsWidget;
class UBaseRadarChartWidget;
UCLASS()
class MHNT_PRACTICE_API UIndustryDisasterChartWidget : public UBaseIndustryWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitItems(int32 max, int32 interval);

protected:

private:

protected:

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URadarChartItemsWidget> mRadarChartItems = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBaseRadarChartWidget> mRadarChart = nullptr;
};
