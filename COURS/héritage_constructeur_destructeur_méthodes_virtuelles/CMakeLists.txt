cmake_minimum_required (VERSION 3.9)

project(Shape)

if(NOT MSVC)
    link_libraries(m) #to link with libm on Unix 
endif()

if(MSVC)
  add_compile_options( /W4 /WX)
else()
    add_compile_options( -Wall -Wextra -Wpedantic -Werror)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable (Shape "shape.cpp" "main.cpp")

