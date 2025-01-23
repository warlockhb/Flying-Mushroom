// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaProject/Public/Player/MushroomPlayerController.h"
#include "EnhancedInputSubsystems.h"

AMushroomPlayerController::AMushroomPlayerController():
	InputMappingContext(nullptr),
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	DashAction(nullptr)
{
}

void AMushroomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 로컬 플레이어 검사
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		// 향상된 입력 로컬플레이어 시스템 검사
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}
