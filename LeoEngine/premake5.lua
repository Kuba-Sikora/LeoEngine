-- ENGINE CORE PROJECT
project "LeoEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "leopch.h"
	pchsource "src/leopch.cpp"

	staticruntime "on"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"%{includeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
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
			"LEO_BUILD_DLL"
		}

		postbuildcommands
		{
			-- copyting the dll file into the Sandbox directory
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
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