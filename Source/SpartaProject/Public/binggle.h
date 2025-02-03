#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "binggle.generated.h"

UCLASS()
class SPARTAPROJECT_API Abinggle : public AActor
{
	GENERATED_BODY()
	
public:	
	Abinggle();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
