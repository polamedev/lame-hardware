cmake_minimum_required(VERSION 3.21)

enable_language(CXX)

add_library(lame-drivers INTERFACE)
add_library(lame::drivers ALIAS lame-drivers)

target_include_directories(lame-drivers
    # Пути включения доступные gользователям
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
)
