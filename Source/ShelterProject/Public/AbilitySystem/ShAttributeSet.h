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

// typedef is specific to the FGameplayAttribute() signature, but TStaticFunPtr is generic to any signature chosen
// typedef TBaseStaticDelegateInstance <FGameplayAttribute(),FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;
template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

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
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	
	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;
	
	
	// Primary Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Toughness, Category = "Attributes|Primary")
	FGameplayAttributeData Toughness;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Toughness);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Attributes|Primary")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Dexterity);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Attributes|Primary")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Charisma, Category = "Attributes|Primary")
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Charisma);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Perception, Category = "Attributes|Primary")
	FGameplayAttributeData Perception;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Perception);

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

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PowerCore, Category = "Combat Attributes")
	FGameplayAttributeData PowerCore;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, PowerCore);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxPowerCore, Category = "Combat Attributes")
	FGameplayAttributeData MaxPowerCore;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxPowerCore);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mobility, Category = "Combat Attributes")
	FGameplayAttributeData Mobility;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Mobility);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMobility, Category = "Combat Attributes")
	FGameplayAttributeData MaxMobility;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxMobility);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Damage, Category="Combat Attributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Damage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalChance, Category="Combat Attributes")
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, CriticalChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalDamage, Category="Combat Attributes")
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, CriticalDamage);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegen, Category = "Attributes|Regen")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, HealthRegen)
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaRegen, Category = "Attributes|Regen")
	FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, StaminaRegen)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PowerRegen, Category = "Attributes|Regen")
	FGameplayAttributeData PowerRegen;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, PowerRegen)
	

	// Survival Attributes
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

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Fatigue, Category = "Survival Attributes")
	FGameplayAttributeData Fatigue;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Fatigue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxFatigue, Category = "Survival Attributes")
	FGameplayAttributeData MaxFatigue;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxFatigue);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stress, Category = "Survival Attributes")
	FGameplayAttributeData Stress;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Stress);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStress, Category = "Survival Attributes")
	FGameplayAttributeData MaxStress;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxStress);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Contamination, Category = "Survival Attributes")
	FGameplayAttributeData Contamination;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Contamination);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxContamination, Category = "Survival Attributes")
	FGameplayAttributeData MaxContamination;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxContamination);

	
	// Special Attributes - Robots

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
	

	// Primary Attributes
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Toughness(const FGameplayAttributeData& OldToughness) const;
	
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
	void OnRep_PowerCore(const FGameplayAttributeData& OldPowerCore) const;

	UFUNCTION()
	void OnRep_MaxPowerCore(const FGameplayAttributeData& OldMaxPowerCore) const;

	UFUNCTION()
	void OnRep_Mobility(const FGameplayAttributeData& OldMobility) const;

	UFUNCTION()
	void OnRep_MaxMobility(const FGameplayAttributeData& OldMaxMobility) const;
	
	UFUNCTION()
	void OnRep_Damage(const FGameplayAttributeData& OldDamage) const;

	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const;

	UFUNCTION()
	void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage) const;
	
	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UFUNCTION()
	void OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen) const;

	UFUNCTION()
	void OnRep_PowerRegen(const FGameplayAttributeData& OldPowerRegen) const;
	
	// Survival Attributes
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
	void OnRep_Contamination(const FGameplayAttributeData& OldContamination) const;

	UFUNCTION()
	void OnRep_MaxContamination(const FGameplayAttributeData& OldMaxContamination) const;


	// Special Attributes - Robot
	UFUNCTION()
	void OnRep_Processing(const FGameplayAttributeData& OldProcessing) const;

	UFUNCTION()
	void OnRep_MaxProcessing(const FGameplayAttributeData& OldMaxProcessing) const;

	UFUNCTION()
	void OnRep_LoyaltyProtocol(const FGameplayAttributeData& OldLoyaltyProtocol) const;

	UFUNCTION()
	void OnRep_MaxLoyaltyProtocol(const FGameplayAttributeData& OldMaxLoyaltyProtocol) const;


private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
