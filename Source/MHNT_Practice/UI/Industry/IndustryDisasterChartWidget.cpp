// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Industry/IndustryDisasterChartWidget.h"

void UIndustryDisasterChartWidget::InitItems(int32 max, int32 interval)
{
	
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
