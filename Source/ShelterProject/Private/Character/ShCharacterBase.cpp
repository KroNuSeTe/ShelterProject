// Copyright KroNus Games 2025

#include "Public/Character/ShCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/ShAbilitySystemComponent.h"
#include "Player/Sh_PlayerState.h"


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

void AShCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AShCharacterBase::InitializeDefaultAttributes() const
{
	const int32 PlayerLevel = GetPlayerState<ASh_PlayerState>()->GetPlayerLevel();
	ApplyEffectToSelf(DefaultPrimaryAttributes, PlayerLevel);
	ApplyEffectToSelf(DefaultSecondaryAttributes, PlayerLevel);
	ApplyEffectToSelf(DefaultVitalAttributes, PlayerLevel);
}

void AShCharacterBase::AddCharacterAbilities()
{
	UShAbilitySystemComponent* ShASC = CastChecked<UShAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	ShASC->AddCharacterAbilities(StartupAbilities);	
}

