#include "moving.h"

Amoving::Amoving()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 100.0f;
	MoveRange = 500.0f;

	Movement = 1;
}

void Amoving::BeginPlay()
{
	Super::BeginPlay();
	
	StartPosition = GetActorLocation();
}

void Amoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentPosition = GetActorLocation();
	FVector NextPosition = CurrentPosition + FVector(0.0f, Movement * MoveSpeed * DeltaTime, 0.0f);

	float DistanceFromStart = FVector::Dist(StartPosition, NextPosition);

	if (DistanceFromStart >= MoveRange)
	{
		Movement *= -1;
	}

	SetActorLocation(NextPosition);
}

