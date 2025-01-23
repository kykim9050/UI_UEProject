// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Industry/Base/BaseIndustryWidget.h"
#include "IndustryTBMChartWidget.generated.h"

/**
 * 
 */
class UVerticalBox;
class UHorizontalBox;
UCLASS()
class MHNT_PRACTICE_API UIndustryTBMChartWidget : public UBaseIndustryWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitYAxis(int32 max, int32 min, int32 interval);

protected:

private:

protected:

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UVerticalBox> mYArea = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHorizontalBox> mXArea = nullptr;

	UPROPERTY(Editanywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> mBaseTextWidgetClass = nullptr;
};
