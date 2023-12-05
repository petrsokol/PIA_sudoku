cmake_minimum_required(VERSION 3.26)
project(PIA_sudoku)

set(CMAKE_CXX_STANDARD 23)

add_executable(PIA_sudoku main.cpp
        Board.cpp
        Board.h
        RecursiveSolver.cpp
        RecursiveSolver.h
        Creator.cpp
        Creator.h)
