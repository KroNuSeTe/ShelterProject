// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
UCLASS()
class SHELTERPROJECT_API ASh_PlayerState : public APlayerState
{
	GENERATED_BODY()

	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 ScrapCollected;

	UPROPERTY(Replicated, BlueprintReadOnly)
	float Health;

	UPROPERTY(Replicated, BlueprintReadOnly)
	bool bIsDowned;
};
