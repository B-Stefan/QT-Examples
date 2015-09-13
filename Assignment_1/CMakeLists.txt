
set(PROJECT "Assignment_1")


##Task 1
set(SOURCE_FILES_1_1
        src/main-1-1.cc
)

add_executable("${PROJECT}-1-1" MACOSX_BUNDLE
    ${SOURCE_FILES_1_1}
)


##Task 2
set(SOURCE_FILES_1_2
        src/main-1-2.cc
)

add_executable("${PROJECT}-1-2" MACOSX_BUNDLE
        ${SOURCE_FILES_1_2}
)


##Task 3
set(SOURCE_FILES_1_3
        src/main-1-3.cc
        src/models/Book.cpp
        src/models/Book.h
)

add_executable("${PROJECT}-1-3" MACOSX_BUNDLE
        ${SOURCE_FILES_1_3}
)


##Task 4
set(SOURCE_FILES_1_4
        src/main-1-4.cc
        src/models/WeatherData.cpp
        src/models/WeatherData.h
)

add_executable("${PROJECT}-1-4" MACOSX_BUNDLE
        ${SOURCE_FILES_1_4}
)


qt5_use_modules("${PROJECT}-1-1"  Widgets)
qt5_use_modules("${PROJECT}-1-2"  Widgets)
qt5_use_modules("${PROJECT}-1-3"  Widgets)
qt5_use_modules("${PROJECT}-1-4"  Widgets)

if (MSVC)
    set_target_properties(${PROJECT} PROPERTIES
        WIN32_EXECUTABLE YES
        LINK_FLAGS "/ENTRY:mainCRTStartup"
    )
endif ()
