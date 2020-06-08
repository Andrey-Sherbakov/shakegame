// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SnakeGameGameModeBase.h"
#include "FoodSpawn.h"
#include "Kismet/GameplayStatics.h"


void ASnakeGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FString CurrentMap = UGameplayStatics::GetCurrentLevelName(GetWorld(), true);
	
	if (Elements.Num() >= 30)
	{
		if (CurrentMap == "Map")
		{
			UGameplayStatics::OpenLevel(this, "Level2");
		}
		if (CurrentMap == "Level2")
		{
			UGameplayStatics::OpenLevel(this, "Level3");
		}
	}
}
