cmake_minimum_required(VERSION 3.5)

project(proyecto_I LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-pthread)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


find_package(Qt5Core)

add_executable(proyecto_I
  main.cpp
  Nodo.hpp
  Lista.hpp
  VSPtr.hpp
  garbagecollector.cpp
  garbagecollector.hpp
  singleton.cpp
  singleton.hpp
  puntero.hpp
  puntero.cpp
  cliente.cpp
  cliente.hpp

)
target_link_libraries(proyecto_I Qt5::Core)
