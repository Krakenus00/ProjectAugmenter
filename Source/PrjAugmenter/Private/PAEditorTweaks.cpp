// Fill out your copyright notice in the Description page of Project Settings.


#include "PAEditorTweaks.h"

#include "Editor/UMGEditor/Public/WidgetBlueprint.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "Editor/Blutility/Public/IBlutilityModule.h"

// Sets the Light property CastDynamicShadows to bSet
void UPAEditorTweaks::PA_SetCastDynamicShadows(ULightComponent* Light, bool bSet)
{
	Light->CastDynamicShadows = bSet;
}

TSharedRef<SDockTab> UPAEditorTweaks::SpawnEditorUITab(const FSpawnTabArgs& SpawnTabArgst, UWidgetBlueprint* Widget)
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab);
	TSubclassOf<UUserWidget> WidgetClass = Widget->GeneratedClass;
	UWorld* World = GEditor->GetEditorWorldContext().World(); check(World);
	UEditorUtilityWidget* CreatedUMGWidget = CreateWidget<UEditorUtilityWidget>(World, WidgetClass);
	if (CreatedUMGWidget)
	{
		TSharedRef<SWidget> CreatedSlateWidget = CreatedUMGWidget->TakeWidget();
		SpawnedTab->SetContent(CreatedSlateWidget);
	}
	return SpawnedTab;
}

void UPAEditorTweaks::PA_DispatchEditorUtilityWidget(UWidgetBlueprint* Widget)
{
	if (Widget->GeneratedClass->IsChildOf(UEditorUtilityWidget::StaticClass()))
	{
		const UEditorUtilityWidget* CDO = Widget->GeneratedClass->GetDefaultObject<UEditorUtilityWidget>();
		if (CDO->ShouldAutoRunDefaultAction())
		{
			// This is an instant-run blueprint, just execute it
			UEditorUtilityWidget* Instance = NewObject<UEditorUtilityWidget>(GetTransientPackage(), Widget->GeneratedClass);
			Instance->ExecuteDefaultAction();
		}
		else
		{
			FName RegistrationName = FName(*(Widget->GetPathName() + TEXT("_ActiveTab")));
			FText DisplayName = FText::FromString(Widget->GetName());
			FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
			TSharedPtr<FTabManager> LevelEditorTabManager = LevelEditorModule.GetLevelEditorTabManager();
			if (!LevelEditorTabManager->HasTabSpawner(RegistrationName))
			{
				//UEditorUtilityWidgetBlueprint* WidgetBlueprint = Cast<UEditorUtilityWidgetBlueprint>(Blueprint);
				LevelEditorTabManager->RegisterTabSpawner(RegistrationName, FOnSpawnTab::CreateStatic(&UPAEditorTweaks::SpawnEditorUITab, Widget))
					.SetDisplayName(DisplayName)
					.SetMenuType(ETabSpawnerMenuType::Hidden);
			}
			TSharedPtr<SDockTab> NewDockTab = LevelEditorTabManager->TryInvokeTab(RegistrationName);
		}
	}
}
