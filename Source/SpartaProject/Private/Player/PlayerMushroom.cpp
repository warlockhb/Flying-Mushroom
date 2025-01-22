// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaProject/Public/Player/PlayerMushroom.h"

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
APlayerMushroom::APlayerMushroom()
{
	// TODO: 인터랙션 구현시 틱 함수 재고
	// PrimaryActorTick.bCanEverTick = true;

	// 콜리전 생성
	Collision = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Collision->SetupAttachment(RootComponent);

	// 화살표 생성
	Arrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetupAttachment(Collision);
	
	// 스켈레탈 메시 생성
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(Collision);
	
	// 무브먼트 컴포넌트 생성
	MovementComponent = CreateDefaultSubobject<UCharacterMovementComponent>("MovementComponent");

	// 카메라 생성
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	// 스프링암 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	
}

// Called when the game starts or when spawned
void APlayerMushroom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerMushroom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerMushroom::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

