#include "Player/PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APlayerPawn::APlayerPawn()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	if (const auto PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerContext, 0);
		}
	}
}

void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (InteractAction)
		{
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &APlayerPawn::Interact);
		}
	}
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn::Interact()
{
	PerformRaycast();
}

void APlayerPawn::InteractWithObject_Implementation(AActor* InteractableActor)
{
	GEngine->AddOnScreenDebugMessage(1, 3, FColor::Green, FString::Printf(TEXT("Interacting with %s"), *InteractableActor->GetName()));
	//InteractableActor->Destroy();
}

void APlayerPawn::PerformRaycast()
{
	if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		float TouchX, TouchY;
		bool bIsTouching;

		PlayerController->GetInputTouchState(ETouchIndex::Touch1, TouchX, TouchY, bIsTouching);

		if (bIsTouching)
		{
			FVector WorldLocation, WorldDirection;
			if (PlayerController->DeprojectScreenPositionToWorld(TouchX, TouchY, WorldLocation, WorldDirection))
			{
				FVector End = WorldLocation + (WorldDirection * 10000.0f);

				FHitResult HitResult;
				FCollisionQueryParams CollisionParams;
				CollisionParams.AddIgnoredActor(this);

				if (GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, End, ECC_Visibility, CollisionParams))
				{
					if (HitResult.GetActor() && HitResult.GetActor()->ActorHasTag("Interactable"))
					{
						InteractWithObject(HitResult.GetActor());
					}
				}
			}
		}
	}
}
