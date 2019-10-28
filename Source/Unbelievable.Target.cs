// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UnbelievableTarget : TargetRules
{
	public UnbelievableTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
        bUsesSteam = true;
		ExtraModuleNames.Add("Unbelievable");
	}
}
