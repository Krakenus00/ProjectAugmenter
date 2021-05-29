// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Components/LightComponent.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"

#include "PAEditorTweaks.generated.h"

/*====================================================================
   A couple of blueprint functions that can be written only using C++.
   They are needed for the plugin to function properly.
   Although, they all are public, so you can use them as you please.
  ====================================================================*/
UCLASS()
class PRJAUGMENTER_API UPAEditorTweaks : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static TSharedRef<SDockTab> SpawnEditorUITab(const FSpawnTabArgs& SpawnTabArgst, UWidgetBlueprint* Widget);

public:
	UFUNCTION(BlueprintCallable, Category="Rendering")
	static void PA_SetCastDynamicShadows(ULightComponent* light, bool bSet);

	UFUNCTION(BlueprintCallable, Category="Scripting")
	static void PA_DispatchEditorUtilityWidget(UWidgetBlueprint* Widget); 
};
