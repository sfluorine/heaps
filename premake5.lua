workspace "Heaps"
    configurations { "Debug", "Release" }

project "Heaps"
    kind "ConsoleApp"
    language "C"

    targetdir "bin/%{cfg.buildcfg}"

    files { "src/**.c", "src/**.h" }
    includedirs { "vendor/" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NODEBUG" }
        optimize "On"
