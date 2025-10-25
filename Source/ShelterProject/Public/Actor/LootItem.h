// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/ItemInterface.h"
#include "LootItem.generated.h"

UCLASS()
class SHELTERPROJECT_API ALootItem : public AActor, public IItemInterface
{
	GENERATED_BODY()

public:
	ALootItem();
	
	/** Item Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Item Interface */

protected:
	UPROPERTY(EditAnywhere, Category = "Item")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
