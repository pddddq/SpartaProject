#include "HealingItem.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.0f;
	ItemType = "Helaing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	DestroyItem();
}