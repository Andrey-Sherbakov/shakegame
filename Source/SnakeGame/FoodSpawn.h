// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "FoodSpawn.generated.h"

class AFood;

UCLASS()
class SNAKEGAME_API AFoodSpawn : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodSpawn();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AFood> FoodClass;

	UPROPERTY()
		TArray<AFood*> FoodElements;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void AddFoodElement(int ElementsNum = 1);

};
