// Copyright KroNus Games 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Sh_PlayerController.generated.h"

struct FGameplayTag;
class UShInputConfig;
class UInv_InventoryComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
class IItemInterface;
class UInv_HUDWidget;
class UShAbilitySystemComponent;
class USplineComponent;
/**
 * 
 */
UCLASS()
class SHELTERPROJECT_API ASh_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASh_PlayerController();
	void AutoRun();
	virtual void PlayerTick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> ShIMContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> PrimaryInteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> ToggleInventoryAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MouseReleaseAction
;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TSubclassOf<UInv_HUDWidget> HUDWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> HUDWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;

	UPROPERTY(EditDefaultsOnly, Category = "Interaction")
	float MaxItemInteractionDistance = 300.f;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	void CursorTraceItem();
	void CreateHUDWidget();
	void PrimaryInteract();

	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent;

	FHitResult CursorHit;

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;

	TScriptInterface<IItemInterface> LastItemActor;
	TScriptInterface<IItemInterface> ThisItemActor;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UShInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UShAbilitySystemComponent> ShAbilitySystemComponent;

	UShAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.0f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly, Category = "AutoRun")
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere, Category = "AutoRun")
	TObjectPtr<USplineComponent> Spline;
};
