// Copyright KroNus Games 2025

#include "Public/Actor/ShEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Public/AbilitySystem/ShAttributeSet.h"
#include "Components/SphereComponent.h"


AShEffectActor::AShEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	
}

void AShEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UShAttributeSet* ShAttributeSet= Cast<UShAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UShAttributeSet::StaticClass()));
		UShAttributeSet* MutableShAttributeSet = const_cast<UShAttributeSet*>(ShAttributeSet);
		MutableShAttributeSet->SetHealth(ShAttributeSet->GetHealth() + 25.f);
		MutableShAttributeSet->SetStamina(ShAttributeSet->GetStamina() - 25.f);
		Destroy();
	}
}

void AShEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AShEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AShEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AShEffectActor::EndOverlap);
}

