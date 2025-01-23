// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseTextWidget.h"
#include "Components/TextBlock.h"

void UBaseTextWidget::SetTextWithText(const FText& input)
{
	mTextBlock->SetText(input);
}

void UBaseTextWidget::SetJustification(ETextJustify::Type InJustification)
{
	mTextBlock->SetJustification(InJustification);
}

void UBaseTextWidget::SetFont(const FSlateFontInfo& InFontInfo)
{
	mTextBlock->SetFont(InFontInfo);
}

const FSlateFontInfo& UBaseTextWidget::GetFont() const
{
	return mTextBlock->GetFont();
}

void UBaseTextWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (nullptr == mTextBlock)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == mTextBlock)"), __FUNCTION__, __LINE__);
		return;
	}
}
