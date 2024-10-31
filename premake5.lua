workspace "sirius-gcs"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "sirius-gcs"

project "sirius-gcs"
    kind "ConsoleApp"
    language "C++"
    targetdir "out/%{cfg.buildcfg}"

    includedirs {
        "src/gui",
        "src/logging"
    }

    files { "src/**.h", "src/**.cpp" }

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