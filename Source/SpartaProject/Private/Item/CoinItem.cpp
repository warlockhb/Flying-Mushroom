// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/CoinItem.h"

#include "World/MushroomGameState.h"


// Sets default values
ACoinItem::ACoinItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointValue = 0;
	ItemType = "DefaultCoin";
}

// Called when the game starts or when spawned
void ACoinItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoinItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = Activator->GetWorld())
		{
			if (AMushroomGameState* GameState = World->GetGameState<AMushroomGameState>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}
		
		DestroyItem();
	}
}

// Called every frame
void ACoinItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

