// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Sh_GameInstance.generated.h"

/**
 * Global, persiste aunque cambies de mapa
 * Poner lo que es del jugador local y debe durar toda la sesión.
 * 
 * Configuración del Usuario (Nombre, Idioma, Opciones Gráficas).
 * Progreso de campaña / guardado (nivel desbloqueado, historia).
 * Opciones de red (IP, si hostea como listen server o se une).
 */
UCLASS()
class SHELTERPROJECT_API USh_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FString PlayerName;

	UPROPERTY(BlueprintReadWrite)
	int32 SavedLevelIndex;
};
