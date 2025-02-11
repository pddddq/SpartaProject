#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "itemInterface.h"
#include "BaseItem.generated.h"

UCLASS()
class SPARTAPROJECT_API ABaseItem : public AActor, public IitemInterface
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

protected:
	virtual void OnItemOverlap(AActor* OverlapActor) override;
	virtual void OnItemEndOverlap(AActor* OverlapActor) override;
	virtual void ActivateItem(AActor* Activator) override;
	virtual FName GetItemType() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemType;

	virtual void DestroyItem();
};
