#include "ShooterCharacter.h"

#include "Kismet/GameplayStatics.h"

AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	RotationRate = 10;
}

void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AShooterCharacter::LookRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacter::LookRightRate);
}

void AShooterCharacter::MoveForward(const float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void AShooterCharacter::MoveRight(const float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

void AShooterCharacter::LookUp(const float Value)
{
	AddControllerPitchInput(Value);
}

void AShooterCharacter::LookRight(const float Value)
{
	AddControllerYawInput(Value);
}

void AShooterCharacter::LookUpRate(const float Value)
{
	AddControllerPitchInput(Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this));
}

void AShooterCharacter::LookRightRate(const float Value)
{
	AddControllerYawInput(Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this));
}

