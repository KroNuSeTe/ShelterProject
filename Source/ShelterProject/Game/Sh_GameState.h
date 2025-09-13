// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Sh_GameState.generated.h"

/**
 * Estado de la partida, se replica del server a todos los clientes.
 * Aquí va lo que todos deben ver igual, sin importar cuántos jugadores haya.
 *
 * Día/noche, clima.
 * Recursos globales (ej. cantidad total de carbón en el mapa).
 * Oleadas de enemigos (oleada actual, tiempo hasta la siguiente).
 * Estado general de la base (temperatura, energía disponible).
 */
UCLASS()
class SHELTERPROJECT_API ASh_GameState : public AGameStateBase
{
	GENERATED_BODY()

	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 CurrentWave;

	UPROPERTY(Replicated, BlueprintReadOnly)
	float TimeUntilNextWave;

	UPROPERTY(Replicated, BlueprintReadOnly)
	float GlobalTemperature;
};
