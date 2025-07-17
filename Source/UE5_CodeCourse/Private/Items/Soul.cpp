// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Soul.h"
#include "Interfaces/PickupInterface.h"
#include "Components/SphereComponent.h"

void ASoul::BeginPlay()
{
	Super::BeginPlay();
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FTimerHandle SpawnDelay;
	GetWorldTimerManager().SetTimer(SpawnDelay, this, &ASoul::SpawnDelayEnd, 0.5f);
}

void ASoul::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->AddSouls(this);
		SpawnPickupSystem();
		SpawnPickupSound();
		Destroy();
	}
}

void ASoul::SpawnDelayEnd()
{
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}
