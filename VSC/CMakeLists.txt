cmake_minimum_required(VERSION 3.23)
project(VSC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(VSC
        ArbolBinarioAVL.h
        articulo.cpp
        articulo.h
        main.cpp
        NodoArbolAVL.h
        prueba.cpp)
