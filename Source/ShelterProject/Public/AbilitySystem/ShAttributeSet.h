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

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Survival Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Survival Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Survival Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Survival Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Morale, Category = "Survival Attributes")
	FGameplayAttributeData Morale;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Morale);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMorale, Category = "Survival Attributes")
	FGameplayAttributeData MaxMorale;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxMorale);

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

	// Skills / Stats
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Skill Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStrength, Category = "Skill Attributes")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxStrength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_TechSkill, Category = "Skill Attributes")
	FGameplayAttributeData TechSkill;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, TechSkill);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxTechSkill, Category = "Skill Attributes")
	FGameplayAttributeData MaxTechSkill;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxTechSkill);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Perception, Category = "Skill Attributes")
	FGameplayAttributeData Perception;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Perception);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxPerception, Category = "Skill Attributes")
	FGameplayAttributeData MaxPerception;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxPerception);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Leadership, Category = "Skill Attributes")
	FGameplayAttributeData Leadership;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Leadership);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxLeadership, Category = "Skill Attributes")
	FGameplayAttributeData MaxLeadership;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxLeadership);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stealth, Category = "Skill Attributes")
	FGameplayAttributeData Stealth;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Stealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStealth, Category = "Skill Attributes")
	FGameplayAttributeData MaxStealth;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxStealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MentalStability, Category = "Mind Attributes")
	FGameplayAttributeData MentalStability;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MentalStability);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMentalStability, Category = "Mind Attributes")
	FGameplayAttributeData MaxMentalStability;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxMentalStability);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Hope, Category = "Mind Attributes")
	FGameplayAttributeData Hope;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Hope);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHope, Category = "Mind Attributes")
	FGameplayAttributeData MaxHope;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxHope);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MachineAffinity, Category = "Skill Attributes")
	FGameplayAttributeData MachineAffinity;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MachineAffinity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMachineAffinity, Category = "Skill Attributes")
	FGameplayAttributeData MaxMachineAffinity;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxMachineAffinity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MachineAffinity, Category = "Skill Attributes")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, Luck);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMachineAffinity, Category = "Skill Attributes")
	FGameplayAttributeData MaxLuck;
	ATTRIBUTE_ACCESSORS(UShAttributeSet, MaxLuck);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	UFUNCTION()
	void OnRep_Morale(const FGameplayAttributeData& OldMorale) const;

	UFUNCTION()
	void OnRep_MaxMorale(const FGameplayAttributeData& OldMaxMorale) const;

	UFUNCTION()
	void OnRep_Hunger(const FGameplayAttributeData& OldHunger) const;

	UFUNCTION()
	void OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger) const;

	UFUNCTION()
	void OnRep_Thirst(const FGameplayAttributeData& OldThirst) const;

	UFUNCTION()
	void OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const;

	UFUNCTION()
	void OnRep_TechSkill(const FGameplayAttributeData& OldTechSkill) const;

	UFUNCTION()
	void OnRep_MaxTechSkill(const FGameplayAttributeData& OldMaxTechSkill) const;

	UFUNCTION()
	void OnRep_Perception(const FGameplayAttributeData& OldPerception) const;

	UFUNCTION()
	void OnRep_MaxPerception(const FGameplayAttributeData& OldMaxPerception) const;

	UFUNCTION()
	void OnRep_Leadership(const FGameplayAttributeData& OldLeadership) const;

	UFUNCTION()
	void OnRep_MaxLeadership(const FGameplayAttributeData& OldMaxLeadership) const;

	UFUNCTION()
	void OnRep_Stealth(const FGameplayAttributeData& OldStealth) const;

	UFUNCTION()
	void OnRep_MaxStealth(const FGameplayAttributeData& OldMaxStealth) const;

	UFUNCTION()
	void OnRep_MentalStability(const FGameplayAttributeData& OldMentalStability) const;

	UFUNCTION()
	void OnRep_MaxMentalStability(const FGameplayAttributeData& OldMaxMentalStability) const;

	UFUNCTION()
	void OnRep_Hope(const FGameplayAttributeData& OldHope) const;

	UFUNCTION()
	void OnRep_MaxHope(const FGameplayAttributeData& OldMaxHope) const;

	UFUNCTION()
	void OnRep_MachineAffinity(const FGameplayAttributeData& OldMachineAffinity) const;

	UFUNCTION()
	void OnRep_MaxMachineAffinity(const FGameplayAttributeData& OldMaxMachineAffinity) const;

	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UFUNCTION()
	void OnRep_MaxLuck(const FGameplayAttributeData& OldMaxLuck) const;


private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
