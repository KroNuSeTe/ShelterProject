// Copyright KroNus Games 2025

#include "Public/AbilitySystem/ShAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "ShGameplayTags.h"

UShAttributeSet::UShAttributeSet()
{
	// Primary Attributes
	TagsToAttributes.Add(ShGameplayTags::Attributes::Primary::Strength, GetStrengthAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Primary::Toughness, GetToughnessAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Primary::Dexterity, GetDexterityAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Primary::Intelligence, GetIntelligenceAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Primary::Charisma, GetCharismaAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Primary::Perception, GetPerceptionAttribute);

	// Secondary Attributes
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Health, GetHealthAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxHealth, GetMaxHealthAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Armor, GetArmorAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxArmor, GetMaxArmorAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Stamina, GetStaminaAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxStamina, GetMaxStaminaAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::PowerCore, GetPowerCoreAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxPowerCore, GetMaxPowerCoreAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Mobility, GetMobilityAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxMobility, GetMaxMobilityAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Damage, GetDamageAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::CriticalChance, GetCriticalChanceAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::CriticalDamage, GetCriticalDamageAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::HealthRegen, GetHealthRegenAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::StaminaRegen, GetStaminaRegenAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::PowerRegen, GetPowerRegenAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Hunger, GetHungerAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxHunger, GetMaxHungerAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Thirst, GetThirstAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxThirst, GetMaxThirstAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Fatigue, GetFatigueAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxFatigue, GetMaxFatigueAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Stress, GetStressAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxStress, GetMaxStressAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Contamination, GetContaminationAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxContamination, GetMaxContaminationAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::Processing, GetProcessingAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxProcessing, GetMaxProcessingAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::LoyaltyProtocol, GetLoyaltyProtocolAttribute);
	TagsToAttributes.Add(ShGameplayTags::Attributes::Secondary::MaxLoyaltyProtocol, GetMaxLoyaltyProtocolAttribute);
	
	
	
	Hunger = 80.f;
	Thirst = 50.f;
}

void UShAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	// Primary Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Toughness, COND_None, REPNOTIFY_Always);
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
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, PowerCore, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxPowerCore, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Mobility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, CriticalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, HealthRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, StaminaRegen, COND_None, REPNOTIFY_Always);

	// Survival Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxThirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Fatigue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxFatigue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Stress, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxStress, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Contamination, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxContamination, COND_None, REPNOTIFY_Always);

	// Special Attributes - Robot
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Processing, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxProcessing, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, LoyaltyProtocol, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxLoyaltyProtocol, COND_None, REPNOTIFY_Always);

	
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

void UShAttributeSet::OnRep_Toughness(const FGameplayAttributeData& OldToughness) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Toughness, OldToughness);
}

void UShAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Dexterity, OldDexterity);
}

void UShAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Intelligence, OldIntelligence);
}

void UShAttributeSet::OnRep_Charisma(const FGameplayAttributeData& OldCharisma) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Charisma, OldCharisma);
}

void UShAttributeSet::OnRep_Perception(const FGameplayAttributeData& OldPerception) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Perception, OldPerception);
}


// Combat Attributes
void UShAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Health, OldHealth);	
}

void UShAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxHealth, OldMaxHealth);
}

void UShAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Armor, OldArmor);
}

void UShAttributeSet::OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxArmor, OldMaxArmor);
}

void UShAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Stamina, OldStamina);
}

void UShAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxStamina, OldMaxStamina);
}

void UShAttributeSet::OnRep_PowerCore(const FGameplayAttributeData& OldPowerCore) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, PowerCore, OldPowerCore);
}

void UShAttributeSet::OnRep_MaxPowerCore(const FGameplayAttributeData& OldMaxPowerCore) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxPowerCore, OldMaxPowerCore);
}

void UShAttributeSet::OnRep_Mobility(const FGameplayAttributeData& OldMobility) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Mobility, OldMobility);
}

void UShAttributeSet::OnRep_MaxMobility(const FGameplayAttributeData& OldMaxMobility) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxMobility, OldMaxMobility);
}

void UShAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Damage, OldDamage);
}

void UShAttributeSet::OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, CriticalChance, OldCriticalChance);
}

void UShAttributeSet::OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, CriticalDamage, OldCriticalDamage);
}

void UShAttributeSet::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, HealthRegen, OldHealthRegen);
}

void UShAttributeSet::OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, StaminaRegen, OldStaminaRegen);
}

void UShAttributeSet::OnRep_PowerRegen(const FGameplayAttributeData& OldPowerRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, PowerRegen, OldPowerRegen);
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
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Fatigue, OldFatigue);
}

void UShAttributeSet::OnRep_MaxFatigue(const FGameplayAttributeData& OldMaxFatigue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxFatigue, OldMaxFatigue);
}

void UShAttributeSet::OnRep_Stress(const FGameplayAttributeData& OldStress) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Stress, OldStress);
}

void UShAttributeSet::OnRep_MaxStress(const FGameplayAttributeData& OldMaxStress) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxStress, OldMaxStress);
}

void UShAttributeSet::OnRep_Contamination(const FGameplayAttributeData& OldContamination) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Contamination, OldContamination);
}

void UShAttributeSet::OnRep_MaxContamination(const FGameplayAttributeData& OldMaxContamination) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxContamination, OldMaxContamination);
}


// Special Attributes - RoboTS
void UShAttributeSet::OnRep_Processing(const FGameplayAttributeData& OldProcessing) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Processing, OldProcessing);
}

void UShAttributeSet::OnRep_MaxProcessing(const FGameplayAttributeData& OldMaxProcessing) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxProcessing, OldMaxProcessing);
}

void UShAttributeSet::OnRep_LoyaltyProtocol(const FGameplayAttributeData& OldLoyaltyProtocol) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, LoyaltyProtocol, OldLoyaltyProtocol);
}

void UShAttributeSet::OnRep_MaxLoyaltyProtocol(const FGameplayAttributeData& OldMaxLoyaltyProtocol) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxLoyaltyProtocol, OldMaxLoyaltyProtocol);
}



