// Copyright KroNus Games 2025


#include "Public/UI/WidgetController/OverlayWidgetController.h"

#include "AttributeSet.h"
#include "AbilitySystem/ShAbilitySystemComponent.h"
#include "Public/AbilitySystem/ShAttributeSet.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	const UShAttributeSet* ShAttributeSet = CastChecked<UShAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(ShAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(ShAttributeSet->GetMaxHealth());
	OnStaminaChanged.Broadcast(ShAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(ShAttributeSet->GetMaxStamina());
	OnHungerChanged.Broadcast(ShAttributeSet->GetHunger());
	OnMaxHungerChanged.Broadcast(ShAttributeSet->GetMaxHunger());
	OnThirstChanged.Broadcast(ShAttributeSet->GetThirst());
	OnMaxThirstChanged.Broadcast(ShAttributeSet->GetMaxThirst());
	
}

void UOverlayWidgetController::RegisterAttributeChangeCallbacks(const UShAttributeSet* ShAttributeSet)
{
    // Health
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnHealthChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxHealthChanged.Broadcast(Data.NewValue);
    });

    // Stamina
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetStaminaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnStaminaChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetMaxStaminaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxStaminaChanged.Broadcast(Data.NewValue);
    });

    // Hunger
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetHungerAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnHungerChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetMaxHungerAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxHungerChanged.Broadcast(Data.NewValue);
    });

    // Thirst
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetThirstAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnThirstChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        ShAttributeSet->GetMaxThirstAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxThirstChanged.Broadcast(Data.NewValue);
    });

}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	const UShAttributeSet* ShAttributeSet = CastChecked<UShAttributeSet>(AttributeSet);

	RegisterAttributeChangeCallbacks(ShAttributeSet);

	Cast<UShAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.MedKit
				// "A.1".MatchesTag("A") will return True, "A".MatchesTag("A.1") will return False
				// "Message.MedKit".MatchesTag("Message") will return True, "Message".MatchesTag("Message.MedKit") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					OnMessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
	
}


