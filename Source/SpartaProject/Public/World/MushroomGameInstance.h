// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MushroomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPROJECT_API UMushroomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	//——————————————————————————————————————————————————————————————————————
	// 생성자 & 소멸자
	//——————————————————————————————————————————————————————————————————————
	UMushroomGameInstance();

	
private:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	// Non-reflected
	
	/**
	 * @brief 총합 점수
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "GameStat"))
	int32 TotalScore;
	
	/**
	 * @brief 현재 레벨 인덱스
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "GameStat"))
	int32 CurrentLevelIndex;

	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// A 함수 그룹

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	// Non-reflected

	// A
	int a;

	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// 오버라이드

	// A 함수 그룹

public:
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// 오버라이드

	// A

	//——————————————————————————————————————————————————————————————————————
	// Get & Set
	//——————————————————————————————————————————————————————————————————————
	// Getter
	int32 GetCurrentLevelIndex() const { return CurrentLevelIndex; }

	int32 GetTotalScore() const { return TotalScore; }

	

	// Setter
	void SetCurrentLevelIndex(int32 Index) { CurrentLevelIndex = Index; }
	
	void AddTotalScore(int32 Amount) { TotalScore += Amount; }
	
	
};
