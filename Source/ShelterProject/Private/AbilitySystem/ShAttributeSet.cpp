// Copyright KroNus Games 2025

#include "Public/AbilitySystem/ShAttributeSet.h"

#include "Net/UnrealNetwork.h"

UShAttributeSet::UShAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);

	InitStamina(60.f);
	InitMaxStamina(60.f);

	InitMorale(100.f);
	InitMaxMorale(100.f);
	
	InitHunger(100.f);
	InitMaxHunger(100.f);
	
	InitThirst(100.f);
	InitMaxThirst(100.f);

	InitStrength(100.f);
	InitMaxStrength(100.f);

	InitTechSkill(100.f);
	InitMaxTechSkill(100.f);

	InitPerception(100.f);
	InitMaxPerception(100.f);

	InitLeadership(100.f);
	InitMaxLeadership(100.f);

	InitStealth(100.f);
	InitMaxStealth(100.f);

	InitMentalStability(100.f);
	InitMaxMentalStability(100.f);

	InitHope(100.f);
	InitMaxHope(100.f);

	InitMachineAffinity(100.f);
	InitMaxMachineAffinity(100.f);

}

void UShAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxStamina, COND_None, REPNOTIFY_Always);

	// Skills / Stats
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxStrength, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, TechSkill, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxTechSkill, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Perception, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxPerception, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Leadership, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxLeadership, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Stealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxStealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MentalStability, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxMentalStability, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Hope, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHope, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MachineAffinity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxMachineAffinity, COND_None, REPNOTIFY_Always);

}

void UShAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Health, OldHealth);	
}

void UShAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Health, OldMaxHealth);
}

void UShAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Stamina, OldStamina);
}

void UShAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxStamina, OldMaxStamina);
}

void UShAttributeSet::OnRep_Morale(const FGameplayAttributeData& OldMorale) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Morale, OldMorale);
}

void UShAttributeSet::OnRep_MaxMorale(const FGameplayAttributeData& OldMaxMorale) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxMorale, OldMaxMorale);
}

void UShAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Hunger, OldHunger);
}

void UShAttributeSet::OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxHunger, OldMaxHunger);
}

void UShAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Thirst, OldThirst);
}

void UShAttributeSet::OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxThirst, OldMaxThirst);
}

// Skills / Stats OnRep
void UShAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Strength, OldStrength);
}

void UShAttributeSet::OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxStrength, OldMaxStrength);
}

void UShAttributeSet::OnRep_TechSkill(const FGameplayAttributeData& OldTechSkill) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, TechSkill, OldTechSkill);
}

void UShAttributeSet::OnRep_MaxTechSkill(const FGameplayAttributeData& OldMaxTechSkill) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxTechSkill, OldMaxTechSkill);
}

void UShAttributeSet::OnRep_Perception(const FGameplayAttributeData& OldPerception) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Perception, OldPerception);
}

void UShAttributeSet::OnRep_MaxPerception(const FGameplayAttributeData& OldMaxPerception) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxPerception, OldMaxPerception);
}

void UShAttributeSet::OnRep_Leadership(const FGameplayAttributeData& OldLeadership) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Leadership, OldLeadership);
}

void UShAttributeSet::OnRep_MaxLeadership(const FGameplayAttributeData& OldMaxLeadership) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxLeadership, OldMaxLeadership);
}

void UShAttributeSet::OnRep_Stealth(const FGameplayAttributeData& OldStealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Stealth, OldStealth);
}

void UShAttributeSet::OnRep_MaxStealth(const FGameplayAttributeData& OldMaxStealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxStealth, OldMaxStealth);
}

void UShAttributeSet::OnRep_MentalStability(const FGameplayAttributeData& OldMentalStability) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MentalStability, OldMentalStability);
}

void UShAttributeSet::OnRep_MaxMentalStability(const FGameplayAttributeData& OldMaxMentalStability) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxMentalStability, OldMaxMentalStability);
}

void UShAttributeSet::OnRep_Hope(const FGameplayAttributeData& OldHope) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Hope, OldHope);
}

void UShAttributeSet::OnRep_MaxHope(const FGameplayAttributeData& OldMaxHope) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxHope, OldMaxHope);
}

void UShAttributeSet::OnRep_MachineAffinity(const FGameplayAttributeData& OldMachineAffinity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MachineAffinity, OldMachineAffinity);
}

void UShAttributeSet::OnRep_MaxMachineAffinity(const FGameplayAttributeData& OldMaxMachineAffinity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxMachineAffinity, OldMaxMachineAffinity);
}

