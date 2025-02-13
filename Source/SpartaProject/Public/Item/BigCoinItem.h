﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "BigCoinItem.generated.h"

UCLASS()
class SPARTAPROJECT_API ABigCoinItem : public ACoinItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABigCoinItem();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void ActivateItem(AActor* Activator) override;
};
