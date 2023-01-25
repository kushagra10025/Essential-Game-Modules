// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NPIM_AC_InteractionTrace.generated.h"

class ANPIM_InteractionArea_Master;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NPINTERACTIONMODULE_API UNPIM_AC_InteractionTrace : public UActorComponent
{
	GENERATED_BODY()

public:	
	UNPIM_AC_InteractionTrace();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction Trace")
	float TraceLength;

private:
	bool bTracingInteractionArea;
	TObjectPtr<ANPIM_InteractionArea_Master> FocusedInteractionArea;
	TObjectPtr<AActor> FocusedActor;

	void Trace();
	void TraceInteractionArea(bool bTrace);

public:
	UFUNCTION(BlueprintCallable, Category="Interaction Trace")
	void SetupInteractionTrace();

		
};
