#include "RespawnActor.h"

ARespawnActor::ARespawnActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	DestroyTime = 5.0f;
	RespawnTime = 3.0f;
}

void ARespawnActor::BeginPlay()
{
	Super::BeginPlay();
	
	InitialSpawnLocation = GetActorLocation();
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &ARespawnActor::DestroyActor, DestroyTime, false);
}

void ARespawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARespawnActor::DestroyActor()
{
	Destroy();

	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ARespawnActor::RespawnActor, RespawnTime, false);
}

void ARespawnActor::RespawnActor()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	GetWorld()->SpawnActor<ARespawnActor>(GetClass(), InitialSpawnLocation, FRotator::ZeroRotator, SpawnParams);
}

