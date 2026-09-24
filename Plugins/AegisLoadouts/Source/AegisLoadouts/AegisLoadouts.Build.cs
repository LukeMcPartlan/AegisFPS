// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisLoadouts : ModuleRules
{
	public AegisLoadouts(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine",
			"AegisCharacters", "AegisAbilities", "AegisWeapons",
		});
	}
}
