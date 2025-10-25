// Copyright KroNus Games 2025


#include "Public/Character/ShEnemy.h"

#include "Public/ShelterProject.h"
#include "Public/AbilitySystem/ShAbilitySystemComponent.h"
#include "Public/AbilitySystem/ShAttributeSet.h"


AShEnemy::AShEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UShAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UShAttributeSet>("AttributeSet");
}

void AShEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AShEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 AShEnemy::GetPlayerLevel()
{
	return Level;
}

void AShEnemy::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void AShEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UShAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

