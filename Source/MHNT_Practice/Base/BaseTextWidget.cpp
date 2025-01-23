// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseTextWidget.h"
#include "Components/TextBlock.h"

void UBaseTextWidget::SetTextWithText(const FText& input)
{
	if (mTextBlock)
	{
		mTextBlock->SetText(input);
	}
}

void UBaseTextWidget::SetJustification(ETextJustify::Type InJustification)
{
	if (mTextBlock)
	{
		mTextBlock->SetJustification(InJustification);
	}
}
