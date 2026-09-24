// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisUI : ModuleRules
{
	public AegisUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine",
			"UMG", "Slate", "SlateCore",
		});
	}
}
