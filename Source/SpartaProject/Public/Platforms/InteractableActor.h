// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class SPARTAPROJECT_API AInteractableActor : public AActor
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned

	
	// Sets default values for this actor's properties
	AInteractableActor();

	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractableActor")
	UBoxComponent* InteractableCollision;

	bool bPressedMagic;
	

	
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————

	// 플레이 함수
	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;

	// 마법 관련 함수
	virtual void Magic();

	void StartMagic();
	void EndMagic();
		
	//

};
