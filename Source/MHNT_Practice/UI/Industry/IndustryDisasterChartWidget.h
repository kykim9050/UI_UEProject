// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Industry/Base/BaseIndustryWidget.h"
#include "IndustryDisasterChartWidget.generated.h"

/**
 * 
 */
class URadarChartWidget;
UCLASS()
class MHNT_PRACTICE_API UIndustryDisasterChartWidget : public UBaseIndustryWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitItems(const int32 max, const int32 interval, const TArray<FText>& itemNames);

protected:

private:

protected:
	void NativeConstruct() override;

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URadarChartWidget> mRadarChart = nullptr;
};
