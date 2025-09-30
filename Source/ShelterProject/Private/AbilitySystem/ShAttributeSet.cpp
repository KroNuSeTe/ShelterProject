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

	InitMobility(10.f);
	
	InitHunger(20.f);
	InitMaxHunger(100.f);
	
	InitThirst(40.f);
	InitMaxThirst(100.f);

	InitFatigue(0.f);
	InitMaxFatigue(100.f);
	
	InitStress(0.f);
	InitMaxStress(100.f);
	
	InitTrauma(0.f);
	InitMaxTrauma(100.f);
	
	InitContamination(0.f);
	InitMaxContamination(100.f);

	InitPowerCore(0.f);
	InitProcessing(0.f);
	InitLoyaltyProtocol(0.f);
	InitUpgradeSlots(0.f);
	

}

void UShAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	// Primary Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Dexterity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Charisma, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Perception, COND_None, REPNOTIFY_Always);

	// Combat Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxArmor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Mobility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Accuracy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, CriticalHitResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxEnergy, COND_None, REPNOTIFY_Always);

	// Regeneration Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, HealthRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, StaminaRegen, COND_None, REPNOTIFY_Always);

	// Survival Stats
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxThirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, Fatigue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxFatigue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, Stress, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxStress, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, Trauma, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxTrauma, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, Contamination, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxContamination, COND_None, REPNOTIFY_Always);

	// Special Attributes - Robot
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, PowerCore, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxPowerCore, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, Processing, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxProcessing, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, LoyaltyProtocol, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, MaxLoyaltyProtocol, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShAttributeSet, UpgradeSlots, COND_None, REPNOTIFY_Always);

	
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
	if (Attribute == GetHungerAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHunger());
	}
	if (Attribute == GetThirstAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxThirst());
	}
	if (Attribute == GetFatigueAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxFatigue());
	}
	if (Attribute == GetStressAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStress());
	}
	if (Attribute == GetTraumaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxTrauma());
	}
	if (Attribute == GetContaminationAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxContamination());
	}
	if (Attribute == GetPowerCoreAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxPowerCore());
	}
	if (Attribute == GetProcessingAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxProcessing());
	}
	if (Attribute == GetLoyaltyProtocolAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxLoyaltyProtocol());
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

	// Clamping Attributes
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}
	if (Data.EvaluatedData.Attribute == GetHungerAttribute())
	{
		SetHunger(FMath::Clamp(GetHunger(), 0.f, GetMaxHunger()));
	}
	if (Data.EvaluatedData.Attribute == GetThirstAttribute())
	{
		SetThirst(FMath::Clamp(GetThirst(), 0.f, GetMaxThirst()));
	}
	if (Data.EvaluatedData.Attribute == GetFatigueAttribute())
	{
		SetFatigue(FMath::Clamp(GetFatigue(), 0.f, GetMaxFatigue()));
	}
	if (Data.EvaluatedData.Attribute == GetStressAttribute())
	{
		SetStress(FMath::Clamp(GetStress(), 0.f, GetMaxStress()));
	}
	if (Data.EvaluatedData.Attribute == GetTraumaAttribute())
	{
		SetTrauma(FMath::Clamp(GetTrauma(), 0.f, GetMaxTrauma()));
	}
	if (Data.EvaluatedData.Attribute == GetContaminationAttribute())
	{
		SetContamination(FMath::Clamp(GetContamination(), 0.f, GetMaxContamination()));
	}
}


// Primary Attributes
void UShAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Strength, OldStrength);
}

void UShAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Intelligence, OldIntelligence);
}

void UShAttributeSet::OnRep_Charisma(const FGameplayAttributeData& OldCharisma) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Charisma, OldCharisma);
}

void UShAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Dexterity, OldDexterity);
}

void UShAttributeSet::OnRep_Perception(const FGameplayAttributeData& OldPerception) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Perception, OldPerception);
}


// Combat Attributes
void UShAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Health, OldHealth);	
}

void UShAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxHealth, OldMaxHealth);
}

void UShAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Armor, OldArmor);
}

void UShAttributeSet::OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxArmor, OldMaxArmor);
}

void UShAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Stamina, OldStamina);
}

void UShAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxStamina, OldMaxStamina);
}

void UShAttributeSet::OnRep_Mobility(const FGameplayAttributeData& OldMobility) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Mobility, OldMobility);
}

void UShAttributeSet::OnRep_Accuracy(const FGameplayAttributeData& OldAccuracy) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Accuracy, OldAccuracy);
}
void UShAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Damage, OldDamage);
}
void UShAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, CriticalHitChance, OldCriticalHitChance);
}
void UShAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, CriticalHitDamage, OldCriticalHitDamage);
}
void UShAttributeSet::OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, CriticalHitResistance, OldCriticalHitResistance);
}
void UShAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, ArmorPenetration, OldArmorPenetration);
}
void UShAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, BlockChance, OldBlockChance);
}

void UShAttributeSet::OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxEnergy, OldMaxEnergy);
}


// Regeneration Attributes
void UShAttributeSet::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, HealthRegen, OldHealthRegen);
}

void UShAttributeSet::OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, StaminaRegen, OldStaminaRegen);
}


// Survival Attributes
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

void UShAttributeSet::OnRep_Fatigue(const FGameplayAttributeData& OldFatigue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Fatigue, OldFatigue);
}

void UShAttributeSet::OnRep_MaxFatigue(const FGameplayAttributeData& OldMaxFatigue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxFatigue, OldMaxFatigue);
}

void UShAttributeSet::OnRep_Stress(const FGameplayAttributeData& OldStress) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Stress, OldStress);
}

void UShAttributeSet::OnRep_MaxStress(const FGameplayAttributeData& OldMaxStress) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxStress, OldMaxStress);
}

void UShAttributeSet::OnRep_Trauma(const FGameplayAttributeData& OldTrauma) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Trauma, OldTrauma);
}

void UShAttributeSet::OnRep_MaxTrauma(const FGameplayAttributeData& OldMaxTrauma) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxTrauma, OldMaxTrauma);
}

void UShAttributeSet::OnRep_Contamination(const FGameplayAttributeData& OldContamination) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Contamination, OldContamination);
}

void UShAttributeSet::OnRep_MaxContamination(const FGameplayAttributeData& OldMaxContamination) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxContamination, OldMaxContamination);
}


// Special Attributes - Robot
void UShAttributeSet::OnRep_PowerCore(const FGameplayAttributeData& OldPowerCore) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, PowerCore, OldPowerCore);
}

void UShAttributeSet::OnRep_MaxPowerCore(const FGameplayAttributeData& OldMaxPowerCore) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxPowerCore, OldMaxPowerCore);
}

void UShAttributeSet::OnRep_Processing(const FGameplayAttributeData& OldProcessing) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, Processing, OldProcessing);
}

void UShAttributeSet::OnRep_MaxProcessing(const FGameplayAttributeData& OldMaxProcessing) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxProcessing, OldMaxProcessing);
}

void UShAttributeSet::OnRep_LoyaltyProtocol(const FGameplayAttributeData& OldLoyaltyProtocol) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, LoyaltyProtocol, OldLoyaltyProtocol);
}

void UShAttributeSet::OnRep_MaxLoyaltyProtocol(const FGameplayAttributeData& OldMaxLoyaltyProtocol) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, MaxLoyaltyProtocol, OldMaxLoyaltyProtocol);
}

void UShAttributeSet::OnRep_UpgradeSlots(const FGameplayAttributeData& OldUpgradeSlots) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShAttributeSet, UpgradeSlots, OldUpgradeSlots);
}



