// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PapaChurros : ModuleRules
{
	public PapaChurros(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
