// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item/ItemSpawnRow.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class SPARTAPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spawining")
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spawining")
	UBoxComponent* SpawnArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawining")
	UDataTable* ItemDataTable;

	UFUNCTION(BlueprintCallable)
	AActor* SpawnRandomItem();

	UFUNCTION(BlueprintCallable)
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass);

	// Getter
	FVector GetRandomPointVolume() const;
	FItemSpawnRow* GetRandomItem() const;
};
