cmake_minimum_required(VERSION 3.16)
project(CyberBank VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt ni topish
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Automoc ni yoqish
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Source fayllari
set(SOURCES
    main.cpp
    mainwindow.cpp
    account.cpp
)

# Header fayllari
set(HEADERS
    mainwindow.h
    account.h
)

# UI fayllari
set(UI_FILES
    mainwindow.ui
)

# Executable yaratish
add_executable(CyberBank
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# Qt kutubxonalarini ulash
target_link_libraries(CyberBank
    Qt5::Core
    Qt5::Widgets
)

# Windows uchun qo'shimcha sozlamalar
if(WIN32)
    set_target_properties(CyberBank PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()
