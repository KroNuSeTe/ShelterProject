// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "ShWidgetController.h"
#include "OverlayWidgetController.generated.h"


struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStaminaChangedSignature, float, NewStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxStaminaChangedSignature, float, NewMaxStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnmoraleChangedSignature, float, NewMorale);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxMoraleChangedSignature, float, NewMaxMorale);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHungerChangedSignature, float, NewHunger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHungerChangedSignature, float, NewMaxHunger);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnThirstChangedSignature, float, NewThirst);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxThirstChangedSignature, float, NewMaxThirst);

// Skills / Stats
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStrengthChangedSignature, float, NewStrength);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxStrengthChangedSignature, float, NewMaxStrength);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTechSkillChangedSignature, float, NewTechSkill);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxTechSkillChangedSignature, float, NewMaxTechSkill);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerceptionChangedSignature, float, NewPerception);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxPerceptionChangedSignature, float, NewMaxPerception);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeadershipChangedSignature, float, NewLeadership);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxLeadershipChangedSignature, float, NewMaxLeadership);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStealthChangedSignature, float, NewStealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxStealthChangedSignature, float, NewMaxStealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMentalStabilityChangedSignature, float, NewMentalStability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxMentalStabilityChangedSignature, float, NewMaxMentalStability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHopeChangedSignature, float, NewHope);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHopeChangedSignature, float, NewMaxHope);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMachineAffinityChangedSignature, float, NewMachineAffinity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxMachineAffinityChangedSignature, float, NewMaxMachineAffinity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLuckChangedSignature, float, NewLuck);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxLuckChangedSignature, float, NewMaxLuck);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SHELTERPROJECT_API UOverlayWidgetController : public UShWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallBacksToDependencies() override;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnStaminaChangedSignature OnStaminaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxStaminaChangedSignature OnMaxStaminaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnmoraleChangedSignature OnMoraleChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxMoraleChangedSignature OnMaxMoraleChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHungerChangedSignature OnHungerChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHungerChangedSignature OnMaxHungerChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnThirstChangedSignature OnThirstChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxThirstChangedSignature OnMaxThirstChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnStrengthChangedSignature OnStrengthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxStrengthChangedSignature OnMaxStrengthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnTechSkillChangedSignature OnTechSkillChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxTechSkillChangedSignature OnMaxTechSkillChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnPerceptionChangedSignature OnPerceptionChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxPerceptionChangedSignature OnMaxPerceptionChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnLeadershipChangedSignature OnLeadershipChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxLeadershipChangedSignature OnMaxLeadershipChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnStealthChangedSignature OnStealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxStealthChangedSignature OnMaxStealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMentalStabilityChangedSignature OnMentalStabilityChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxMentalStabilityChangedSignature OnMaxMentalStabilityChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHopeChangedSignature OnHopeChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHopeChangedSignature OnMaxHopeChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMachineAffinityChangedSignature OnMachineAffinityChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxMachineAffinityChangedSignature OnMaxMachineAffinityChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnLuckChangedSignature OnLuckChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxLuckChangedSignature OnMaxLuckChanged;	

protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void StaminaChanged(const FOnAttributeChangeData& Data) const;
	void MaxStaminaChanged(const FOnAttributeChangeData& Data) const;
	void MoraleChanged(const FOnAttributeChangeData& Data) const;
	void MaxMoraleChanged(const FOnAttributeChangeData& Data) const;
	void HungerChanged(const FOnAttributeChangeData& Data) const;
	void MaxHungerChanged(const FOnAttributeChangeData& Data) const;
	void ThirstChanged(const FOnAttributeChangeData& Data) const;
	void MaxThirstChanged(const FOnAttributeChangeData& Data) const;
	void StrengthChanged(const FOnAttributeChangeData& Data) const;
	void MaxStrengthChanged(const FOnAttributeChangeData& Data) const;
	void TechSkillChanged(const FOnAttributeChangeData& Data) const;
	void MaxTechSkillChanged(const FOnAttributeChangeData& Data) const;
	void PerceptionChanged(const FOnAttributeChangeData& Data) const;
	void MaxPerceptionChanged(const FOnAttributeChangeData& Data) const;
	void LeadershipChanged(const FOnAttributeChangeData& Data) const;
	void MaxLeadershipChanged(const FOnAttributeChangeData& Data) const;
	void StealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxStealthChanged(const FOnAttributeChangeData& Data) const;
	void MentalStabilityChanged(const FOnAttributeChangeData& Data) const;
	void MaxMentalStabilityChanged(const FOnAttributeChangeData& Data) const;
	void HopeChanged(const FOnAttributeChangeData& Data) const;
	void MaxHopeChanged(const FOnAttributeChangeData& Data) const;
	void MachineAffinityChanged(const FOnAttributeChangeData& Data) const;
	void MaxMachineAffinityChanged(const FOnAttributeChangeData& Data) const;
	void LuckChanged(const FOnAttributeChangeData& Data) const;
	void MaxLuckChanged(const FOnAttributeChangeData& Data) const;
	
 
};
