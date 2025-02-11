#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "itemInterface.generated.h"

UINTERFACE(MinimalAPI)
class UitemInterface : public UInterface
{
	GENERATED_BODY()
};

class SPARTAPROJECT_API IitemInterface
{
	GENERATED_BODY()

public:
	virtual void OnItemOverlap(AActor* OverlapActor) = 0;
	virtual void OnItemEndOverlap(AActor* OverlapActor) = 0;
	virtual void ActivateItem(AActor* Activator) = 0;
	virtual FName GetItemType() const = 0;

};
