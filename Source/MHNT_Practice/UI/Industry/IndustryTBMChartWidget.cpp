// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/Industry/IndustryTBMChartWidget.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Base/BaseTextWidget.h"
#include "Base/BaseLineChartWidget.h"

void UIndustryTBMChartWidget::InitYAxis(int32 max, int32 min, int32 interval)
{
	mNumY = StaticCast<int>((max-min) / StaticCast<double>(interval)) + 1;
	mMaxYValue = max;
	mDataPosOffset.Y = 1. / mNumY / 2.;
	mYInterval = interval;

	if (mBaseTextWidgetClass)
	{
		for (int32 i = 0; i < mNumY; ++i)
		{
			int value = max - mYInterval * i;

			// vertical box�� WBP_Textblock�� �����ؼ� �ϳ��� �߰�
			UBaseTextWidget* textBlock = CreateWidget<UBaseTextWidget>(this, mBaseTextWidgetClass);
			// �ؽ�Ʈ �Է�
			textBlock->SetTextWithText(FText::FromString(FString::FromInt(value)));
			textBlock->SetJustification(ETextJustify::Right);
			FSlateFontInfo slateFontInfo{ textBlock->GetFont() };
			slateFontInfo.Size = mAxisFontSize;
			textBlock->SetFont(slateFontInfo);

			UVerticalBoxSlot* newSlot = mY.Get()->AddChildToVerticalBox(textBlock);
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
	mNumX = xValues.Num();
	mDataPosOffset.X = 1. / mNumX / 2.;

	if (mBaseTextWidgetClass)
	{
		for (int32 i = 0; i < mNumX; ++i)
		{
			// horizontal box�� WBP_Textblock�� �����ؼ� �ϳ��� �߰�
			UBaseTextWidget* textBlock = CreateWidget<UBaseTextWidget>(this, mBaseTextWidgetClass);
			// �ؽ�Ʈ �Է�
			textBlock->SetTextWithText(xValues[i]);
			textBlock->SetJustification(ETextJustify::Center);
			FSlateFontInfo slateFontInfo{ textBlock->GetFont() };
			slateFontInfo.Size = mAxisFontSize;
			textBlock->SetFont(slateFontInfo);

			UHorizontalBoxSlot* newSlot = mX.Get()->AddChildToHorizontalBox(textBlock);
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

void UIndustryTBMChartWidget::UpdateData(const TArray<int>& datas)
{
	if (-1.f == mDataPosOffset.X || -1.f == mDataPosOffset.Y)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (-1.f == mDataPosOffset.X || -1.f == mDataPosOffset.Y)"), __FUNCTION__, __LINE__);
		return;
	}

	int32 datasNum = datas.Num();
	if (datasNum > mNumX)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (datas.Num() > mNumX)"), __FUNCTION__, __LINE__);
		return;
	}

	TArray<FVector2D> newDatas;
	newDatas.Reserve(datasNum);

	for (int32 i = 0; i < datasNum; ++i)
	{
		// int�� float ������ ���� (x : 0~1(��~��), y : 0~1(��~�Ʒ�))
		// offset��ŭ ������ �̵� ���� �߰�
		newDatas.Add(FVector2D{ 
			StaticCast<double>(i) / StaticCast<double>(mNumX), 
			StaticCast<double>(mMaxYValue - datas[i]) / StaticCast<double>(mNumY) / StaticCast<double>(mYInterval) });
		newDatas[i] += mDataPosOffset;
	}

	// ���� ��Ʈ �����Ϳ� �ݿ�
	mLineChart->SetGraphData(newDatas);
}

