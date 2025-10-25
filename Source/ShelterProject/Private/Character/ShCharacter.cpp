// Copyright KroNus Games 2025


#include "Public/Character/ShCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/ShAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Public/Player/Sh_PlayerController.h"
#include "Public/Player/Sh_PlayerState.h"
#include "Public/UI/HUD/ShHUD.h"


AShCharacter::AShCharacter()
{	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AShCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AShCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();

	// Add character abilities
	AddCharacterAbilities();
}

int32 AShCharacter::GetPlayerLevel()
{
	const ASh_PlayerState* ShPlayerState = GetPlayerState<ASh_PlayerState>();
	check(ShPlayerState);
	return ShPlayerState->GetPlayerLevel();
}

void AShCharacter::InitAbilityActorInfo()
{
	ASh_PlayerState* ShPlayerState = GetPlayerState<ASh_PlayerState>();
	check(ShPlayerState);
	ShPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ShPlayerState, this);
	Cast<UShAbilitySystemComponent>(ShPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = ShPlayerState->GetAbilitySystemComponent();
	AttributeSet = ShPlayerState->GetAttributeSet();

	if (ASh_PlayerController* ShPlayerController = Cast<ASh_PlayerController>(GetController()))
	{
		if (AShHUD* ShHUD = Cast<AShHUD>(ShPlayerController->GetHUD()))
		{
			ShHUD->InitOverlay(ShPlayerController, ShPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

	InitializeDefaultAttributes();
	
}
