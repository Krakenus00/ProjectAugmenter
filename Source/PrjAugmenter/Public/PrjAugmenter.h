// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBarBuilder;
class FMenuBuilder;

class FPrjAugmenterModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void OpenMenuCommand();

private:
	void AddMenu(FMenuBarBuilder& MenuBuilder);
	void FillMenu(FMenuBuilder& MenuBuilder);
	void FillSubMenu(FMenuBuilder& MenuBuilder);

};
