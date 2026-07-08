// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/PlayableCharacters/GCC_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"

void AGCC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (auto Mapping : DefaultMapping)
		{
			Subsystem->AddMappingContext(Mapping, 0);
		
		
		
		
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent=Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGCC_PlayerController::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGCC_PlayerController::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Jump);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AGCC_PlayerController::Sprint);
	}
}

void AGCC_PlayerController::Move(const struct FInputActionValue& Value)
{
	FVector2D _2DValue=Value.Get<FVector2D>();
	
	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	GetPawn()->AddMovementInput(ForwardDirection, _2DValue.X);
	GetPawn()->AddMovementInput(RightDirection, _2DValue.Y);
}

void AGCC_PlayerController::Look(const struct FInputActionValue& Value)
{
	FVector2D _2DValue=Value.Get<FVector2D>();
	
	AddYawInput(_2DValue.X);
	AddPitchInput(_2DValue.Y);
}

void AGCC_PlayerController::Jump()
{
	GetCharacter()->Jump();
}

void AGCC_PlayerController::Sprint()
{
	
}