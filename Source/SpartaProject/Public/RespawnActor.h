#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RespawnActor.generated.h"

UCLASS()
class SPARTAPROJECT_API ARespawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARespawnActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	FTimerHandle DestroyTimerHandle;
	FTimerHandle RespawnTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	float DestroyTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	float RespawnTime;

	FVector InitialSpawnLocation;

	void DestroyActor();

	void RespawnActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
