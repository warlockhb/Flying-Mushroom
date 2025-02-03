// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Platforms/InteractableActorBase.h"
#include "PlayerMushroom.generated.h"

struct FInputActionValue;

USTRUCT()
struct FInteractionData
{
	GENERATED_USTRUCT_BODY()

	FInteractionData() : CurrentInteractable(nullptr), LastInteractionCheckTime(0.0f) {}

	// HACK: 인터랙션 가능 액터로 바꿔도 되는지 추후 확인
	UPROPERTY()
	AInteractableActorBase* CurrentInteractable;

	UPROPERTY()
	float LastInteractionCheckTime;
};


UCLASS()
class SPARTAPROJECT_API APlayerMushroom : public ACharacter
{
	GENERATED_BODY()

protected:
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————
	// 이동 변수
	UPROPERTY()
	FVector2D MoveInputValue;


	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————
    virtual void BeginPlay() override;
	
public:
	APlayerMushroom();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//——————————————————————————————————————————————————————————————————————
	// 프로퍼티 & 변수
	//——————————————————————————————————————————————————————————————————————


	// 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UCameraComponent* Camera;

	
	// 인터랙션 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	float InteractionCheckFrequency;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	float InteractionCheckDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	FTimerHandle TimerHandle_Interaction;
	
	UPROPERTY()
	FInteractionData InteractionData;
	
	

	//——————————————————————————————————————————————————————————————————————
	// 함수
	//——————————————————————————————————————————————————————————————————————

	// 오버라이드 함수

	// 상호작용 관련 함수
	// TODO: 상호작용 관련되서 데이터 상세화 - 액터 먼저 우선순위
	// TODO: 상호작용 입력도 구현 | 상호작용 액터 구현 후
	// 기본적인 플로우 : 상호작용 가능 액터를 찾는다 -> 인터랙션 시작 -> 인터렉션 종료
	// 단순화 시키면, Found와 Interact 만 있어도 무방할 듯 하다.
	// FIXME: 단순화된 환경 구성
	void PerformInteractionCheck();
	
	void FoundInteractableActor();

	void BeginInteract();
	void EndInteract();

	void Interact();

	// 입력 -> 동작 함수
	void Move(const FInputActionValue& Input);



	void StartJump(const FInputActionValue& Input);
	void EndJump(const FInputActionValue& Input);

	// 
	void Look(const FInputActionValue& Input);

	//TODO: 대시 구현
	void StartDash(const FInputActionValue& Input);
	void EndDash(const FInputActionValue& Input);

	// Getter
	UFUNCTION(BlueprintPure)
	FVector2D GetMoveInputValue() const { return MoveInputValue; }
};
