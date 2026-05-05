cmake_minimum_required(VERSION 3.10)
project(project)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(my_app 
    src/main.cpp
    src/filesystem/filesystem.cpp
    src/tables/ProcessModelTable.cpp
)

target_include_directories(my_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(my_app Qt5::Widgets)
