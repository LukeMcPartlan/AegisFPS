// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisWeapons : ModuleRules
{
	public AegisWeapons(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
