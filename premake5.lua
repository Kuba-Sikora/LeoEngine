workspace "LeoEngine"
	architecture "x86_64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- ENGINE CORE PROJECT
project "LeoEngine"
	location "LeoEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "leopch.h"
	pchsource "%{prj.name}/src/leopch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		-- include spdlog
		"%{prj.name}/src/",
		"%{prj.name}/vendor/spdlog/include/"
	}

	-- on windows
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"

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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	-- Debug config
	filter "configurations:Debug"
		defines "LEO_DEBUG"
		symbols "On"

	-- Release config
	filter "configurations:Release"
		defines "LEO_RELEASE"
		optimize "On"

	-- Dist config
	filter "configurations:Dist"
		defines "LEO_DIST"
		optimize "On"

-- SANDBOX PROJECT
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		-- include spdlog
		"LeoEngine/vendor/spdlog/include/",
		"LeoEngine/src"
	}

	links
	{
		"LeoEngine"
	}

	-- on windows
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"

		-- windows version
		systemversion "latest"

		defines
		{
			-- macros
			"LEO_PLATFORM_WINDOWS"
		}

	-- Debug config
	filter "configurations:Debug"
		defines "LEO_DEBUG"
		symbols "On"

	-- Release config
	filter "configurations:Release"
		defines "LEO_RELEASE"
		optimize "On"

	-- Dist config
	filter "configurations:Dist"
		defines "LEO_DIST"
		optimize "On"