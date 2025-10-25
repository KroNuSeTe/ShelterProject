// Copyright KroNus Games 2025


#include "Public/Player/Sh_PlayerState.h"

#include "Net/UnrealNetwork.h"
#include "Public/AbilitySystem/ShAbilitySystemComponent.h"
#include "Public/AbilitySystem/ShAttributeSet.h"


ASh_PlayerState::ASh_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UShAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UShAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.0f);
}

void ASh_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, Level);
}

UAbilitySystemComponent* ASh_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASh_PlayerState::OnRep_Level(int32 OldLevel)
{
	
}
