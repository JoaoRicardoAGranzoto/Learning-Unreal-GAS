// Joao Ricardo Copyright.

#include "Characters/GCC_BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCharacterMovement()->bOrientRotationToMovement=false;
	GetCharacterMovement()->MaxWalkSpeed=300.f;
	
	GetMesh()->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* AGCC_BaseCharacter::GetAbilitySystemComponent() const




{
	return nullptr;
}

void AGCC_BaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;

	for (const auto& Ability : StartupAbilites)
	{
		FGameplayAbilitySpec AbilitySpec=FGameplayAbilitySpec(Ability, 1);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}