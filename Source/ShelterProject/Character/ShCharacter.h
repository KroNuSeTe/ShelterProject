// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "ShCharacterBase.h"
#include "ShCharacter.generated.h"

UCLASS()
class SHELTERPROJECT_API AShCharacter : public AShCharacterBase
{
	GENERATED_BODY()

public:
	AShCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
