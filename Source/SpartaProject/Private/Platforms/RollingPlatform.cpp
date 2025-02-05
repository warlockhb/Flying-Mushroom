// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/RollingPlatform.h"

#include "VectorTypes.h"
#include "Chaos/Utilities.h"


// Sets default values
ARollingPlatform::ARollingPlatform() 
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore); // 기본적으로 모두 무시
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

// Called when the game starts or when spawned
void ARollingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	Initialize();
	UE_LOG(LogTemp, Warning, TEXT("%f"), Radius);
	
}

// Called every frame
void ARollingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARollingPlatform::Magic(float DeltaTime)
{
	Super::Magic(DeltaTime);
	
	// 타임 변수 업데이트
	UpdateCheckTime = GetWorld()->GetTimeSeconds();
	ElapsedTime += DeltaTime;

	// 알파값 구하기
	LocationAlpha = ((-1.0f * FMath::Cos(ElapsedTime * RollingSpeed)) + 1.0f) * 0.5f;
	
	// 보간 방식 채택
	// 위치 변경
	FVector NewLocation = FMath::Lerp(OriginLocation, EndLocation, LocationAlpha);

	if (bForwardRolling && FMath::IsNearlyEqual(LocationAlpha,1.0f, 0.01f))
	{
		bForwardRolling = false;	
	}
	if (not bForwardRolling && FMath::IsNearlyEqual(LocationAlpha,0.0f, 0.01f))
	{
		bForwardRolling = true;
		++CurrentCycle;
	}
	
	SetActorLocation(NewLocation);
	
	// 회전 변경
	if (not RadiusDirection.IsZero())
	{
		float RotationVelocity = -1.0f * FMath::Sin(ElapsedTime * RollingSpeed);
		
		FRotator AddRotation = ((RadiusDirection.Rotation() * 4.0f) * (1/Radius)) * RotationVelocity;
        StaticMesh->AddLocalRotation(AddRotation);
	}

}


// 이니셜라이즈
void ARollingPlatform::Initialize()
{
	// 컴포넌트 변수 초기화
	// 박스 바운드 구하기
	FVector Min, Max;
    StaticMesh->GetLocalBounds(Min, Max);

    FVector3d Bound = Max - Min;
	Bound = Bound * StaticMesh->BoundsScale;

	// 유닛 벡터 구하기

	// 반지름 구하기
    Radius = FVector3d::DotProduct(RadiusDirection, Bound) * 0.5f;

	// 원 둘레와 주기 구하기
	Round = 2 * PI * Radius;
	RollingCycle = Distance / Round;

	// -----------------------------------------------------
	// 위치 변수 초기화
	OriginLocation = GetActorLocation();

	FVector ForwardVector = bUseForward ? GetActorForwardVector() : FVector(0);
	FVector RightVector =  bUseRight ? GetActorRightVector() : FVector(0);
	FVector UpVector = bUseUp ? GetActorUpVector() : FVector(0);

	FinalDirection = (ForwardVector + RightVector + UpVector).GetSafeNormal();
	EndLocation = OriginLocation + (FinalDirection * Distance);
}



