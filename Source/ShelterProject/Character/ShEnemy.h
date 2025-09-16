// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "ShCharacterBase.h"
#include "ShEnemy.generated.h"

UCLASS()
class SHELTERPROJECT_API AShEnemy : public AShCharacterBase
{
	GENERATED_BODY()

public:
	AShEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
