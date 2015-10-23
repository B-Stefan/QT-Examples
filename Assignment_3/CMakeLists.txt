# Reference: http://qt-project.org/doc/qt-5.0/qtdoc/cmake-manual.html

set(SOURCE_FILES
    src/main.cc
    src/mainwindow.h
    src/Player.h
    src/Player.cpp
    src/Puck.cpp
    src/Puck.h
    src/Game.cpp
    src/Game.h
    src/mainwindow.cc
)

if (WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} win/example.rc)
endif ()

set(UI_FILES
    ui/mainwindow.ui
)
source_group("UI Files" FILES ${UI_FILES})
qt5_wrap_cpp(HEADERS_MOC ${SOURCE_FILES})
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
source_group("Generated UI Headers" FILES ${UI_HEADERS})
include_directories(src/)
qt5_add_resources(RESOURCE_FILES example.qrc)

if (APPLE)
    set(SOURCE_FILES ${SOURCE_FILES} AppIcon.icns)
    set_source_files_properties(AppIcon.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
endif ()

add_executable("${PROJECT}-Pong-Game" MACOSX_BUNDLE
    ${SOURCE_FILES}
    ${UI_HEADERS}
    ${UI_FILES}
    ${RESOURCE_FILES}
)


qt5_use_modules("${PROJECT}-Pong-Game" Widgets)

if (MSVC)
    set_target_properties("${PROJECT}-Pong-Game"  PROPERTIES
        WIN32_EXECUTABLE YES
        LINK_FLAGS "/ENTRY:mainCRTStartup"
    )
endif ()
