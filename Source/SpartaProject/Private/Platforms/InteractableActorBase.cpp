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

	Magic();
}

// 마법 관련 함수
void AInteractableActorBase::Magic()
{
}


void AInteractableActorBase::StartMagic()
{
	// 인터페이스에 따라서 키 입력에 따라 실행
	bPressedMagic = true;
}

void AInteractableActorBase::EndMagic()
{
	// 인터페이스에 따라서 키 입력에 따라 실행
	bPressedMagic = false;
}

