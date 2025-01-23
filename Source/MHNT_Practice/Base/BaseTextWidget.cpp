// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseTextWidget.h"
#include "Components/TextBlock.h"

void UBaseTextWidget::SetTextWithText(const FText& input)
{
	// 언리얼의 assert로 mTextBlock이 nullptr인지 확인
	if (mTextBlock)
	{
		mTextBlock->SetText(input);
	}
}
