// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ColorPaletteEditor : ModuleRules
{
	public ColorPaletteEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"Core", 
				"DetailCustomizations", 
				"Slate",
				"AppFramework",
				"UnrealEd",
				"PropertyEditor",
				"InputCore",
				"DeveloperSettings",
			});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"SlateCore",
				"ColorPalette",   
				"PropertyEditor",

				"Kismet",
				"EditorFramework",
				"GraphEditor",
				"ApplicationCore",
				"EditorStyle",
				"Projects",
				"ToolMenus",


			});
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
			});
	}
}
