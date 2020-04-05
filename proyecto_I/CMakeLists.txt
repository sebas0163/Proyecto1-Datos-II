cmake_minimum_required(VERSION 3.5)

project(proyecto_I LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(proyecto_I
  main.cpp
  Nodo.hpp
  Lista.hpp
)
target_link_libraries(proyecto_I Qt5::Core)
