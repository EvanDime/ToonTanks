// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//Get distance of tank
	if (Tank)
	{
		float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());

		//see if in range
		if (Distance <= FireRange)
		{
			//Rotate towards target
			RotateTurret(Tank->GetActorLocation());

			//murder.exe
		}

	}
	
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
