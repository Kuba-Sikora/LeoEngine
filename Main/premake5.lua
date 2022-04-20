-- MAIN PROJECT
project "Main"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/LeoEngine")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/LeoEngine")

	staticruntime "on"

	files
	{
		"src/**.hpp",
		"src/**.cpp"
	}

	includedirs
	{
		"%{includeDir.spdlog}",
		"%{includeDir.GLFW}",
		"%{wks.location}/Application/src",
		"%{wks.location}/Editor/src",
		"%{wks.location}/Framework/src"
	}

	links
	{
		"Application",
        "Editor",
		"Framework"
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