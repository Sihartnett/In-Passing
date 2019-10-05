#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraShake.h"
#include "UnbelievableCharacter.generated.h"

class UInputComponent;

UCLASS(config = Game)

class AUnbelievableCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* R_MotionController;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* L_MotionController;

	UPROPERTY()
	AActor* id;

public:

	AUnbelievableCharacter();
	UPROPERTY(BlueprintReadWrite)
		bool shouldBeHealing;
	UPROPERTY(BlueprintReadWrite)
		bool damageHasBeenTaken;
	int WallJumpTraces;
	float WallJumpTraceDistance;
	float SingleJumpControl = 0.8f;
	float DoubleJumpControl = 0.7f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Wall Vars")
		AActor* WallBeingRode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isMovingForward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isOnIce;


	//void SingleJumpIncrement();
	//void DoubleJumpIncrement();

	void Jump();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float WalljumpHorizontalStrenght;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float WalljumpUpwardsStrength;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UCameraShake> MyShake;

protected:

	void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Health Variables")//------------------
		float healthPoints;                                                                 // |
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Variables")            // |
		float healthPointsMaximum;                                                          // |
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health Variables")
		float healthTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Variables")
		float amountToRegenerate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Variables")
		float rateOfRegeneration = 3.0f;
	UFUNCTION()                                                                           // |---------- used for damage and will need to be hooked up to Will's stuff 
		void takeDamage(int damageAmount);//-------------------------------------------------|

	UFUNCTION(BlueprintImplementableEvent, Category="Health Regeneration")
		void RegainHealth();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	float BaseLookUpRate;

	UFUNCTION()
	void DoubleJump();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DoubleJumpCounter;
	UFUNCTION()
	void WallRun();
	UFUNCTION()
	void WallRunEnd();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanDodge = true;
	UPROPERTY(EditAnywhere, Category="Can We WallRun")
	bool CanWallRun = false;
	bool StopSideMovement = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TutJustDodged = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool inMenu;

protected:

	void MoveForward(float Val);
	void MoveRight(float Val);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	void DodgeLeft();
	void DodgeRight();
	void EndDodge();
	void SetWallBool();
	void ResetWallBool();

protected:

	void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	UFUNCTION(BlueprintCallable, Category = "On Land shake method")
	void Landed(const FHitResult& Hit) override;
	void Debug();
private:
	UFUNCTION(BlueprintCallable, Category="Save System Functionality")
	void SaveGame();
	UFUNCTION(BlueprintCallable, Category = "Save System Functionality")
	void LoadGame();

	void LoadTotalGameTime();

	// trial of sound cues variables


public:
	float debugFloat = 0;
	UPROPERTY(BlueprintReadWrite)
	float dodgeCoolDownFloat;
	bool isheld = false;
	void DodgeCooldown();
	UFUNCTION(BlueprintCallable, Category="Yeet")
	void TutDodgeCheck();

	struct FTimerHandle MemberTimerHandle;
	struct FTimerHandle MemberTimerHandle2;
	struct FTimerHandle MemberTimerHandle3;
	struct FTimerHandle MemberTimerHandleDodge;

	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	UPROPERTY(BlueprintReadWrite)
		bool DisableSpecialMovement = true;

	UPROPERTY(BlueprintReadWrite)
		bool WingedMode = false;

	UPROPERTY(BlueprintReadWrite)
		bool shouldShake = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Location of Saving")
		FVector locationToSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Rocation of Saving")
		FRotator rotationToSet;

	bool WallClimb = true;
	bool WallClimb2 = true;

	UFUNCTION()
		void RunFall();

	bool WallRunCooldown = true;

	void cool_down();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int indexOfSaveFile;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float f_TotalGameplayTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float float_TimeSpentInGame;

	UPROPERTY(VisibleAnywhere, Category="Debug Time Variables")
		float debugTimer;

	UPROPERTY(EditAnywhere, Category = "Debug Time Variables")
		float delayToPrint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int ref_NumberofDeaths;
	
	UFUNCTION(BlueprintCallable, Category = "Save System Functionality")
		void setModeForSave(int indexOfGameMode);

	/*UFUNCTION(BlueprintImplementableEvent, Category = "Set Player Rotation on Load")
		void setPlayerRotationOnLoad(FRotator Rotation);*/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ref_GameMode;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ref_LevelBeingPlayed;
	
	UFUNCTION(BlueprintCallable, Category = "Save System Functionality")
		void setLevelBeingPlayed(int indexOfLevel);

	UFUNCTION(BlueprintCallable, Category = "Save System Functionality")
		void setNumberOfDeaths(int numberOfDeathsToAdd);

	UFUNCTION(BlueprintCallable, Category = "Save System Functionality")
		void setAllVariablesNecessaryFromBlueprint(int numberOfDeathsToAdd, int indexOfGameMode, int indexOfLevel);

	UFUNCTION(BlueprintCallable, Category = "Save System Functionality")
		void setDeathCountFromBlueprint(int numberOfDeaths);

	UFUNCTION(BlueprintImplementableEvent, Category = "New Camera Shake")
		void cameraBob(float amountToBob);

	UFUNCTION(BlueprintImplementableEvent, Category = "Speed Line")
		void SpeedLineFade();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callLandingCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callWalkingCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callJumpCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callDoubleJumpCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callWallJumpCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callWallRunCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callDodgeCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callDashJumpCue();

	UFUNCTION(BlueprintImplementableEvent, Category = "Sound Effects")
		void callAirTravelCue(float Time);

	UFUNCTION(BlueprintImplementableEvent, Category = "Winged Mode")
		void WingedModeOn();

	UFUNCTION(BlueprintImplementableEvent, Category = "Winged Mode")
		void WingedModeOff();

	
	UPROPERTY(EditAnywhere,Category="Camera Shake Variables")
		float rateOfShakePerSecondOfDescent=1.0f;

	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere, Category = "Camera Shake Variables")
		float timeSpentInAir;
	
	UPROPERTY(BlueprintReadWrite,Category="Camera Shake Variable")
		float amountForCameraToShakeOnLand;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Camera Shake Variables")
		float amountForCameraToShakeOnDoubleJump;

	UPROPERTY(EditAnywhere, Category = "Wall Run Variables")
		float arcOfWallRun=50;


	struct FTimerHandle MemberTimerHandle4;
	void reset_camera_rotation();
	UFUNCTION(BlueprintImplementableEvent, Category = "CrossHair")
		void changeCircleSize(float amountForCircle);
	UFUNCTION(BlueprintImplementableEvent, Category = "CrossHair")
		void lerpCircleIn();

};