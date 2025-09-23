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
	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;
	
protected:
	virtual void BeginPlay() override;

private:
	void InitAbilityActorInfo();
};
