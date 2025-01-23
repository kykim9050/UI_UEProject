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

			// vertical box�� WBP_Textblock�� �����ؼ� �ϳ��� �߰�
			UBaseTextWidget* textBlock = CreateWidget<UBaseTextWidget>(this, mBaseTextWidgetClass);
			// �ؽ�Ʈ �Է�
			textBlock->SetTextWithText(FText::FromString(FString::FromInt(value)));
			textBlock->SetJustification(ETextJustify::Right);
			FSlateFontInfo slateFontInfo{ textBlock->GetFont() };
			slateFontInfo.Size = mAxisFontSize;
			textBlock->SetFont(slateFontInfo);

			UVerticalBoxSlot* newSlot = mYArea.Get()->AddChildToVerticalBox(textBlock);
			if (newSlot)
			{
				// ������ ȭ�� ������ �°� ä��� & ���� ����
				newSlot->SetSize(ESlateSizeRule::Fill);
				newSlot->SetHorizontalAlignment(HAlign_Right);
				newSlot->SetVerticalAlignment(VAlign_Center);
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
			// horizontal box�� WBP_Textblock�� �����ؼ� �ϳ��� �߰�
			UBaseTextWidget* textBlock = CreateWidget<UBaseTextWidget>(this, mBaseTextWidgetClass);
			// �ؽ�Ʈ �Է�
			textBlock->SetTextWithText(xValues[i]);
			textBlock->SetJustification(ETextJustify::Center);
			FSlateFontInfo slateFontInfo{ textBlock->GetFont() };
			slateFontInfo.Size = mAxisFontSize;
			textBlock->SetFont(slateFontInfo);

			UHorizontalBoxSlot* newSlot = mXArea.Get()->AddChildToHorizontalBox(textBlock);
			if (newSlot)
			{
				// ������ ȭ�� ������ �°� ä��� & ���� ����
				newSlot->SetSize(ESlateSizeRule::Fill);
				newSlot->SetHorizontalAlignment(HAlign_Center);
				newSlot->SetVerticalAlignment(VAlign_Center);
			}
		}
	}
}

