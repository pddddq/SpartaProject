#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem(); //생성자 - 메모리에 생김, 딱 한번 호출.

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float RotationSpeed;

	//virtual void PostInitializeComponents() override; // 컴포넌트가 완성된 직후 호출, 컴포넌트끼리 데이터 주고받기, 상호작용
	virtual void BeginPlay() override; // 배치(spawn) 직후
	virtual void Tick(float DeltaTime) override; // 매 프레임마다 호출
	//virtual void Destroyed() override; // 삭제 되기 직전에 호출
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override; // 게임 종료, 파괴(Destroyed()), 레벨 전환

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;
};
