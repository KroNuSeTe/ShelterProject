// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/LootItem.h"

#include "Public/ShelterProject.h"


ALootItem::ALootItem()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
}

void ALootItem::HighlightActor()
{
	MeshComponent->SetRenderCustomDepth(true);
	MeshComponent->SetCustomDepthStencilValue(CUSTOM_DEPTH_BLUE);

}

void ALootItem::UnHighlightActor()
{
	MeshComponent->SetRenderCustomDepth(false);
}
