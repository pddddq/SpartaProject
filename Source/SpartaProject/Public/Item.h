#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem(); //������ - �޸𸮿� ����, �� �ѹ� ȣ��.

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float RotationSpeed;

	//virtual void PostInitializeComponents() override; // ������Ʈ�� �ϼ��� ���� ȣ��, ������Ʈ���� ������ �ְ�ޱ�, ��ȣ�ۿ�
	virtual void BeginPlay() override; // ��ġ(spawn) ����
	virtual void Tick(float DeltaTime) override; // �� �����Ӹ��� ȣ��
	//virtual void Destroyed() override; // ���� �Ǳ� ������ ȣ��
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override; // ���� ����, �ı�(Destroyed()), ���� ��ȯ

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;
};
