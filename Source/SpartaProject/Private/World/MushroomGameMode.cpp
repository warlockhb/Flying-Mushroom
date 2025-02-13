// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaProject/Public/World/MushroomGameMode.h"

#include "SpartaProject/Public/Player/MushroomPlayerController.h"
#include "SpartaProject/Public/Player/PlayerMushroom.h"
#include "World/MushroomGameState.h"

AMushroomGameMode::AMushroomGameMode()
{
	DefaultPawnClass = APlayerMushroom::StaticClass();
	PlayerControllerClass = AMushroomPlayerController::StaticClass();
	GameStateClass = AMushroomGameState::StaticClass();
}
