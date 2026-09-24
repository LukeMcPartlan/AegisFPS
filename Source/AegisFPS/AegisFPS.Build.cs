// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisFPS : ModuleRules
{
	public AegisFPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"NetCore",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			// Aegis feature plugins (modular gameplay features)
			"AegisCharacters",
			"AegisAbilities",
			"AegisWeapons",
			"AegisLoadouts",
			"AegisUI",
		});
	}
}
