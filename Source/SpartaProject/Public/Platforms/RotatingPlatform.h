// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActorBase.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API ARotatingPlatform : public AInteractableActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotatingPlatform();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————

	// 회전 변수
	// Visible Only
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float RotationTime = 10.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Rotation")
	FVector RadiusDirection = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Rotation")
	float RotatingSpeed = 100.0f;

	UPROPERTY()
	float Radius;


	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void Magic(float DeltaTime) override;

	void Initialize();

public:
	// Called every frame

};
