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
	OnMoraleChanged.Broadcast(ShAttributeSet->GetMorale());
	OnMaxMoraleChanged.Broadcast(ShAttributeSet->GetMaxMorale());
	OnHungerChanged.Broadcast(ShAttributeSet->GetHunger());
	OnMaxHungerChanged.Broadcast(ShAttributeSet->GetMaxHunger());
	OnThirstChanged.Broadcast(ShAttributeSet->GetThirst());
	OnMaxThirstChanged.Broadcast(ShAttributeSet->GetMaxThirst());
	OnStrengthChanged.Broadcast(ShAttributeSet->GetStrength());
	OnMaxStrengthChanged.Broadcast(ShAttributeSet->GetMaxStrength());
	OnTechSkillChanged.Broadcast(ShAttributeSet->GetTechSkill());
	OnMaxTechSkillChanged.Broadcast(ShAttributeSet->GetMaxTechSkill());
	OnPerceptionChanged.Broadcast(ShAttributeSet->GetPerception());
	OnMaxPerceptionChanged.Broadcast(ShAttributeSet->GetMaxPerception());
	OnLeadershipChanged.Broadcast(ShAttributeSet->GetLeadership());
	OnMaxLeadershipChanged.Broadcast(ShAttributeSet->GetMaxLeadership());	
	OnStealthChanged.Broadcast(ShAttributeSet->GetStealth());
	OnMaxStealthChanged.Broadcast(ShAttributeSet->GetMaxStealth());
	OnMentalStabilityChanged.Broadcast(ShAttributeSet->GetMentalStability());
	OnMaxMentalStabilityChanged.Broadcast(ShAttributeSet->GetMaxMentalStability());
	OnHopeChanged.Broadcast(ShAttributeSet->GetHope());
	OnMaxHopeChanged.Broadcast(ShAttributeSet->GetMaxHope());
	OnMachineAffinityChanged.Broadcast(ShAttributeSet->GetMachineAffinity());
	OnMaxMachineAffinityChanged.Broadcast(ShAttributeSet->GetMaxMachineAffinity());
	OnLuckChanged.Broadcast(ShAttributeSet->GetLuck());
	OnMaxLuckChanged.Broadcast(ShAttributeSet->GetMaxLuck());
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

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMoraleAttribute()).AddUObject(this, &UOverlayWidgetController::MoraleChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxMoraleAttribute()).AddUObject(this, &UOverlayWidgetController::MaxMoraleChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetHungerAttribute()).AddUObject(this, &UOverlayWidgetController::HungerChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxHungerAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHungerChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetThirstAttribute()).AddUObject(this, &UOverlayWidgetController::ThirstChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxThirstAttribute()).AddUObject(this, &UOverlayWidgetController::MaxThirstChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetStrengthAttribute()).AddUObject(this, &UOverlayWidgetController::StrengthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxStrengthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStrengthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetTechSkillAttribute()).AddUObject(this, &UOverlayWidgetController::TechSkillChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxTechSkillAttribute()).AddUObject(this, &UOverlayWidgetController::MaxTechSkillChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetPerceptionAttribute()).AddUObject(this, &UOverlayWidgetController::PerceptionChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxPerceptionAttribute()).AddUObject(this, &UOverlayWidgetController::MaxPerceptionChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetLeadershipAttribute()).AddUObject(this, &UOverlayWidgetController::LeadershipChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxLeadershipAttribute()).AddUObject(this, &UOverlayWidgetController::MaxLeadershipChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetStealthAttribute()).AddUObject(this, &UOverlayWidgetController::StealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxStealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMentalStabilityAttribute()).AddUObject(this, &UOverlayWidgetController::MentalStabilityChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxMentalStabilityAttribute()).AddUObject(this, &UOverlayWidgetController::MaxMentalStabilityChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetHopeAttribute()).AddUObject(this, &UOverlayWidgetController::HopeChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxHopeAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHopeChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMachineAffinityAttribute()).AddUObject(this, &UOverlayWidgetController::MachineAffinityChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxMachineAffinityAttribute()).AddUObject(this, &UOverlayWidgetController::MaxMachineAffinityChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetLuckAttribute()).AddUObject(this, &UOverlayWidgetController::LuckChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ShAttributeSet->GetMaxLuckAttribute()).AddUObject(this, &UOverlayWidgetController::MaxLuckChanged);
	
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

void UOverlayWidgetController::MoraleChanged(const FOnAttributeChangeData& Data) const
{
	OnMoraleChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxMoraleChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxMoraleChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::HungerChanged(const FOnAttributeChangeData& Data) const
{
	OnHungerChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHungerChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHungerChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ThirstChanged(const FOnAttributeChangeData& Data) const
{
	OnThirstChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxThirstChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxThirstChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StrengthChanged(const FOnAttributeChangeData& Data) const
{
	OnStrengthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStrengthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStrengthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::TechSkillChanged(const FOnAttributeChangeData& Data) const
{
	OnTechSkillChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxTechSkillChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxTechSkillChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::PerceptionChanged(const FOnAttributeChangeData& Data) const
{
	OnPerceptionChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxPerceptionChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxPerceptionChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::LeadershipChanged(const FOnAttributeChangeData& Data) const
{
	OnLeadershipChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxLeadershipChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxLeadershipChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StealthChanged(const FOnAttributeChangeData& Data) const
{
	OnStealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MentalStabilityChanged(const FOnAttributeChangeData& Data) const
{
	OnMentalStabilityChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxMentalStabilityChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxMentalStabilityChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::HopeChanged(const FOnAttributeChangeData& Data) const
{
	OnHopeChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHopeChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHopeChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MachineAffinityChanged(const FOnAttributeChangeData& Data) const
{
	OnMachineAffinityChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxMachineAffinityChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxMachineAffinityChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::LuckChanged(const FOnAttributeChangeData& Data) const
{
	OnLuckChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxLuckChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxLuckChanged.Broadcast(Data.NewValue);
}


