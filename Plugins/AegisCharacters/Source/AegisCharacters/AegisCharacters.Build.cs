// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisCharacters : ModuleRules
{
	public AegisCharacters(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
	}
}
