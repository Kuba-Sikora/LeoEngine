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

-- Including the GLFW premake5 file
include "LeoEngine/vendor/glfw"

-- ENGINE CORE PROJECT
include "LeoEngine"

-- SANDBOX PROJECT
include "Sandbox"