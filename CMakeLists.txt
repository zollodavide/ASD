cmake_minimum_required(VERSION 3.6)
project(ListaEOperazioni)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lista.h)
add_executable(ListaEOperazioni ${SOURCE_FILES})