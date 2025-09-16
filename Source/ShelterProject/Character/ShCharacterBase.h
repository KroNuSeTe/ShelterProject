// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShCharacterBase.generated.h"

UCLASS(Abstract)
class SHELTERPROJECT_API AShCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	AShCharacterBase();

protected:
	virtual void BeginPlay() override;

};
