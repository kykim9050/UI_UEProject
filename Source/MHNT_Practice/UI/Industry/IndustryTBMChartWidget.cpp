// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/Industry/IndustryTBMChartWidget.h"
#include "Components/VerticalBox.h"


void UIndustryTBMChartWidget::InitYAxis(int32 max, int32 min, int32 interval)
{
	int32 cnt = StaticCast<int>((max-min) / StaticCast<double>(interval)) + 1;

	for (int32 i = 0; i < cnt; ++i)
	{
		int value = max - interval * i;
		
		int a = 0;
		// vertical box에 Textblock을 생성해서 하나씩 추가
		//YArea.Get()->AddChild();
	}
}