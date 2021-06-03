// Copyright © 2021 Mykhailo Mushynskyi. All Rights Reserved.

/*=====================================================================================================
     PAEditorTweaks.cpp: Project Augmenter Editor Tweaks Blueprint Function Library implementation.
=====================================================================================================*/

#include "PAEditorTweaks.h"

#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "Editor/Blutility/Public/IBlutilityModule.h"
#include "Engine/StaticMeshActor.h"

// Sets the Light property CastDynamicShadows to bSet
void UPAEditorTweaks::PA_SetCastDynamicShadows(ULightComponent* Light, bool bSet)
{
	Light->CastDynamicShadows = bSet;
}

TSharedRef<SDockTab> UPAEditorTweaks::SpawnEditorUITab(const FSpawnTabArgs& SpawnTabArgs, UEditorUtilityWidget* Widget)
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab);
	if (Widget)
	{
		const TSharedRef<SWidget> CreatedSlateWidget = Widget->TakeWidget();
		SpawnedTab->SetContent(CreatedSlateWidget);
	}
	return SpawnedTab;
}

void UPAEditorTweaks::PA_DispatchEditorUtilityWidget(UUserWidget* Widget)
{
	const UEditorUtilityWidget* CDO = Widget->GetClass()->GetDefaultObject<UEditorUtilityWidget>();
	UEditorUtilityWidget* Instance = Cast<UEditorUtilityWidget>(Widget);
	if (CDO->ShouldAutoRunDefaultAction())
	{
		// This is an instant-run blueprint, just execute it
		Instance->ExecuteDefaultAction();
	}
	else
	{
		const FName RegistrationName = FName(*(Widget->GetPathName() + TEXT("_ActiveTab")));
		const FText DisplayName = FText::FromString(Widget->GetName());
		FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
		TSharedPtr<FTabManager> LevelEditorTabManager = LevelEditorModule.GetLevelEditorTabManager();
		if (!LevelEditorTabManager->HasTabSpawner(RegistrationName))
		{
			LevelEditorTabManager->RegisterTabSpawner(RegistrationName, FOnSpawnTab::CreateStatic(&UPAEditorTweaks::SpawnEditorUITab, Instance))
				.SetDisplayName(DisplayName)
				.SetMenuType(ETabSpawnerMenuType::Hidden);
		}
		TSharedPtr<SDockTab> NewDockTab = LevelEditorTabManager->TryInvokeTab(RegistrationName);
	}
}

TArray<UStaticMesh*> UPAEditorTweaks::PA_GetStaticMeshes(TArray<AActor*> Actors)
{
	TArray<UStaticMesh*> Meshes;
	for (const auto& A : Actors)
		if (A->IsA(AStaticMeshActor::StaticClass()))
		{
			UStaticMeshComponent* MeshComponent = Cast<AStaticMeshActor>(A)->GetStaticMeshComponent();
			MeshComponent->ForcedLodModel = 0;
			MeshComponent->MinLOD = 0;
			Meshes.Add(MeshComponent->GetStaticMesh());
		}
	return Meshes;
}

AActor* UPAEditorTweaks::PA_SpawnActorInEditorFromClass(TSubclassOf<AActor> Class, FTransform Transform)
{
#ifdef WITH_EDITOR
	return GEditor->GetEditorWorldContext(false).World()->SpawnActor(Class, &Transform);
#elif
	return nullptr;
#endif
}
