// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PrjAugmenter : ModuleRules
{
	public PrjAugmenter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange
		(
			new string[]
			{
				"PrjAugmenter/Public"
			}
		);


		PrivateIncludePaths.AddRange
		(
			new string[]
			{
				"PrjAugmenter/Private"
			}
		);
			
		
		PublicDependencyModuleNames.AddRange
		(
			new string[]
			{
				"Core"
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange
		(
			new string[]
			{
				"Projects",
				"InputCore",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"Blutility",
				"UMG",
				"UMGEditor",
				"LevelEditor"
			}
		);
	}
}
