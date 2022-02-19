workspace "LeoEngine"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories relative to root folder
includeDir = {}
includeDir["GLFW"] = "%{wks.location}/LeoEngine/vendor/glfw/include"
includeDir["GLAD"] = "%{wks.location}/LeoEngine/vendor/glad/include"
includeDir["ImGui"] = "%{wks.location}/LeoEngine/vendor/imgui"

-- Including vendor premake5 files
include "LeoEngine/vendor/glfw"
include "LeoEngine/vendor/glad"
include "LeoEngine/vendor/imgui"

-- ENGINE CORE PROJECT
include "LeoEngine"

-- SANDBOX PROJECT
include "Sandbox"