// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Industry/IndustryDisasterChartWidget.h"
#include "Base/RadarChartWidget.h"
#include "Base/RadarChartItemsWidget.h"

void UIndustryDisasterChartWidget::InitItems(const int32 max, const TArray<FText>& itemNames, const TArray<int32>& datas)
{
	mRadarChart->GetRadarChartItemsWidget()->SetItems(itemNames);
	mRadarChart->SetDatas(max, datas);
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
