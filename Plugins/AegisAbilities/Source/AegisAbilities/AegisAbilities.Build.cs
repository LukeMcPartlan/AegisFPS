// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisAbilities : ModuleRules
{
	public AegisAbilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine",
			"GameplayAbilities", "GameplayTags", "GameplayTasks",
		});
	}
}
