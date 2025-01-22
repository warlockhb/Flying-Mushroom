// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerMushroom.generated.h"

UCLASS()
class SPARTAPROJECT_API APlayerMushroom : public APawn
{
	GENERATED_BODY()

public:
	APlayerMushroom();
	
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UCapsuleComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	USpringArmComponent* SpringArm;
	
	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————

	// 상호작용 관련 함수
	// TODO: 상호작용 관련되서 데이터 상세화 - 액터 먼저 우선순위
	// 기본적인 플로우 : 상호작용 가능 액터를 찾는다 -> 인터랙션 시작 -> 인터렉션 종료
	// 단순화 시키면, Found와 Interact 만 있어도 무방할 듯 하다.
	// FIXME: 단순화된 환경 구성
	void FoundInteractActor();

	void BeginInteract();
	void EndInteract();

	void Interact();
	
	
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
