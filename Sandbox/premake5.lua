-- SANDBOX PROJECT
project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	staticruntime "on"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/LeoEngine/vendor/spdlog/include",
		"%{wks.location}/LeoEngine/src"
	}

	links
	{
		"LeoEngine"
	}

	-- on windows
	filter "system:windows"
		cppdialect "C++17"

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