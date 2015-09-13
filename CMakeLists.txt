cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0020 NEW)
set(CMAKE_PREFIX_PATH "/usr/local/opt/qt5/")

set(PROJECT "QT-Assignments")

project(${PROJECT})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)


find_package(Qt5Widgets REQUIRED)


set(MACOSX_BUNDLE_BUNDLE_NAME "Example")
set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_COPYRIGHT "Copyright (c) 2015")
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.QTExample")
set(MACOSX_BUNDLE_ICON_FILE AppIcon.icns)

# Add sub projects
add_subdirectory("Assignment_1")
add_subdirectory("_example")
