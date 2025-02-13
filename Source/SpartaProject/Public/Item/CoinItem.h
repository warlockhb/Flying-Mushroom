// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "CoinItem.generated.h"

UCLASS()
class SPARTAPROJECT_API ACoinItem : public AItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoinItem();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int PointValue;

	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ActivateItem(AActor* Activator) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
