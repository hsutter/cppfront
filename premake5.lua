workspace "cppfront"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "cppfront"
	kind "ConsoleApp"
	language "C++" -- "C", "C++", "C#"
	cppdialect "C++latest"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files { "source/*.cpp", "source/*.h", "include/*.h", "*.*", "passthrough-tests/*.*", "regression-tests/**" }

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		defines { "DEBUG" }

	filter "configurations:Release"
		runtime "Release"
		optimize "on" -- "on", "off", "Debug", "Size", "Speed", "Full"
		defines { "NDEBUG" }

	filter "configurations:*32"
		architecture "x86"

	filter "configurations:*64"
		architecture "x86_64"