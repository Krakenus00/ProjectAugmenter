// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PrjAugmenter : ModuleRules
{
	public PrjAugmenter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateIncludePaths.AddRange(
			new string[]
			{
				"Runtime/Engine/Classes"
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "UnrealEd",
                "Blutility",
                "UMG",
                "UMGEditor"
			}
		);
	}
}
