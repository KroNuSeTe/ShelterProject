// Copyright KroNus Games 2025
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ShAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHELTERPROJECT_API UShAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UShAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
