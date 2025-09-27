// Copyright KroNus Games 2025

#include "Public/Character/ShCharacterBase.h"


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

