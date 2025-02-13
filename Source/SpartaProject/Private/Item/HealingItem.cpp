// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/HealingItem.h"

#include "Player/PlayerMushroom.h"


// Sets default values
AHealingItem::AHealingItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealAmount = 20;
	ItemType = "Healing";
}

// Called when the game starts or when spawned
void AHealingItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (APlayerMushroom* Player = Cast<APlayerMushroom>(Activator))
		{
			Player->AddHealth(HealAmount);
		}
		
		DestroyItem();
	}
}

