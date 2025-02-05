﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MushroomPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;

UCLASS()
class SPARTAPROJECT_API AMushroomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMushroomPlayerController();

public:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* InteractAction;

	virtual void BeginPlay() override;
};
