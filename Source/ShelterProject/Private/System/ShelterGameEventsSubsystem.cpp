// Fill out your copyright notice in the Description page of Project Settings.


#include "System/ShelterGameEventsSubsystem.h"
#include "Inventory.h"

// HUD y WidgetController del proyecto
#include "UI/HUD/ShHUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/WidgetController/ShWidgetController.h" // FWidgetControllerParams

void UShelterGameEventsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FInventoryModule::Get().SetGameEventsProvider(TScriptInterface<IInventoryGameEvents>(this));
}

void UShelterGameEventsSubsystem::Deinitialize()
{
	auto& Module = FInventoryModule::Get();
	if (Module.GetGameEventsProvider().GetObject() == this)
	{
		Module.SetGameEventsProvider(TScriptInterface<IInventoryGameEvents>());
	}
	Super::Deinitialize();
}

void UShelterGameEventsSubsystem::TriggerOnHealthChanged_Implementation(APlayerController* PC, float NewHealth)
{
	if (!IsValid(PC))
	{
		return;
	}

	AShHUD* HUD = PC->GetHUD<AShHUD>();
	if (!IsValid(HUD))
	{
		return;
	}

	// Nota:
	// - Si el OverlayWidgetController ya está creado, no necesitará ASC/AttributeSet aquí.
	// - Si no lo está y tu implementación lo crea en GetOverlayWidgetController con WCParams,
	//   y requiere ASC/AttributeSet válidos, pásalos aquí en lugar de nullptr.
	FWidgetControllerParams WCParams(PC, PC->PlayerState, /*ASC*/ nullptr, /*AttributeSet*/ nullptr);
	UOverlayWidgetController* OverlayWC = HUD->GetOverlayWidgetController(WCParams);
	if (!OverlayWC)
	{
		return;
	}

	// Broadcast hacia la UI
	OverlayWC->OnHealthChanged.Broadcast(NewHealth);
}

