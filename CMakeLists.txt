cmake_minimum_required(VERSION 3.16)

project(DubWriter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Core library
add_library(DubWriterCore STATIC
    src/core/DocumentModel.cpp
    src/core/DocumentModel.h
)

target_link_libraries(DubWriterCore
    Qt6::Core
)

target_include_directories(DubWriterCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
)

# UI library
add_library(DubWriterUI STATIC
    src/ui/MainWindow.cpp
    src/ui/MainWindow.h
)

target_link_libraries(DubWriterUI
    DubWriterCore
    Qt6::Widgets
)

target_include_directories(DubWriterUI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
)

# Main application
add_executable(DubWriter
    src/main.cpp
)

target_link_libraries(DubWriter
    DubWriterCore
    DubWriterUI
    Qt6::Widgets
)
