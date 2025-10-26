cmake_minimum_required(VERSION 3.21)

# Основные настройки проекта
project(
    lame-hardware
    VERSION 1.0.0
    DESCRIPTION
        "Lame hardware lib"
    LANGUAGES C
)

# Определяем является ли текущий проектом верхнего уровня. Для fetch проектов, gitsubmodule или просто вложенных проектов это неверно
# string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)
# Но в новых версиях 3.21 можно использовать ${PROJECT_IS_TOP_LEVEL}

# -----------------------------------------------------------------------------------------------------------------------------------
# Настройка сборки библиотеки
# -----------------------------------------------------------------------------------------------------------------------------------

# Опции сборки
option(Lame_Hardware_BUILD_TESTS    "Build lame::hardware tests"         OFF)  # Нужно ли собирать тесты для библиотеки
# option(Lame_Hardware_BUILD_EXAMPLES "Build lame::hardware examples"      OFF)  # Нужно ли собирать примеры
# option(Lame_Hardware_BUILD_DOCS     "Build lame::hardware documentation" OFF)  # Нужно ли собирать документацию

# Установка типа сборки
if(NOT CMAKE_BUILD_TYPE)
    # Установить переменную CMAKE_BUILD_TYPE и сохранить в кэше
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
    # Устанавливаем для CMAKE_BUILD_TYPE возможные значения, которые можно будет выбрать через cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()


# Добавление суфикса в имя дебажной библиотеки, нужно чтобы установить различия в названии. Возможно от этого стоит отказаться
set(CMAKE_DEBUG_POSTFIX -dev)

# -----------------------------------------------------------------------------------------------------------------------------------
# Добавление других таргетов
# -----------------------------------------------------------------------------------------------------------------------------------

add_subdirectory(drivers)
set(Lame_Device_BUILD_TESTS ON)
add_subdirectory(device)


# if(Lame_Hardware_BUILD_TESTS)
#     message(STATUS "Включено тестирование библиотеки")
#     # enable_testing()
#     # add_subdirectory(tests)
# endif()
