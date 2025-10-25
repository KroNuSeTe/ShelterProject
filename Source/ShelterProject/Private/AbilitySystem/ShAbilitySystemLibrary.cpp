// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ShAbilitySystemLibrary.h"
#include "GameplayEffect.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Sh_PlayerState.h"
#include "UI/HUD/ShHUD.h"
#include "UI/WidgetController/ShWidgetController.h"

UOverlayWidgetController* UShAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AShHUD* ShHUD = Cast<AShHUD>(PC->GetHUD()))
		{
			ASh_PlayerState* PS = PC->GetPlayerState<ASh_PlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return ShHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UShAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AShHUD* ShHUD = Cast<AShHUD>(PC->GetHUD()))
		{
			ASh_PlayerState* PS = PC->GetPlayerState<ASh_PlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return ShHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
