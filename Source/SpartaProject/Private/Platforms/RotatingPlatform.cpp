// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/RotatingPlatform.h"


// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	Initialize();
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ARotatingPlatform::Magic(float DeltaTime)
{
	Super::Magic(DeltaTime);
	// 타임 변수 업데이트
	UpdateCheckTime = GetWorld()->GetTimeSeconds();
	ElapsedTime += DeltaTime;

	if (FMath::IsNearlyEqual(RotationTime, ElapsedTime,0.1f))
	{
		ElapsedTime = 0.0f;
		CurrentCycle = InteractCycle;
		return;
	}
	
	if (not RadiusDirection.IsZero())
	{
		FRotator AddRotation = ((RadiusDirection.Rotation() * 4.0f) * (1/Radius) * RotatingSpeed);
		StaticMesh->AddLocalRotation(AddRotation);
	}
}

void ARotatingPlatform::Initialize()
{

	// 컴포넌트 변수 초기화
	// 박스 바운드 구하기
	FVector Min, Max;
	StaticMesh->GetLocalBounds(Min, Max);

	FVector3d Bound = Max - Min;
	Bound = Bound * StaticMesh->BoundsScale;

	Radius = FVector3d::DotProduct(RadiusDirection, Bound) * 0.5f;
}
