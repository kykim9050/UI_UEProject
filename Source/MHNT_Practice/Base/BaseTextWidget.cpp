// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseTextWidget.h"
#include "Components/TextBlock.h"

void UBaseTextWidget::SetTextWithText(const FText& input)
{
	// �𸮾��� assert�� mTextBlock�� nullptr���� Ȯ��
	if (mTextBlock)
	{
		mTextBlock->SetText(input);
	}
}
