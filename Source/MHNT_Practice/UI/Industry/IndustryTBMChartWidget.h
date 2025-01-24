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
class UBaseLineChartWidget;
UCLASS()
class MHNT_PRACTICE_API UIndustryTBMChartWidget : public UBaseIndustryWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitYAxis(int32 max, int32 min, int32 interval);

	UFUNCTION(BlueprintCallable)
	void InitXAxis(const TArray<FText>& xValues);

	/// <summary>
	/// 그래프 데이터 업데이트
	/// </summary>
	/// <param name="datas"></param>
	UFUNCTION(BlueprintCallable)
	void UpdateData(const TArray<int>& datas);

protected:

private:

protected:

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UVerticalBox> mY = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHorizontalBox> mX = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBaseLineChartWidget> mLineChart = nullptr;

	UPROPERTY(Editanywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> mBaseTextWidgetClass = nullptr;

	UPROPERTY()
	float mAxisFontSize = 10.f;

	UPROPERTY()
	FVector2f mDataPosOffset{-1.f, -1.f};

	UPROPERTY()
	int32 mNumX = -1;

	UPROPERTY()
	int32 mNumY = -1;

	UPROPERTY()
	int32 mMaxYValue = -1;
};
