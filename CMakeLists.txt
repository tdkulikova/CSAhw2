cmake_minimum_required(VERSION 3.9)
project(Computer_System_Architecture_Hw2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(Computer_System_Architecture_Hw2 main.cpp triangle.cpp triangle.h rectangle.cpp rectangle.h figure.cpp figure.h circle.cpp circle.h random.h container.cpp container.h)
