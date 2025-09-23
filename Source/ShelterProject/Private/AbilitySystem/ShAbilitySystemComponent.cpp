// Copyright KroNus Games 2025

#include "Public/AbilitySystem/ShAbilitySystemComponent.h"


UShAbilitySystemComponent::UShAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UShAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UShAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

