// Fill out your copyright notice in the Description page of Project Settings.

#include "SpartaProject/Public/Player/PlayerHornet.h"
#include "EnhancedInputComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "SpartaProject/Public/Player/MushroomPlayerController.h"


// Sets default values
APlayerHornet::APlayerHornet()
{
	// TODO: 인터랙션 구현시 틱 함수 재고
	PrimaryActorTick.bCanEverTick = true;

	// 콜리전 생성
	Collision = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Collision;

	// 화살표 생성
	Arrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetupAttachment(Collision);
	
	// 스켈레탈 메시 생성
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(Collision);

	// 무브먼트 컴포넌트 생성
	// HACK: 임시적으로 일단 무브먼트를 생성했는데, 이게 적성적인 방법인지 탐구
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	
	// 스프링암 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(Collision);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUseCameraLagSubstepping = true;

	// 카메라 생성
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	
	JumpForce = 500.0f;
}

// Called when the game starts or when spawned
void APlayerHornet::BeginPlay()
{
	Super::BeginPlay();
	
	if (Collision)
	{
		Collision->SetSimulatePhysics(true);
		Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
}

// Called every frame
void APlayerHornet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerHornet::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Display, TEXT("Post : Player Controller Setup"));
	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMushroomPlayerController* PlayerController = CastChecked<AMushroomPlayerController>(GetController()))
		{
			UE_LOG(LogTemp, Display, TEXT("Player Controller Setup"));
			// 이동
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction
				(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&APlayerHornet::Move
				);
			}
			

			// 화면 회전
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction
				(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&APlayerHornet::Look
				);
			}

			// 달리기
			if (PlayerController->DashAction)
			{
				EnhancedInput->BindAction
				(
					PlayerController->DashAction,
					ETriggerEvent::Triggered,
					this,
					&APlayerHornet::StartDash
				);
				
				EnhancedInput->BindAction
				(
					PlayerController->DashAction,
					ETriggerEvent::Completed,
					this,
					&APlayerHornet::EndDash
				);
			}
		}
	}
}

// Input Action
void APlayerHornet::Move(const FInputActionValue& Input)
{
	if (not Controller) return;

	const FVector2D MoveInput = Input.Get<FVector2D>();
	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();
	
	// X
	if (not FMath::IsNearlyZero(MoveInput.X))
		AddMovementInput(ForwardVector, MoveInput.X);
	
	// Y
	if (not FMath::IsNearlyZero(MoveInput.Y))
		AddMovementInput(RightVector, MoveInput.Y);
}







void APlayerHornet::Look(const FInputActionValue& Input)
{
	
}


void APlayerHornet::StartDash(const FInputActionValue& Input)
{
	
}


void APlayerHornet::EndDash(const FInputActionValue& Input)
{
	
}
