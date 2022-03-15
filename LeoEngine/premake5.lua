-- ENGINE CORE PROJECT
project "LeoEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "leopch.h"
	pchsource "src/leopch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"%{includeDir.GLFW}",
		"%{includeDir.GLAD}",
		"%{includeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib",
		"ImGui"
	}

	-- on windows
	filter "system:windows"
		cppdialect "C++17"

		-- windows version
		systemversion "latest"

		defines
		{
			-- macros
			"LEO_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	-- Debug config
	filter "configurations:Debug"
		defines "LEO_DEBUG"
		symbols "On"
		runtime "Debug"

	-- Release config
	filter "configurations:Release"
		defines "LEO_RELEASE"
		optimize "On"
		runtime "Release"

	-- Dist config
	filter "configurations:Dist"
		defines "LEO_DIST"
		optimize "On"
		runtime "Release"