#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moving.generated.h"

UCLASS()
class SPARTAPROJECT_API Amoving : public AActor
{
	GENERATED_BODY()
	
public:	
	Amoving();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveRange;

	FVector StartPosition;

	int32 Movement;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
