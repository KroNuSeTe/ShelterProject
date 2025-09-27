// Copyright KroNus Games 2025

#include "Public/AbilitySystem/ShAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UShAttributeSet::UShAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);

	InitStamina(10.f);
	InitMaxStamina(60.f);

	InitMorale(100.f);
	InitMaxMorale(100.f);
	
	InitHunger(20.f);
	InitMaxHunger(100.f);
	
	InitThirst(40.f);
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
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Morale, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxMorale, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHunger, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxThirst, COND_None, REPNOTIFY_Always);
	
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

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Luck, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxLuck, COND_None, REPNOTIFY_Always);

}

void UShAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
	if (Attribute == GetMoraleAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMorale());
	}
	if (Attribute == GetHungerAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHunger());
	}
	if (Attribute == GetThirstAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxThirst());
	}

}

void UShAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = causer of the effect, Target = target of the effect (owner of this AS).
	
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UShAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data,Props);
	
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

void UShAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldLuck) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Luck, OldLuck);
}

void UShAttributeSet::OnRep_MaxLuck(const FGameplayAttributeData& OldMaxLuck) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxLuck, OldMaxLuck);
}


