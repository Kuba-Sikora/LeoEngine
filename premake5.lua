workspace "LeoEngine"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories relative to root folder
includeDir = {}
includeDir["spdlog"] = "%{wks.location}/vendor/spdlog/include"
includeDir["GLFW"] = "%{wks.location}/vendor/glfw/include"
includeDir["GLAD"] = "%{wks.location}/vendor/glad/include"
includeDir["ImGui"] = "%{wks.location}/vendor/imgui"

-- Including vendor premake5 files
include "vendor/glfw"
include "vendor/glad"
include "vendor/imgui"

-- SANDBOX PROJECT
include "src/Sandbox"

-- ENGINE PROJECT
include "src/Leo"