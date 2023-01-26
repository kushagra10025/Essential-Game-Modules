// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NPIM_InteractionInterface.generated.h"

class UWidgetComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNPIM_InteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NPINTERACTIONMODULE_API INPIM_InteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction Interface")
	void Interface_ToggleFocus(bool bFocus);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction Interface")
	UWidgetComponent* Interface_GetInteractionWidgetRef();
};
