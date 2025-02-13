// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MushroomGameState.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPROJECT_API AMushroomGameState : public AGameState
{
	GENERATED_BODY()

	AMushroomGameState();

public:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————

	/* 게임 내 획득 점수 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 Score;

	/* 게임 내 스폰된 갯수 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;
	
	FTimerHandle LevelTimerHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelNames;
	
	FTimerHandle HUDTimerHandle;
	
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————

	UFUNCTION(BlueprintCallable, Category = "Level")
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Level")
	void StartLevel();
	UFUNCTION(BlueprintCallable, Category = "Level")
	void EndLevel();

	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnCoinCollected();
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnLevelTimeUp();

	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();


	void UpdateHUD();
	
	// Getter
	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const { return Score; }

	// Setter
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);


};
