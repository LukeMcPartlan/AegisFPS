// Copyright RolyatWorks. All Rights Reserved.

using UnrealBuildTool;

public class AegisFPSEditorTarget : TargetRules
{
	public AegisFPSEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("AegisFPS");
	}
}
