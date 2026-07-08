// Joao Ricardo Copyright.

#include "Characters/PlayableCharacters/GCC_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGCC_PlayerCharacter::AGCC_PlayerCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->SetupAttachment(GetRootComponent());
	
	FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	
	
	

	FollowCamera->bUsePawnControlRotation = false;
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
}