// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/InventoryGameEvents.h"
#include "ShelterGameEventsSubsystem.generated.h"

UCLASS()
class SHELTERPROJECT_API UShelterGameEventsSubsystem : public UGameInstanceSubsystem, public IInventoryGameEvents
{
	GENERATED_BODY()

public:
	// IInventoryGameEvents
	virtual void TriggerOnHealthChanged_Implementation(APlayerController* PC, float NewHealth) override;

	// Registro del provider
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
};
