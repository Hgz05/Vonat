cmake_minimum_required(VERSION 3.31)
project(NHFClion)

set(CMAKE_CXX_STANDARD 11)

add_executable(NHFClion main.cpp
        Ido.cpp
        Jarat.cpp
        Menetrend.cpp
        Vonat.cpp
        Ules.cpp
        Kocsi.cpp
        Jegy.cpp
        HelyJegy.cpp
        Allomas.cpp)
