// Copyright KroNus Games 2025


#include "Sh_PlayerState.h"

#include "Net/UnrealNetwork.h"

ASh_PlayerState::ASh_PlayerState()
{
	NetUpdateFrequency = 100.0f;
}

void ASh_PlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ScrapCollected );
	DOREPLIFETIME(ThisClass, Health );
	DOREPLIFETIME(ThisClass, bIsDowned );
}
