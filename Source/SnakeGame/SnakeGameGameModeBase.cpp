// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SnakeGameGameModeBase.h"
#include "FoodSpawn.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeGameInstance.h"

void ASnakeGameGameModeBase::BeginPlay()
{
	
}

void ASnakeGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	USnakeGameInstance* game_instance = Cast<USnakeGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	int32 Scores = game_instance->Scores;
	if (Scores == 5)
	{
		UGameplayStatics::OpenLevel(this, "Level2");
		game_instance->Scores = game_instance->Scores + 1;
	}
	if (Scores == 10)
	{
		UGameplayStatics::OpenLevel(this, "Level3");
		game_instance->Scores = game_instance->Scores + 1;
	}
}
