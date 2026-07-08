// Joao Ricardo Copyright.

#include "Characters/PlayableCharacters/GCC_PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/PlayableCharacters/GCC_PlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
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
	
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->MaxWalkSpeed=230.f;
}

void AGCC_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (IsValid(GetAbilitySystemComponent()) || !HasAuthority()) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
}

void AGCC_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (!IsValid(GetAbilitySystemComponent())) return;
}

UAbilitySystemComponent* AGCC_PlayerCharacter::GetAbilitySystemComponent() const
{
	AGCC_PlayerState* GCCPlayerState=Cast<AGCC_PlayerState>(GetPlayerState());
	
	if (!IsValid(GCCPlayerState)) return nullptr;
	
	return GCCPlayerState->GetAbilitySystemComponent();
}