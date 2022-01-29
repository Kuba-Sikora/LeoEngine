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

-- Including the GLFW and GLAD premake5 files
include "LeoEngine/vendor/glfw"
include "LeoEngine/vendor/glad"

-- ENGINE CORE PROJECT
include "LeoEngine"

-- SANDBOX PROJECT
include "Sandbox"