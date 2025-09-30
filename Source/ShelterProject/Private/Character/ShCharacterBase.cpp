// Copyright KroNus Games 2025

#include "Public/Character/ShCharacterBase.h"

#include "AbilitySystemComponent.h"


AShCharacterBase::AShCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("Weapon_R"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AShCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AShCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShCharacterBase::InitAbilityActorInfo()
{
	
}

void AShCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

