// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/Industry/IndustryTBMChartWidget.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Base/BaseTextWidget.h"

void UIndustryTBMChartWidget::InitYAxis(int32 max, int32 min, int32 interval)
{
	int32 cnt = StaticCast<int>((max-min) / StaticCast<double>(interval)) + 1;

	if (mBaseTextWidgetClass)
	{
		for (int32 i = 0; i < cnt; ++i)
		{
			int value = max - interval * i;

			// vertical box에 WBP_Textblock을 생성해서 하나씩 추가
			UBaseTextWidget* textBlock = CreateWidget<UBaseTextWidget>(this, mBaseTextWidgetClass);
			// 텍스트 입력
			textBlock->SetTextWithText(FText::FromString(FString::FromInt(value)));

			UVerticalBoxSlot* newSlot = mYArea.Get()->AddChildToVerticalBox(textBlock);
			if (newSlot)
			{
				// 슬롯을 화면 비율에 맞게 채우기
				newSlot->SetSize(ESlateSizeRule::Fill);
			}
		}
	}
}

void UIndustryTBMChartWidget::InitXAxis(const TArray<FText>& xValues)
{
	int32 cnt = xValues.Num();

	if (mBaseTextWidgetClass)
	{
		for (int32 i = 0; i < cnt; ++i)
		{
			// horizontal box에 WBP_Textblock을 생성해서 하나씩 추가
			UBaseTextWidget* textBlock = CreateWidget<UBaseTextWidget>(this, mBaseTextWidgetClass);
			// 텍스트 입력
			textBlock->SetTextWithText(xValues[i]);

			UHorizontalBoxSlot* newSlot = mXArea.Get()->AddChildToHorizontalBox(textBlock);
			if (newSlot)
			{
				// 슬롯을 화면 비율에 맞게 채우기
				newSlot->SetSize(ESlateSizeRule::Fill);
			}
		}
	}
}

