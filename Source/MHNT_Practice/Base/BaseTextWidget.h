// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseTextWidget.generated.h"

/**
 * 
 */
class UTextBlock;
UCLASS()
class MHNT_PRACTICE_API UBaseTextWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetTextWithText(const FText& input);

	void SetJustification(ETextJustify::Type InJustification);

	void SetFont(const FSlateFontInfo& InFontInfo);
	const FSlateFontInfo& GetFont() const;

protected:
	
private:
	void NativeConstruct() override;

protected:

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTextBlock> mTextBlock = nullptr;
};
