cmake_minimum_required(VERSION 3.10) # Проверка версии CMake.
                                     # Если версия установленой программы
                                     # старее указаной, произайдёт аварийный выход.

project(includes) # Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(SOURCE_LIB my_strings.cpp) # Установка переменной со списком исходников

add_library(includes STATIC ${SOURCE_LIB}) # Создание статической библиотеки
