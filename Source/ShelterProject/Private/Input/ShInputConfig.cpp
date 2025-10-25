// Copyright KroNus Games 2025


#include "Input/ShInputConfig.h"

const UInputAction* UShInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FShInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
		
		if (bLogNotFound)
		{
			UE_LOG(LogTemp, Error, TEXT("Could not find input action for tag %s"), *InputTag.ToString());
		}
	}
	return nullptr;
}
