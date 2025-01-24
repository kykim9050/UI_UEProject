// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MHNT_PRACTICE_API IChartInterface
{
public:
	/// <summary>
	/// Chart Data¸¦ °»½Å
	/// </summary>
	/// <param name="datas"></param>
	virtual void UpdateData(const TArray<int32>& datas) = 0;
};
