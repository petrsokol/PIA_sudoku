# PIA_sudoku
 
A project for the CTU - PIA 1 developed by Petr Sokol and Marie Raušová. 

## Purpose
The program is primarily designed for generating unique sudoku boards for people to solve. It can also solve any sudoku configuration, determine whether a solution exist and how many there are. There are tools for inputting a sudoku board one wants to solve.

## How it works
The program first creates a full valid sudoku board and then successively removes numbers from the squares until the solution is no longer unique. If the uniqueness condition is violated, the algorithm goes back to the last unique solution, which it displays as the result. The check for uniqueness is done by solving the current configuration of the board by a recursive solver algorithm described here: [Recursive sudoku solver in C++](https://www.youtube.com/watch?v=VPVtlODPdPY). 

## Contents
This C++ project contains three classes:
* *Board* keeps track of the sudoku board itself, has methods for setting and reading its contents.
* *RecursiveSolver* is used for solving instances of the class *Board*.
* *Creator* class uses the other two to create solvable sudoku boards
