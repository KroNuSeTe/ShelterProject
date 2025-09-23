// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "ShCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "ShEnemy.generated.h"

UCLASS()
class SHELTERPROJECT_API AShEnemy : public AShCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AShEnemy();

	/** Enemy Interface **/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */

protected:
	virtual void BeginPlay() override;

};
