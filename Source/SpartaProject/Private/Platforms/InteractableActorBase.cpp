// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaProject/Public/Platforms/InteractableActorBase.h"

#include "Components/SphereComponent.h"


// Sets default values
AInteractableActorBase::AInteractableActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractableCollision = CreateDefaultSubobject<UBoxComponent>("InteractableCollision");
	RootComponent = InteractableCollision;

	// 충돌 감지 설정
	InteractableCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	InteractableCollision->SetCollisionObjectType(ECC_WorldDynamic);
	InteractableCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractableCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootComponent);

	EffectMaterial = CreateDefaultSubobject<UMaterial>("EffectMaterial");
}

// Called when the game starts or when spawned
void AInteractableActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPressedMagic)
	{
		if (CurrentCycle < InteractCycle)
		{
			if (GetWorld()->TimeSince(UpdateCheckTime) > UpdateCheckFrequency)
			{
				Magic(DeltaTime);
			}
		}
		if (CurrentCycle == InteractCycle)
		{
			EndMagic();
		}
	}
}

// 마법 관련 함수
void AInteractableActorBase::Magic(float DeltaTime)
{
}


void AInteractableActorBase::StartMagic()
{
	// 마법이 끝나면, 다시 실행 가능
	if (bPressedMagic == false)
	{
		StaticMesh->SetOverlayMaterial(EffectMaterial);
		CurrentCycle = 0;
		bPressedMagic = true;
	}
	// 인터페이스에 따라서 키 입력에 따라 실행
}

void AInteractableActorBase::EndMagic()
{
	// 인터페이스에 따라서 키 입력에 따라 실행
	StaticMesh->SetOverlayMaterial(nullptr);
	bPressedMagic = false;
}

