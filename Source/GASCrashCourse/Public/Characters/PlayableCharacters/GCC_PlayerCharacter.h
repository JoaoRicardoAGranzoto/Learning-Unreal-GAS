// Joao Ricardo Copyright.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GCC_BaseCharacter.h"
#include "GCC_PlayerCharacter.generated.h"

UCLASS()
class GASCRASHCOURSE_API AGCC_PlayerCharacter : public AGCC_BaseCharacter
{
	GENERATED_BODY()

public:
	AGCC_PlayerCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera")
	TObjectPtr<class USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera")
	TObjectPtr<class UCameraComponent> FollowCamera;
};