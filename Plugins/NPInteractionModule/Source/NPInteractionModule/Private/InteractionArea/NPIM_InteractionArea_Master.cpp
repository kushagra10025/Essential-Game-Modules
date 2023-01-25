// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionArea/NPIM_InteractionArea_Master.h"

ANPIM_InteractionArea_Master::ANPIM_InteractionArea_Master()
{
	PrimaryActorTick.bCanEverTick = true;

	ActorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ActorRoot"));
	SetRootComponent(ActorRoot);

}

void ANPIM_InteractionArea_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANPIM_InteractionArea_Master::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPIM_InteractionArea_Master::ToggleFocus(bool NewFocused)
{
	bFocused = NewFocused;
}
