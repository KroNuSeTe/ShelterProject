// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "Sh_PlayerState.generated.h"

/**
 * Datos de cada jugador, se replican a todos
 * Aquí va lo que pertenece a cada jugador individualmente, y el server lo replica.
 *
 * Vida / Energía de la Persone/Robot.
 * Inventario personal (ej. chatarra, Cristales).
 * Puntuación o progreso personal.
 * Estado especial del jugador (muerto, incapacitado, activo).
 */

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class SHELTERPROJECT_API ASh_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

	
public:
	ASh_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
