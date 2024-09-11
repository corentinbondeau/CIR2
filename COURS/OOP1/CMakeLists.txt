cmake_minimum_required(VERSION 3.9)
project(TP)

# Créé l'exécutable pour ce sous projet 
add_executable(main_cpp main_cpp.cpp "main_cpp.cpp" shape_cpp shape_cpp.cpp "shape_cpp.cpp" bad_assert bad_assert.h "bad_assert.h" shape_cpp shape_cpp.hpp "shape_cpp.hpp")


