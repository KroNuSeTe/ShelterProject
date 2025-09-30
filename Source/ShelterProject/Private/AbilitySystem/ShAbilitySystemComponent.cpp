// Copyright KroNus Games 2025

#include "Public/AbilitySystem/ShAbilitySystemComponent.h"


void UShAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UShAbilitySystemComponent::EffectApplied);
}

void UShAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                              const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
