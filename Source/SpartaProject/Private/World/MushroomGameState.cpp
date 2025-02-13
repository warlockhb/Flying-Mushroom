// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public//World/MushroomGameState.h"

#include "Components/TextBlock.h"
#include "Item/CoinItem.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MushroomPlayerController.h"
#include "World/MushroomGameInstance.h"
#include "World/SpawnVolume.h"


AMushroomGameState::AMushroomGameState()
{
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	LevelDuration = 30;
	CurrentLevelIndex = 0;
	MaxLevels = 3;
}

void AMushroomGameState::BeginPlay()
{
	Super::BeginPlay();

	UpdateHUD();
	
	StartLevel();

	GetWorldTimerManager().SetTimer
	(
		HUDTimerHandle,
		this,
		&AMushroomGameState::UpdateHUD,
		0.1f,
		true
	);
	
}

void AMushroomGameState::StartLevel()
{
	UpdateHUD();
	
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UMushroomGameInstance* MushroomGameInstance = Cast<UMushroomGameInstance>(GameInstance);
		if (MushroomGameInstance)
		{
			CurrentLevelIndex = MushroomGameInstance->GetCurrentLevelIndex();
		}
	}
	
	Score = 0;
	CollectedCoinCount = 0;

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawnCount = 40;
	for (int32 i = 0; i < ItemToSpawnCount; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();

				if (SpawnedActor != nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("Spawned Coin Item"));
				}
				
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}
			}
		}
	}

	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AMushroomGameState::OnLevelTimeUp,
		LevelDuration,
		false
		);
	
	UE_LOG(LogTemp, Display, TEXT("Level %d Start, Spawned &d Coins"), CurrentLevelIndex +1, SpawnedCoinCount);

}

void AMushroomGameState::EndLevel()
{
	GetWorldTimerManager().ClearTimer(LevelTimerHandle);

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UMushroomGameInstance* MushroomGameInstance = Cast<UMushroomGameInstance>(GameInstance);
		
		if (MushroomGameInstance)
		{
			CurrentLevelIndex++;
			MushroomGameInstance->SetCurrentLevelIndex(CurrentLevelIndex);
			UE_LOG(LogTemp, Warning, TEXT("Level %d End"), CurrentLevelIndex);
		}
	}
	
	if (CurrentLevelIndex >= MaxLevels)
	{
		OnGameOver();
		return;
	}

	if (LevelNames.IsValidIndex(CurrentLevelIndex))
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelNames[CurrentLevelIndex]);
	}
	else
	{
		OnGameOver();
	}
}

void AMushroomGameState::OnCoinCollected()
{
	CollectedCoinCount++;
	UE_LOG(LogTemp, Display, TEXT("Collected Coins : %d / %d"), CollectedCoinCount, SpawnedCoinCount);

	if (SpawnedCoinCount >= 0 and CollectedCoinCount >= SpawnedCoinCount)
	{
		EndLevel();
	}
}

void AMushroomGameState::OnLevelTimeUp()
{
	
	EndLevel();
}

void AMushroomGameState::OnGameOver()
{
	UpdateHUD();
	UE_LOG(LogTemp, Display, TEXT("Game Over"));

}

void AMushroomGameState::UpdateHUD()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMushroomPlayerController* MushroomPlayerController = Cast<AMushroomPlayerController>(PlayerController))
		{
			if (UUserWidget* HUD = MushroomPlayerController->GetHUDWidget())
			{
				if (UTextBlock* TimeText = Cast<UTextBlock>(HUD->GetWidgetFromName(TEXT("Time"))))
				{
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);

					TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
				}
				
				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUD->GetWidgetFromName(TEXT("Score"))))
				{
					if (UGameInstance* GameInstance = GetGameInstance())
					{
						UMushroomGameInstance* MushroomGameInstance = Cast<UMushroomGameInstance>(GameInstance);
						if (MushroomGameInstance)
						{
							int32 TotalScore = MushroomGameInstance->GetTotalScore();
							ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), TotalScore)));
						}
					}
				}
				
				if (UTextBlock* LevelText = Cast<UTextBlock>(HUD->GetWidgetFromName(TEXT("Level"))))
				{
					if (UGameInstance* GameInstance = GetGameInstance())
					{
						UMushroomGameInstance* MushroomGameInstance = Cast<UMushroomGameInstance>(GameInstance);
						if (MushroomGameInstance)
						{
							int32 LevelIndex = MushroomGameInstance->GetCurrentLevelIndex();
							LevelText->SetText(FText::FromString(FString::Printf(TEXT("Level: %d"), LevelIndex+1)));
						}
					}
				}
			}
		}
	}
}

void AMushroomGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UMushroomGameInstance* MushroomGameInstance = Cast<UMushroomGameInstance>(GameInstance);
		if (MushroomGameInstance)
		{
			MushroomGameInstance->AddTotalScore(Amount);
		}
	}
	
	Score += Amount;
}


