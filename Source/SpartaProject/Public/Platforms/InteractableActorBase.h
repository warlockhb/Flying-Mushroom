// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "InteractableActorBase.generated.h"

UCLASS()
class SPARTAPROJECT_API AInteractableActorBase : public AActor
{
	friend class PlayerMushroom;
	GENERATED_BODY()
protected:
	AInteractableActorBase();

	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	// 시간 변수
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Time")
	float ElapsedTime = 0.0f;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Time")
	float UpdateCheckTime = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float UpdateCheckFrequency = 0.05f;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Time")
	float LocationAlpha;

	// 타이머 변수
	// 타이머 보단 왕복 주기로 하는게 낫다고 판단
	// UPROPERTY()
	// FTimerHandle TimerHandle;
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Time")
	int CurrentCycle = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	int InteractCycle = 3;
	
	// 컴포넌트 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractableActor")
	UBoxComponent* InteractableCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractableActor")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractableActor")
	UMaterial* EffectMaterial;

	UPROPERTY()
	bool bPressedMagic = false;
	

	
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————

	// 플레이 함수
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	// 마법 함수
	virtual void Magic(float DeltaTime);

public:
	// 외부 마법 실행 함수
	void StartMagic();
	void EndMagic();
};
