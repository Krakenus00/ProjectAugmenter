// Copyright © 2021 Mykhailo Mushynskyi. All Rights Reserved.

/*==============================================================================================================================
	  PAPostProcessingInterface.cpp: Project Augmenter Post Processing Interface Blueprint Function Library implementation.
==============================================================================================================================*/

#include "PAPostProcessingInterface.h"

void UPAPostProcessingInterface::PA_SetPostProcAOIntensity(APostProcessVolume* PP, float Value)
{
	PP->Settings.AmbientOcclusionIntensity = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcAOIntensity(APostProcessVolume* PP)
{
	return PP->Settings.AmbientOcclusionIntensity;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcAOIntensity(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_AmbientOcclusionIntensity = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcAOIntensity(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_AmbientOcclusionIntensity;
}

void UPAPostProcessingInterface::PA_SetPostProcAOPower(APostProcessVolume* PP, float Value)
{
	PP->Settings.AmbientOcclusionPower = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcAOPower(APostProcessVolume* PP)
{
	return PP->Settings.AmbientOcclusionPower;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcAOPower(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_AmbientOcclusionPower = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcAOPower(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_AmbientOcclusionPower;
}

void UPAPostProcessingInterface::PA_SetPostProcAORadius(APostProcessVolume* PP, float Value)
{
	PP->Settings.AmbientOcclusionRadius = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcAORadius(APostProcessVolume* PP)
{
	return PP->Settings.AmbientOcclusionRadius;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcAORadius(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_AmbientOcclusionRadius = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcAORadius(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_AmbientOcclusionRadius;
}

void UPAPostProcessingInterface::PA_SetPostProcAOQuality(APostProcessVolume* PP, float Value)
{
	PP->Settings.AmbientOcclusionQuality = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcAOQuality(APostProcessVolume* PP)
{
	return PP->Settings.AmbientOcclusionQuality;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcAOQuality(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_AmbientOcclusionQuality = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcAOQuality(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_AmbientOcclusionQuality;
}

void UPAPostProcessingInterface::PA_SetPostProcBloomIntensivity(APostProcessVolume* PP, float Value)
{
	PP->Settings.BloomIntensity = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcBloomIntensivity(APostProcessVolume* PP)
{
	return PP->Settings.BloomIntensity;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcBloomIntensivity(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_BloomIntensity = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcBloomIntensivity(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_BloomIntensity;
}

void UPAPostProcessingInterface::PA_SetPostProcBloomThreshold(APostProcessVolume* PP, float Value)
{
	PP->Settings.BloomThreshold = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcBloomThreshold(APostProcessVolume* PP)
{
	return PP->Settings.BloomThreshold;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcBloomThreshold(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_BloomThreshold = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcBloomThreshold(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_BloomThreshold;
}

void UPAPostProcessingInterface::PA_SetPostProcBloomSizeScale(APostProcessVolume* PP, float Value)
{
	PP->Settings.BloomSizeScale = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcBloomSizeScale(APostProcessVolume* PP)
{
	return PP->Settings.BloomSizeScale;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcBloomSizeScale(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_BloomSizeScale = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcBloomSizeScale(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_BloomSizeScale;
}

void UPAPostProcessingInterface::PA_SetPostProcDOFFocalDistance(APostProcessVolume* PP, float Value)
{
	PP->Settings.DepthOfFieldFocalDistance = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcDOFFocalDistance(APostProcessVolume* PP)
{
	return PP->Settings.DepthOfFieldFocalDistance;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcDOFFocalDistance(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_DepthOfFieldFocalDistance = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcDOFFocalDistance(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_DepthOfFieldFocalDistance;
}

void UPAPostProcessingInterface::PA_SetPostProcDOFBlurRadius(APostProcessVolume* PP, float Value)
{
	PP->Settings.DepthOfFieldDepthBlurRadius = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcDOFBlurRadius(APostProcessVolume* PP)
{
	return PP->Settings.DepthOfFieldDepthBlurRadius;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcDOFBlurRadius(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_DepthOfFieldDepthBlurRadius = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcDOFBlurRadius(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_DepthOfFieldDepthBlurRadius;
}

void UPAPostProcessingInterface::PA_SetPostProcDOFBlurDistance(APostProcessVolume* PP, float Value)
{
	PP->Settings.DepthOfFieldDepthBlurAmount = Value;
}

float UPAPostProcessingInterface::PA_GetPostProcDOFBlurDistance(APostProcessVolume* PP)
{
	return PP->Settings.DepthOfFieldDepthBlurAmount;
}

void UPAPostProcessingInterface::PA_SetCheckPostProcDOFBlurDistance(APostProcessVolume* PP, bool isChecked)
{
	PP->Settings.bOverride_DepthOfFieldDepthBlurAmount = isChecked;
}

bool UPAPostProcessingInterface::PA_GetCheckPostProcDOFBlurDistance(APostProcessVolume* PP)
{
	return PP->Settings.bOverride_DepthOfFieldDepthBlurAmount;
}
