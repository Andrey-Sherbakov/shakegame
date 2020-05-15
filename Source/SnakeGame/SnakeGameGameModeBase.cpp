// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SnakeGameGameModeBase.h"
#include "FoodSpawn.h"
#include "Kismet/GameplayStatics.h"

void ASnakeGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	Scores = 0;
}

void ASnakeGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Scores == 50)
	{
		UGameplayStatics::OpenLevel(this, "Level2");
	}
}
