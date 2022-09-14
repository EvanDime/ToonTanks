// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	//see if in range
	if (Tank == nullptr)
	{
		return;
	}

	if (InFireRange() && Tank->bAlive)
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if (Tank)
	{
		const float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());

		return Distance <= FireRange;
	}
	return false;
}


void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
