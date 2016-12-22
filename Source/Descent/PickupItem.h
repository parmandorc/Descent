// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"

UCLASS()
class DESCENT_API APickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

  UPROPERTY(EditAnywhere)
    USceneComponent* ItemRootComponent;

  UPROPERTY(EditAnywhere)
    UStaticMeshComponent* ItemMesh;

  UPROPERTY(EditAnywhere)
    UShapeComponent* ItemPickupBox;

  UPROPERTY(EditAnywhere)
    FString name;

  UFUNCTION()
    void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFrontSweep, const FHitResult& SweepResult);
};
