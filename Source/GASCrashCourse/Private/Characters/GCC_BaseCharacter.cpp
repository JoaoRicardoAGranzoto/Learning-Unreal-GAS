// Joao Ricardo Copyright.

#include "Characters/GCC_BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCharacterMovement()->bOrientRotationToMovement=false;
	GetCharacterMovement()->MaxWalkSpeed=300.f;
}