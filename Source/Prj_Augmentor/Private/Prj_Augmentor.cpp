// Copyright Epic Games, Inc. All Rights Reserved.

#include "Prj_Augmentor.h"

#define LOCTEXT_NAMESPACE "FPrj_AugmentorModule"

void FPrj_AugmentorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FPrj_AugmentorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPrj_AugmentorModule, Prj_Augmentor)