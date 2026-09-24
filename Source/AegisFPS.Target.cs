// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisFPSTarget : TargetRules
{
	public AegisFPSTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("AegisFPS");
	}
}
