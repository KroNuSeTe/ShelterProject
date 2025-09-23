// Copyright KroNus Games 2025


#include "Public/Game/Sh_GameState.h"

#include "Net/UnrealNetwork.h"

void ASh_GameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, CurrentWave);
	DOREPLIFETIME(ThisClass, TimeUntilNextWave);
	DOREPLIFETIME(ThisClass, GlobalTemperature);
}
