// Copyright KroNus Games 2025
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ShAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /*AssetTags*/);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHELTERPROJECT_API UShAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();

	FEffectAssetTags EffectAssetTags;	
	
protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec,
		FActiveGameplayEffectHandle ActiveGameplayEffectHandle);
};
