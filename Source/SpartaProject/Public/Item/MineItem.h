// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "MineItem.generated.h"

/*!
 * 
 */
UCLASS()
class SPARTAPROJECT_API AMineItem : public AItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMineItem();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	float ExplosionDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	float ExplosionRadius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int ExplosionDamage;
	
	FTimerHandle ExplosionTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	USphereComponent* ExplosionCollision;
	
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ActivateItem(AActor* Activator) override;

	void Explode();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
