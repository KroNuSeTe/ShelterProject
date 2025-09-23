// Copyright KroNus Games 2025

#include "Public/UI/WidgetController/ShWidgetController.h"

void UShWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UShWidgetController::BroadcastInitialValues()
{
	
}

void UShWidgetController::BindCallBacksToDependencies()
{
	
}
