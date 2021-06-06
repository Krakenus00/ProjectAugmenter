// Copyright © 2021 Mykhailo Mushynskyi. All Rights Reserved.

/*=====================================================================================================
       PAEditorTweaks.h: Project Augmenter Editor Tweaks Blueprint Function Library definitions.
=====================================================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "WidgetBlueprint.h"
#include "EditorUtilityWidget.h"
#include "LevelEditor.h"

#include "Components/LightComponent.h"
#include "Components/ListView.h"

#include "PAEditorTweaks.generated.h"

// A couple of blueprint functions that can be written only using C++.
// They are needed for the plugin to function properly.
// Although, they all are public, so you can use them as you please.

UCLASS()
class PRJAUGMENTER_API UPAEditorTweaks : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static TSharedRef<SDockTab> SpawnEditorUITab(const FSpawnTabArgs& SpawnTabArgs, UEditorUtilityWidget* Widget);

public:
	UFUNCTION(BlueprintCallable, Category = "Rendering")
	static void PA_SetCastDynamicShadows(ULightComponent* light, bool bSet);

	UFUNCTION(BlueprintCallable, Category = "Scripting")
	static void PA_DispatchEditorUtilityWidget(UUserWidget* Widget);

	UFUNCTION(BlueprintCallable, Category = "Scripting")
	static TArray<UStaticMesh*> PA_GetStaticMeshes(TArray<AActor*> Actors);

	UFUNCTION(BlueprintCallable, Category = "Scripting", meta = (DeterminesOutputType = "Class"))
	static AActor* PA_SpawnActorInEditorFromClass(TSubclassOf<AActor> Class, FTransform Transform);
};

UCLASS(meta = (EntryInterface = UserListEntry))
class PRJAUGMENTER_API UPAListView : public UListView
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Scripting")
	void SetEntryWidgetClass(TSubclassOf<UUserWidget> NewWidget)
	{
#ifdef WITH_EDITOR
		EntryWidgetClass = NewWidget;
#endif
	}
};
