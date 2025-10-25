// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/ShAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	ToughnessDef.AttributeToCapture = UShAttributeSet::GetToughnessAttribute();
	ToughnessDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ToughnessDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(ToughnessDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather Tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Toughness = 0.f;
	GetCapturedAttributeMagnitude(ToughnessDef, Spec, EvaluationParameters, Toughness);
	Toughness = FMath::Max<float>(Toughness, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	
	return 80.f + 2.5f * Toughness + 10.f * PlayerLevel;
	
}
