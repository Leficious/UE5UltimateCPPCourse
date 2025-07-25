// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EchoHUD.generated.h"

class UEchoOverlay;

/**
 * 
 */
UCLASS()
class UE5_CODECOURSE_API AEchoHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Echo")
	TSubclassOf<UEchoOverlay> EchoOverlayClass;

	UPROPERTY()
	TObjectPtr<UEchoOverlay> EchoOverlay;
public:

	FORCEINLINE UEchoOverlay* GetEchoOverlay() const { return EchoOverlay; }
};
