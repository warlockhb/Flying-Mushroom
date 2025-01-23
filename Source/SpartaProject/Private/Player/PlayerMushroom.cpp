// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaProject/Public/Player/PlayerMushroom.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpartaProject/Public/Player/MushroomPlayerController.h"


class AMushroomPlayerController;

// Sets default values
APlayerMushroom::APlayerMushroom()
{
	// TODO: 인터랙션 구현시 틱 함수 재고
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate
	
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	
	// 스프링암 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUseCameraLagSubstepping = true;

	// 카메라 생성
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
	
}

// Called when the game starts or when spawned
void APlayerMushroom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerMushroom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerMushroom::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
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
					&APlayerMushroom::Move
				);
			}

			// 점프
			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction
				(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&APlayerMushroom::StartJump
				);
				
				EnhancedInput->BindAction
				(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&APlayerMushroom::EndJump
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
					&APlayerMushroom::Look
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
					&APlayerMushroom::StartDash
				);
				
				EnhancedInput->BindAction
				(
					PlayerController->DashAction,
					ETriggerEvent::Completed,
					this,
					&APlayerMushroom::EndDash
				);
			}
		}
	}
}

// Input Action
void APlayerMushroom::Move(const FInputActionValue& Input)
{
	if (not Controller) return;

	const FVector2D MoveInput = Input.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotator = Controller->GetControlRotation();
		const FRotator YawRotator(0, Rotator.Yaw, 0);
		
		const FVector ForwardVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
        const FVector RightVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);

		GetActorForwardVector()
        // ForwardVector
        if (not FMath::IsNearlyZero(MoveInput.X))
        	AddMovementInput(ForwardVector, MoveInput.X);
        
        // RightVector
        if (not FMath::IsNearlyZero(MoveInput.Y))
        	AddMovementInput(RightVector, MoveInput.Y);
	}
}


void APlayerMushroom::StartJump(const FInputActionValue& Input)
{
	if (Input.Get<bool>())
		Jump();
}


void APlayerMushroom::EndJump(const FInputActionValue& Input)
{
	if (not Input.Get<bool>())
		StopJumping();
}


void APlayerMushroom::Look(const FInputActionValue& Input)
{
	FVector2D LookInput = Input.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookInput.X);
        AddControllerPitchInput(LookInput.Y);
	}
}


void APlayerMushroom::StartDash(const FInputActionValue& Input)
{
	
}


void APlayerMushroom::EndDash(const FInputActionValue& Input)
{
	
}
