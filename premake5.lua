workspace "sirius-gcs"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "sirius-gcs"

project "sirius-gcs"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "out/%{cfg.buildcfg}"

    includedirs {
        "src/gui",
        "src/logging",
        "src/map",
        "external/mINI"
    }

    files { 
        "src/**.h",
        "src/**.cpp",
        "external/mINI/ini.h"
    }

    defines { "STB_IMAGE_IMPLEMENTATION" }

    filter "system:windows"
        buildoptions {
            "/utf-8",
            "/wd4005",
            "/wd26498",
            "/wd26800"
        }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"