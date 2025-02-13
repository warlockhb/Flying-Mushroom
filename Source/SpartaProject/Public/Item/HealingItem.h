// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "HealingItem.generated.h"

UCLASS()
class SPARTAPROJECT_API AHealingItem : public AItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealingItem();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int HealAmount;
	
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
