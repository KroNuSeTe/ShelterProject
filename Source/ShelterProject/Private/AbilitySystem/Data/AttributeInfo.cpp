// Copyright KroNus Games 2025


#include "AbilitySystem/Data/AttributeInfo.h"

FShAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FShAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("AttributeInfo::FindAttributeInforForTag: Could not find attribute info for tag %s"), *AttributeTag.ToString());
	}

	return FShAttributeInfo();
}
