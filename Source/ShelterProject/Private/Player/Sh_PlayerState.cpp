// Copyright KroNus Games 2025


#include "Public/Player/Sh_PlayerState.h"

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

UAbilitySystemComponent* ASh_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
