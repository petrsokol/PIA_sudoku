//
// Created by petrs on 05.12.2023.
//

#include "Creator.h"

#include <utility>
#include <random>
#include "RecursiveSolver.h"

Board Creator::create() {
    Board empty(".................................................................................");
    RecursiveSolver solver(empty);
    solver.solveSudoku(true);
    return solver.board;
}

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
    RecursiveSolver solver(board);
    solver.show();
    return last;
}

bool Creator::check(Board board) {
    RecursiveSolver solver(std::move(board));
    solver.solveSudoku(false);
    return solver.solutions == 1;
}
