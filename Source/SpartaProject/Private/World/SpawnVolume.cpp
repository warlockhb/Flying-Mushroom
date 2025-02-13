// Fill out your copyright notice in the Description page of Project Settings.


#include "World/SpawnVolume.h"
#include "Components/BoxComponent.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	SpawnArea->SetupAttachment(Scene);

	ItemDataTable = nullptr;
	
	
}

AActor* ASpawnVolume::SpawnRandomItem()
{
	if (FItemSpawnRow* SelectedRow = GetRandomItem())
	{
		if (UClass* ActualClass = SelectedRow->ItemClass.Get())
		{
			return SpawnItem(ActualClass);
		}
	}
	
	return nullptr;
}

AActor* ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	if (!ItemClass) return nullptr;

	GEngine->AddOnScreenDebugMessage(
		-1,
		2.0f,
		FColor::Red,
		FString::Printf(TEXT("Spawing")));				
	
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>
	(
		ItemClass,
		GetRandomPointVolume(),
		FRotator::ZeroRotator
	);
	
	return SpawnedActor;
}

FVector ASpawnVolume::GetRandomPointVolume() const
{
	FVector BoxExtent = SpawnArea->GetScaledBoxExtent();
	FVector BoxOrigin = SpawnArea->GetComponentLocation();

	FVector RandomRange = FVector(FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
								  FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
								  FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z));

	return BoxOrigin + RandomRange;
}

FItemSpawnRow* ASpawnVolume::GetRandomItem() const
{
	if (!ItemDataTable) return nullptr;

	TArray<FItemSpawnRow*> AllRow;
	static const FString ContextString(TEXT("ItemSpawnContext"));
	ItemDataTable->GetAllRows(ContextString, AllRow);

	if (AllRow.IsEmpty()) return nullptr;

	float TotalChance = 0.0f;
	for (FItemSpawnRow* Row : AllRow)
	{
		if (Row)
		{
			TotalChance += Row->SpawnChance;
		}
	}

	const float RandValue = FMath::FRandRange(0, TotalChance);
	float AccumulatedChance = 0.0f;
	
	for (FItemSpawnRow* Row : AllRow)
	{
		AccumulatedChance += Row->SpawnChance;
		if (AccumulatedChance >= RandValue)
		{
			return Row;
		}
	}

	return nullptr;
}
