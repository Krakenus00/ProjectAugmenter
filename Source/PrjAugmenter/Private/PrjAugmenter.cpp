// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrjAugmenter.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "PrjAugmenterStyle.h"
#include "PAEditorTweaks.h"
#include "Blueprint/UserWidget.h"

#include "LevelEditor.h"

static const FName PrjAugmenterTabName("PrjAugmenter");

#define LOCTEXT_NAMESPACE "FPrjAugmenterModule"
#define LEVELEDITOR_MODULE_NAME TEXT("LevelEditor")

void FPrjAugmenterModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FPrjAugmenterStyle::Initialize();
	FPrjAugmenterStyle::ReloadTextures();
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(LEVELEDITOR_MODULE_NAME);
	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
	MenuExtender->AddMenuBarExtension(
		"Help",
		EExtensionHook::Before,
		nullptr,
		FMenuBarExtensionDelegate::CreateRaw(this, &FPrjAugmenterModule::AddMenu)
	);
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FPrjAugmenterModule::ShutdownModule()
{
	FPrjAugmenterStyle::Shutdown();
}

void FPrjAugmenterModule::OpenMenuCommand()
{
	//UUserWidget* MenuWidget = CreateWidget(GEditor->GetEditorWorldContext(false).World(), UMenuHolder().GetClass(), "PAMenu");
	//UPAEditorTweaks::PA_DispatchEditorUtilityWidget(MenuWidget);
}

void FPrjAugmenterModule::AddMenu(FMenuBarBuilder& MenuBuilder)
{
	MenuBuilder.AddPullDownMenu(
		LOCTEXT("PluginsMenu", "Plugins"),
		LOCTEXT("PluginsMenu_TooltipKey", "Opens menu for Plugins"),
		FNewMenuDelegate::CreateRaw(this, &FPrjAugmenterModule::FillMenu),
		"Plugins",
		FName(TEXT("PluginsMenu")));
}

void FPrjAugmenterModule::FillMenu(FMenuBuilder& MenuBuilder)
{
	// Create a Submenu
	MenuBuilder.AddSubMenu(FText::FromString("Project Augmenter"),
		FText::FromString("Project Augmenter commands"),
		FNewMenuDelegate::CreateRaw(this, &FPrjAugmenterModule::FillSubMenu));
}

void FPrjAugmenterModule::FillSubMenu(FMenuBuilder& MenuBuilder)
{
	// Create the Submenu Entries
	MenuBuilder.AddMenuEntry(
		FText::FromString("Open Menu"),
		FText::FromString("Opens Project Augmenter Menu"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FPrjAugmenterModule::OpenMenuCommand))
	);
}

#undef LEVELEDITOR_MODULE_NAME
#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPrjAugmenterModule, PrjAugmenter)