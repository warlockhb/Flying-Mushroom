// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ItemInterface.h"
#include "ItemBase.generated.h"

UCLASS()
class SPARTAPROJECT_API AItemBase : public AActor, public IItemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemBase();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FName ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item | Component")
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item | Component")
	USphereComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item | Component")
	UStaticMeshComponent* StaticMesh;
	
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

protected:
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;
	virtual void ActivateItem(AActor* Activator) override;

	// 디스트로이 함수
	virtual void DestroyItem();

	// Getter
	virtual FName GetItemType() const override;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
