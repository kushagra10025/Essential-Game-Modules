// Fill out your copyright notice in the Description page of Project Settings.


#include "NPIM_AC_InteractionTrace.h"

#include "InteractionArea/NPIM_InteractionArea_Master.h"
#include "Kismet/GameplayStatics.h"

UNPIM_AC_InteractionTrace::UNPIM_AC_InteractionTrace():
	TraceLength(400.f)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	SetComponentTickInterval(0.03f);

}

void UNPIM_AC_InteractionTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Trace();
}

void UNPIM_AC_InteractionTrace::BeginPlay()
{
	Super::BeginPlay();

}

void UNPIM_AC_InteractionTrace::Trace()
{
	if(const APlayerCameraManager* PCM = UGameplayStatics::GetPlayerCameraManager(this, 0))
	{
		const FVector Start = PCM->GetActorTransform().GetLocation();
		const FVector End = Start + (PCM->GetActorTransform().GetRotation().GetForwardVector() * TraceLength);

		FHitResult TraceHitResult;
		if(GetWorld()->LineTraceSingleByChannel(TraceHitResult, Start, End, ECollisionChannel::ECC_Visibility))
		{
			if(FocusedActor != TraceHitResult.GetActor())
			{
				FocusedActor = TraceHitResult.GetActor();
				TraceInteractionArea(FocusedActor.IsA(ANPIM_InteractionArea_Master::StaticClass()));
			}
		}else
		{
			TraceInteractionArea(false);
		}
	}
}

void UNPIM_AC_InteractionTrace::TraceInteractionArea(bool bTrace)
{
	if(bTrace)
	{
		if(bTracingInteractionArea)
		{
			FocusedInteractionArea->ToggleFocus(false);
		}
		FocusedInteractionArea = Cast<ANPIM_InteractionArea_Master>(FocusedActor);
		if(FocusedInteractionArea)
		{
			FocusedInteractionArea->ToggleFocus(true);
			bTracingInteractionArea = true;
		}
	}else
	{
		if(bTracingInteractionArea)
		{
			bTracingInteractionArea = false;
			FocusedInteractionArea->ToggleFocus(false);
			FocusedActor = nullptr;
			FocusedInteractionArea = nullptr;
		}
	}
}

void UNPIM_AC_InteractionTrace::SetupInteractionTrace()
{
	if(const APawn* PawnOwner = Cast<APawn>(GetOwner()))
	{
		if(PawnOwner->IsLocallyControlled())
		{
			SetComponentTickEnabled(true);
		}
	}
}

