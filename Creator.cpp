//
// Created by petrs on 05.12.2023.
//

#include "Creator.h"

#include <utility>
#include <random>
#include <iostream>
#include "RecursiveSolver.h"

/**
 * creates a random filled (completed) sudoku board - a starting point for sudoku setting.
 *
 * The algorithm proceeds to take away squares until the solution is no longer unique, at which point it stops.
 *
 * @return a full valid board of numbers assorted randomly according to rules
 */
Board Creator::create() {
    Board empty(".................................................................................");
    RecursiveSolver solver(empty);
    solver.solveSudoku(true);
    return solver.board;
}

/**
 * Takes a sudoku board (usually created by a method Creator::create()) and takes away numbers until the solution for
 * this given board is no longer unique
 *
 * @param n maximum number of subtractions
 * @param board sudoku board which is to be reduced to a unique solution
 * @return returns a partially filled sudoku board which has a guaranteed unique solution
 *
 * @author Péťa Sokol
 */
Board Creator::subtract(int n, Board board) {
    bool unique = check(board);
    int subtractions = 0;
    Board last = board;
    while (unique && subtractions < n) {
        subtractions++;

        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the distribution for integers in the range [0, 8]
        std::uniform_int_distribution<> dis(0, 8);

        // Generate a random integer
        int r = dis(gen);
        int c = dis(gen);

        board.set(r, c, 0);
        unique = check(board);
        if (unique) {
            last = board;
        }
    }
    RecursiveSolver solver(last);
    solver.show();
    std::cout << "subtracted " << subtractions << " numbers \n";
    return last;
}

/**
 * Checks if the given sudoku board has a unique solution or not
 * @param board board, which you want to check for its unique solution
 * @return true: given sudoku board has a single unique solution
 */
bool Creator::check(Board board) {
    RecursiveSolver solver(std::move(board));
    solver.solveSudoku(false);
    return solver.solutions == 1;
}
