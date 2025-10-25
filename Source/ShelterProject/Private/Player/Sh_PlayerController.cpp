// Copyright KroNus Games 2025


#include "Public/Player/Sh_PlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "ShGameplayTags.h"
#include "AbilitySystem/ShAbilitySystemComponent.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/SplineComponent.h"
#include "Input/ShInputComponent.h"
#include "Public/Interaction/EnemyInterface.h"
#include "Public/Interaction/ItemInterface.h"
#include "Inventory/Public/Widgets/HUD/Inv_HUDWidget.h"
#include "Inventory/Public/InventoryManagement/components/Inv_InventoryComponent.h"
#include "Items/Components/Inv_ItemComponent.h"
#include "Widgets/Inventory/HoverItem/Inv_HoverItem.h"

ASh_PlayerController::ASh_PlayerController()
{
	bReplicates = true;
	ItemTraceChannel = ECC_GameTraceChannel1;

	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

void ASh_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
	CursorTraceItem();

	AutoRun();
}

void ASh_PlayerController::AutoRun()
{
	if (!bAutoRunning) return;
	if (APawn* ControlledPawn = GetPawn())
	{
		const FVector LocationOnSpline = Spline->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
		const FVector Direction = Spline->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World);
		ControlledPawn->AddMovementInput(Direction);

		const float DistanceToDestination = (LocationOnSpline - CachedDestination).Length();
		if (DistanceToDestination <= AutoRunAcceptanceRadius)
		{
			bAutoRunning = false;
		}
	}
}

void ASh_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(ShIMContext, 0);
	}

	InventoryComponent = FindComponentByClass<UInv_InventoryComponent>();
	
	//CreateHUDWidget();
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASh_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UShInputComponent* ShInputComponent = CastChecked<UShInputComponent>(InputComponent);
	ShInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	ShInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, &ThisClass::PrimaryInteract);
	ShInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Started, this, &ThisClass::ToggleInventory);

	ShInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ASh_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ASh_PlayerController::ToggleInventory()
{
	if (!InventoryComponent.IsValid()) return;
	InventoryComponent->ToggleInventoryMenu();

	/*if (InventoryComponent->IsMenuOpen())
	{
		HUDWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		HUDWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	}*/
}

void ASh_PlayerController::CursorTrace()
{
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	if (LastActor != ThisActor)
	{
		if (LastActor) LastActor->UnHighlightActor();
		if (ThisActor) ThisActor->HighlightActor();
	}
}

void ASh_PlayerController::CursorTraceItem()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit)
	{
		if (ThisItemActor)
		{
			ThisItemActor->UnHighlightActor();
			LastItemActor = ThisItemActor;
			ThisItemActor = nullptr;
		}
		return;
	}

	AActor* HitActor = CursorHit.GetActor();
	if (!HitActor)
	{
		if (ThisItemActor)
		{
			ThisItemActor->UnHighlightActor();
			LastItemActor = ThisItemActor;
			ThisItemActor = nullptr;
		}
		return;
	}

	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	float Distance = FVector::Dist(ControlledPawn->GetActorLocation(), HitActor->GetActorLocation());
	//DrawDebugLine(GetWorld(), ControlledPawn->GetActorLocation(), HitActor->GetActorLocation(), FColor::Green, false, 1.0f);
	
	if (Distance > MaxItemInteractionDistance)
	{
		if (ThisItemActor)
		{
			ThisItemActor->UnHighlightActor();
			LastItemActor = ThisItemActor;
			ThisItemActor = nullptr;
		}
		return;
	}

	// Si el actor ha cambiado
	if (HitActor != ThisItemActor)
	{
		if (ThisItemActor)
			ThisItemActor->UnHighlightActor();

		LastItemActor = ThisItemActor;
		ThisItemActor = HitActor;

		if (ThisItemActor)
			ThisItemActor->HighlightActor();
	}

	/** Old code
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastItemActor = ThisItemActor;
	ThisItemActor = CursorHit.GetActor();

	if (LastItemActor != ThisItemActor)
	{
		if (LastItemActor) LastItemActor->UnHighlightActor();
		if (ThisItemActor) ThisItemActor->HighlightActor();
	}
	Old code **/
}

void ASh_PlayerController::CreateHUDWidget()
{
	/*if (!IsLocalController()) return;
	HUDWidget = CreateWidget<UInv_HUDWidget>(this, HUDWidgetClass);
	if (IsValid(HUDWidget))
	{
		HUDWidget->AddToViewport();
	}*/
}

void ASh_PlayerController::PrimaryInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, "ThisItemActor");

	if (!ThisItemActor) return;

	AActor* ThisActorInt = Cast<AActor>(ThisItemActor.GetObject());
	UInv_ItemComponent* ItemComp = ThisActorInt->FindComponentByClass<UInv_ItemComponent>();
	if (!IsValid(ItemComp) || !InventoryComponent.IsValid()) return;
	InventoryComponent->TryAddItem(ItemComp);
}

void ASh_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.MatchesTagExact(ShGameplayTags::InputTag::LeftMouseButton))
	{
		bTargeting = ThisActor ? true : false;
		bAutoRunning = false;
	}

}

void ASh_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(ShGameplayTags::InputTag::LeftMouseButton))
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagReleased(InputTag);
		}
		return;
	}

	if (bTargeting)
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagReleased(InputTag);
		}
	}
	else
	{
		APawn* ControlledPawn = GetPawn<APawn>();
		if (FollowTime <= ShortPressThreshold && ControlledPawn)
		{
			if (UNavigationPath* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination))
			{
				Spline->ClearSplinePoints();
				for (const FVector& PointLoc : NavPath->PathPoints)
				{
					Spline->AddSplinePoint(PointLoc, ESplineCoordinateSpace::World);
					DrawDebugSphere(GetWorld(), PointLoc, 10.f, 10, FColor::Green, false, 5.f);
				}
				if (NavPath->PathPoints.Num() > 0)
				{
					CachedDestination = NavPath->PathPoints[NavPath->PathPoints.Num() - 1];
					bAutoRunning = true;
				}
			}
		}
		FollowTime = 0.f;
		bTargeting = false;
	}
}

void ASh_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(ShGameplayTags::InputTag::LeftMouseButton))
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagHeld(InputTag);
		}
		return;
	}

	if (bTargeting)
	{
		GetASC()->AbilityInputTagHeld(InputTag);
	}
	else
	{
		FollowTime += GetWorld()->GetDeltaSeconds();

		FHitResult Hit;
		if (GetHitResultUnderCursor(ECC_Visibility, false, Hit))
		{
			CachedDestination = Hit.ImpactPoint;
		}

		if (APawn* ControlledPawn = GetPawn<APawn>())
		{
			const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
		}
	}
}

UShAbilitySystemComponent* ASh_PlayerController::GetASC()
{
	if (ShAbilitySystemComponent == nullptr)
	{
		ShAbilitySystemComponent = Cast<UShAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return ShAbilitySystemComponent;
}
