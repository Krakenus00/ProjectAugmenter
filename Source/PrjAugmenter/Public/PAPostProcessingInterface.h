// Copyright © 2021 Mykhailo Mushynskyi. All Rights Reserved.

/*===========================================================================================================================
	   PAPostProcessingInterface.h: Project Augmenter Post Processing Interface Blueprint Function Library definitions.
===========================================================================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/PostProcessVolume.h"

#include "PAPostProcessingInterface.generated.h"

//Set of accessors to post processing settings.

UCLASS()
class PRJAUGMENTER_API UPAPostProcessingInterface : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/*=================================
	      Ambient Occlusion begin
	=================================*/

	// Intensity

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcAOIntensity(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcAOIntensity(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcAOIntensity(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcAOIntensity(APostProcessVolume* PP);

	// Power

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcAOPower(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcAOPower(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcAOPower(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcAOPower(APostProcessVolume* PP);

	// Radius

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcAORadius(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcAORadius(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcAORadius(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcAORadius(APostProcessVolume* PP);

	// Quality

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcAOQuality(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcAOQuality(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcAOQuality(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcAOQuality(APostProcessVolume* PP);

	/*==============================
	     Ambient Occlusion end
	==============================*/

	//-----------------------------------------------------------------------------

	/*=====================
		  Bloom begin
	=====================*/

	// Intensity

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcBloomIntensivity(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcBloomIntensivity(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcBloomIntensivity(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcBloomIntensivity(APostProcessVolume* PP);

	// Threshold

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcBloomThreshold(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcBloomThreshold(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcBloomThreshold(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcBloomThreshold(APostProcessVolume* PP);

	// Size scale

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcBloomSizeScale(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcBloomSizeScale(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcBloomSizeScale(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcBloomSizeScale(APostProcessVolume* PP);

	/*=====================
	      Bloom end
	=====================*/

	//-----------------------------------------------------------------------------

	/*==============================
	      Depth of Field begin
	==============================*/

#pragma region Depth of Field

	//Focal distance

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcDOFFocalDistance(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcDOFFocalDistance(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcDOFFocalDistance(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcDOFFocalDistance(APostProcessVolume* PP);
	
	//Blur radius

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcDOFBlurRadius(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcDOFBlurRadius(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcDOFBlurRadius(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcDOFBlurRadius(APostProcessVolume* PP);

	//Blur km for 50%

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetPostProcDOFBlurDistance(APostProcessVolume* PP, float Value);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static float PA_GetPostProcDOFBlurDistance(APostProcessVolume* PP);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCheckPostProcDOFBlurDistance(APostProcessVolume* PP, bool isChecked);

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static bool PA_GetCheckPostProcDOFBlurDistance(APostProcessVolume* PP);

#pragma endregion

	/*=============================
	       Depth of Field end
	=============================*/
};
