// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BonusSpawn.generated.h"

class ABonusUpSpeed;
class ABonusDownSpeed;
class ADoobleFood;

UCLASS()
class SNAKEGAME_API ABonusSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABonusSpawn();

	UPROPERTY()
		FTimerHandle BonusTimerHandle;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ABonusUpSpeed> BonusUpSpeedClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ABonusDownSpeed> BonusDownSpeedClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ADoobleFood> DoubleFoodClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void AddBonus();

};
