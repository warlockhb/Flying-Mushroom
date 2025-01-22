// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaProject/Public/World/MushroomGameMode.h"

#include "SpartaProject/Public/Player/PlayerMushroom.h"

AMushroomGameMode::AMushroomGameMode()
{
	DefaultPawnClass=APlayerMushroom::StaticClass();
}
