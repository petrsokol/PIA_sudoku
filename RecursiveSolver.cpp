//
// Created by petrs on 11.11.2023.
//

#include "RecursiveSolver.h"

#include <random>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

RecursiveSolver::RecursiveSolver(Board board) {
    solutions = 0;
    RecursiveSolver::board = std::move(board);
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int n;
            if ((n = RecursiveSolver::board.getS(r,c)) != 0) {
                updatePos(r, c, n-1);
            }
        }
    }
}

int RecursiveSolver::nextRow(int r, int c) {
    return r + (c + 1) / 9;
}

int RecursiveSolver::nextCol(int c) {
    return (c + 1) % 9;
}

pair<int, int> RecursiveSolver::nextEmptyPos(int r, int c) {
    while(r != 9) {
        if (board.isEmpty(r, c)) {
            return {r, c};
        }
        r = nextRow(r, c); //move to next empty position
        c = nextCol(c);
    }
    return {9,0};
}

bool RecursiveSolver::solve(int rStart, int cStart, bool isRandom) {
    // Create a vector with initial values
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8};

    if (isRandom) {
        // Use a random number generator engine to shuffle the vector
        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(vec.begin(), vec.end(), g);
    }

    auto [r, c] = nextEmptyPos(rStart, cStart);
    if (r == 9) {
        solutions++;
        cout << endl << "found solution " << solutions << "/x" << endl;
//        show();
        if (isRandom || solutions > 10) {
            return true;
        }
    }

    int s = getCell(r, c);
    bitset<9> contains = rows[r] | cols[c] | sqrs[s];
    if (contains.all()) {return false;}

    for (int digit = 0; digit < 9; ++digit) {
        if (!contains[vec[digit]]) {
            board.set(r, c, vec[digit] + 1);
            updatePos(r, c, vec[digit]);
            if (solve(r, c, isRandom)) {
                return true;
            }
            undoPos(r, c, vec[digit]);
        }
    }
    board.set(r, c, 0);
    return false;
}

void RecursiveSolver::updatePos(int r, int c, int digit) {
    int s = getCell(r, c);
    rows[r].set(digit);
    cols[c].set(digit);
    sqrs[s].set(digit);
}

void RecursiveSolver::undoPos(int r, int c, int digit) {
    int s = getCell(r, c);
    rows[r].reset(digit);
    cols[c].reset(digit);
    sqrs[s].reset(digit);
}

void RecursiveSolver::show() {
    for (int i = 0; i < 9*9; ++i) {
        if (i%3 == 0 && i != 0) {
            cout << "| ";
        }
        if (i%9 == 0 && i != 0) {
            cout << endl;
        }
        if (i%81 == 27 || i%81 == 54) {
            cout << "------+-------+-------+ " << endl;
        }
        if (board.isEmpty(i/9, i%9)) {
            cout << ". ";
        } else {
            cout << board.getS(i/9, i%9) << " ";
        }
    }
    cout << "|" << endl;
}

int RecursiveSolver::getCell(int r, int c) {
    return (r / 3) * 3 + c / 3;
}

void RecursiveSolver::solveSudoku(bool isRandom) {
    solve(0, 0, isRandom);
    if (!isRandom) {
        if (solutions == 0) {
            cout << "this sudoku does not have a solution." << endl;
        } else if (solutions == 1) {
            cout << "this sudoku has a unique solution." << endl;
        } else if (solutions <= 10) {
            cout << "this sudoku has " << solutions << " solutions." << endl;
        } else {
            cout << "this sudoku has more than 10 solutions." << endl;
        }
    }
}

/**
 * create() method starts with an empty board and fills it randomly within constraints.
 */
Board RecursiveSolver::create() {
    Board empty(".................................................................................");
    RecursiveSolver solver(empty);
    solver.solveSudoku(true);
    return solver.board;
}

