// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActorBase.h"
#include "RollingPlatform.generated.h"


UCLASS()
class SPARTAPROJECT_API ARollingPlatform : public AInteractableActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARollingPlatform();

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	// 콜리젼
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Collider")
	UBoxComponent* CollisionBox;
	
	// 회전 변수
	// Visible Only
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Rotation")
	float Radius = NULL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Rotation")
	float Round = NULL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Rotation")
	float RollingCycle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Rotation")
	bool bForwardRolling = true;

	// Editable

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Rotation")
	float Distance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Rotation")
	FVector RadiusDirection = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Rotation")
	float RollingSpeed = 100.0f;


	// 위치 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Transforms")
	bool bUseForward = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Transforms")
	bool bUseRight = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic | Transforms")
	bool bUseUp = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Transforms")
	FVector OriginLocation = FVector::ZeroVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Transforms")
	FVector FinalDirection = FVector::ZeroVector;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic | Transforms")
	FVector EndLocation = FVector::ZeroVector;
	
	
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
 