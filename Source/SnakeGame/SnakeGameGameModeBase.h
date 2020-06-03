// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameGameModeBase.generated.h"

class AFoodSpawn;
class ASnakeElementBase;

/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASnakeGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TArray<ASnakeElementBase*> Elements;
	UPROPERTY()
		AFoodSpawn* FoodSpawn;
public:
	virtual void Tick(float DeltaTime) override;
};
