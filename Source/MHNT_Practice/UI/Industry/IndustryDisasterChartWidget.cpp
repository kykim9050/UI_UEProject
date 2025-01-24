// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Industry/IndustryDisasterChartWidget.h"
#include "Base/BaseRadarChartWidget.h"

void UIndustryDisasterChartWidget::InitItems(const int32 max, const int32 interval)
{
	mRadarChart->SetItems();
}

void UIndustryDisasterChartWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (nullptr == mRadarChart)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == mRadarChart)"), __FUNCTION__, __LINE__);
		return;
	}
}
