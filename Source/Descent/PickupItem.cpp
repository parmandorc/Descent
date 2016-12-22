// Fill out your copyright notice in the Description page of Project Settings.

#include "Descent.h"
#include "PickupItem.h"


// Sets default values
APickupItem::APickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  ItemRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ItemRoot"));
  ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
  ItemPickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ItemPickupBox"));

  RootComponent = ItemRootComponent;

  ItemMesh->AttachToComponent(ItemRootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

  ItemPickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
  ItemPickupBox->bGenerateOverlapEvents = true;
  ItemPickupBox->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnPlayerEnterPickupBox);
  ItemPickupBox->AttachToComponent(ItemRootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

  name = FString(TEXT("<Item Name>"));
}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APickupItem::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFrontSweep, const FHitResult & SweepResult)
{
  Destroy();
}

