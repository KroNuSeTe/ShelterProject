// Copyright KroNus Games 2025


#include "Public/UI/WidgetController/OverlayWidgetController.h"

#include "AttributeSet.h"
#include "Public/AbilitySystem/ShAttributeSet.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	const UShAttributeSet* ShAttributeSet = CastChecked<UShAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(ShAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(ShAttributeSet->GetMaxHealth());
	OnStaminaChanged.Broadcast(ShAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(ShAttributeSet->GetMaxStamina());
	
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	const UShAttributeSet* ShAttributeSet = CastChecked<UShAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetHealthAttribute()).AddUObject(this,&UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	ShAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);
}
