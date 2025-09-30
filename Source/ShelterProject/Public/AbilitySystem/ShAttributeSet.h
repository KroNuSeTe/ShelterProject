// Copyright KroNus Games 2025
#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ShAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
	
	FEffectProperties() {}
	
	FGameplayEffectContextHandle EffectContextHandle;
	
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
	
};

/**
 * 
 */
UCLASS()
class SHELTERPROJECT_API UShAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UShAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;


	// Primary Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Attributes|Primary")
	FGameplayAttributeData Dexterity;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Attributes|Primary")
	FGameplayAttributeData Intelligence;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Charisma, Category = "Attributes|Primary")
	FGameplayAttributeData Charisma;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Perception, Category = "Attributes|Primary")
	FGameplayAttributeData Perception;

	// Combat Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Combat Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Combat Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Combat Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Armor);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxArmor, Category = "Combat Attributes")
	FGameplayAttributeData MaxArmor;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxArmor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Combat Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Combat Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mobility, Category = "Combat Attributes")
	FGameplayAttributeData Mobility;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Mobility);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Accuracy, Category="Combat Attributes")
	FGameplayAttributeData Accuracy;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Accuracy);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Damage, Category="Combat Attributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Damage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitChance, Category="Combat Attributes")
	FGameplayAttributeData CriticalHitChance; // 0..100 (%)
	ATTRIBUTE_ACCESSORS(UShAttributeSet, CriticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitDamage, Category="Combat Attributes")
	FGameplayAttributeData CriticalHitDamage; // 0..500 (%) bonus sobre daño base
	ATTRIBUTE_ACCESSORS(UShAttributeSet, CriticalHitDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitResistance, Category="Combat Attributes")
	FGameplayAttributeData CriticalHitResistance; // 0..100 (%)
	ATTRIBUTE_ACCESSORS(UShAttributeSet, CriticalHitResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ArmorPenetration, Category="Combat Attributes")
	FGameplayAttributeData ArmorPenetration; // 0..100 (%)
	ATTRIBUTE_ACCESSORS(UShAttributeSet, ArmorPenetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BlockChance, Category="Combat Attributes")
	FGameplayAttributeData BlockChance; // 0..100 (%)
	ATTRIBUTE_ACCESSORS(UShAttributeSet, BlockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxEnergy, Category="Resource Attributes")
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxEnergy);
	

	// Regeneration Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Regen", ReplicatedUsing = OnRep_HealthRegen)
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, HealthRegen)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Regen", ReplicatedUsing = OnRep_StaminaRegen)
	FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, StaminaRegen)
	

	// Survival Stats
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Hunger, Category = "Survival Attributes")
	FGameplayAttributeData Hunger;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Hunger);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHunger, Category = "Survival Attributes")
	FGameplayAttributeData MaxHunger;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxHunger);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Thirst, Category = "Survival Attributes")
	FGameplayAttributeData Thirst;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Thirst);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxThirst, Category = "Survival Attributes")
	FGameplayAttributeData MaxThirst;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxThirst);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Fatigue, Category = "Status Attributes")
	FGameplayAttributeData Fatigue;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Fatigue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxFatigue, Category = "Status Attributes")
	FGameplayAttributeData MaxFatigue;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxFatigue);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stress, Category = "Status Attributes")
	FGameplayAttributeData Stress;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Stress);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStress, Category = "Status Attributes")
	FGameplayAttributeData MaxStress;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxStress);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Trauma, Category = "Status Attributes")
	FGameplayAttributeData Trauma;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Trauma);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxTrauma, Category = "Status Attributes")
	FGameplayAttributeData MaxTrauma;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxTrauma);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Contamination, Category = "Status Attributes")
	FGameplayAttributeData Contamination;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Contamination);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxContamination, Category = "Status Attributes")
	FGameplayAttributeData MaxContamination;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxContamination);

	
	// Special Attributes - Robot
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_PowerCore)
	FGameplayAttributeData PowerCore;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, PowerCore)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_MaxPowerCore)
	FGameplayAttributeData MaxPowerCore;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxPowerCore)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_Processing)
	FGameplayAttributeData Processing;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Processing)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_MaxProcessing)
	FGameplayAttributeData MaxProcessing;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxProcessing)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_LoyaltyProtocol)
	FGameplayAttributeData LoyaltyProtocol;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, LoyaltyProtocol)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_MaxLoyaltyProtocol)
	FGameplayAttributeData MaxLoyaltyProtocol;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxLoyaltyProtocol)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Robot", ReplicatedUsing = OnRep_UpgradeSlots)
	FGameplayAttributeData UpgradeSlots;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, UpgradeSlots)

	

	// Primary Attributes
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;
	
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Charisma(const FGameplayAttributeData& OldCharisma) const;

	UFUNCTION()
	void OnRep_Perception(const FGameplayAttributeData& OldPerception) const;
	
	// Combat Attributes
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	UFUNCTION()
	void OnRep_Mobility(const FGameplayAttributeData& OldMobility) const;

	UFUNCTION()
	void OnRep_Accuracy(const FGameplayAttributeData& OldAccuracy) const;
	
	UFUNCTION()
	void OnRep_Damage(const FGameplayAttributeData& OldDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy) const;

	
	// Regeneration Attributes
	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UFUNCTION()
	void OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen) const;

	
	// Survival Stats
	UFUNCTION()
	void OnRep_Hunger(const FGameplayAttributeData& OldHunger) const;

	UFUNCTION()
	void OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger) const;

	UFUNCTION()
	void OnRep_Thirst(const FGameplayAttributeData& OldThirst) const;

	UFUNCTION()
	void OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst) const;
	
	UFUNCTION()
	void OnRep_Fatigue(const FGameplayAttributeData& OldFatigue) const;

	UFUNCTION()
	void OnRep_MaxFatigue(const FGameplayAttributeData& OldMaxFatigue) const;

	UFUNCTION()
	void OnRep_Stress(const FGameplayAttributeData& OldStress) const;

	UFUNCTION()
	void OnRep_MaxStress(const FGameplayAttributeData& OldMaxStress) const;

	UFUNCTION()
	void OnRep_Trauma(const FGameplayAttributeData& OldTrauma) const;

	UFUNCTION()
	void OnRep_MaxTrauma(const FGameplayAttributeData& OldMaxTrauma) const;

	UFUNCTION()
	void OnRep_Contamination(const FGameplayAttributeData& OldContamination) const;

	UFUNCTION()
	void OnRep_MaxContamination(const FGameplayAttributeData& OldMaxContamination) const;


	// Special Attributes - Robot
	UFUNCTION()
	void OnRep_PowerCore(const FGameplayAttributeData& OldPowerCore) const;

	UFUNCTION()
	void OnRep_MaxPowerCore(const FGameplayAttributeData& OldMaxPowerCore) const;

	UFUNCTION()
	void OnRep_Processing(const FGameplayAttributeData& OldProcessing) const;

	UFUNCTION()
	void OnRep_MaxProcessing(const FGameplayAttributeData& OldMaxProcessing) const;

	UFUNCTION()
	void OnRep_LoyaltyProtocol(const FGameplayAttributeData& OldLoyaltyProtocol) const;

	UFUNCTION()
	void OnRep_MaxLoyaltyProtocol(const FGameplayAttributeData& OldMaxLoyaltyProtocol) const;

	UFUNCTION()
	void OnRep_UpgradeSlots(const FGameplayAttributeData& OldUpgradeSlots) const;

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
