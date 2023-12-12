//
// Created by petrs on 11.11.2023.
//

#include "RecursiveSolver.h"

#include <random>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Constructor
 * @param board inputs board which the solver then solves
 */
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

/**
 * gives an integer of the next row
 * @param r row of the current position
 * @param c column of the current position
 * @return This method only returns a new row if the current column is the last column.
 */
int RecursiveSolver::nextRow(int r, int c) {
    return r + (c + 1) / 9;
}

/**
 * gives an integer of the next column
 * @param c current column
 * @return returns a column integer next to the current one, or 1, if the last one was 9 - right-most column
 */
int RecursiveSolver::nextCol(int c) {
    return (c + 1) % 9;
}

/**
 * This method iterates on the board until it finds next empty position, given the starting position.
 *
 * It iterates through columns and jumps to the next row at the end of a column
 *
 * If the board is completely full, it returns a value "out of bounds", which is checked elsewhere for program termination
 * @param r current row
 * @param c current column
 * @return returns a pair of integers of indicating the next empty square on the sudoku board
 */
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

/**
 * a recursive algorithm to solve a given sudoku board.
 *
 * If the current recursion level finds a flaw, the method returns
 * false and the level above it tries to input next number from the list.
 *
 * Once the method fills all the empty positions, the last recursion level returns a bool true, which goes up the chain
 * of recursion until the program finishes
 *
 * @param rStart row, where the next recursion starts
 * @param cStart column, where the next recursion starts
 * @param isRandom used for generating non-trivial boards stemming from an empty board preset.
 * @return informs the recursion level above whether this configuration is valid
 */
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
        if (isRandom || solutions > 10) {
            return true;
        }
    }

    int s = getCell(r, c);
    bitset<9> contains = rows[r] | cols[c] | sqrs[s];
    if (contains.all()) {return false;} //when there are two same numbers in a given row, column or 3x3 cell

    //main recursion loop
    for (int digit = 0; digit < 9; ++digit) {
        if (!contains[vec[digit]]) {
            board.set(r, c, vec[digit] + 1);
            updatePos(r, c, vec[digit]);
            if (solve(r, c, isRandom)) { //goes a level deeper
                return true; //if the previous level is true, so is this one
            }
            undoPos(r, c, vec[digit]);
            // if the lower recursion level is false (not a legal sudoku configuration), this undoes the wrong step
        }
    }
    board.set(r, c, 0);
    return false; // all options on this level of recursion were exhausted, there is a mistake somewhere earlier
}

/**
 * updates the bitsets which allow the algorithm to check for neighbouring numbers
 * in the current row, column and 3x3 cell
 *
 * @param r row you want to update
 * @param c column you want to update
 * @param digit the number you want to insert at the chosen position
 */
void RecursiveSolver::updatePos(int r, int c, int digit) {
    int s = getCell(r, c);
    rows[r].set(digit);
    cols[c].set(digit);
    sqrs[s].set(digit);
}

/**
 * takes the digit from the chosen row, column and 3x3 cell - updates the bitsets
 * @param r row you want to update
 * @param c column you want to update
 * @param digit number you want to take away from the bitsets
 */
void RecursiveSolver::undoPos(int r, int c, int digit) {
    int s = getCell(r, c);
    rows[r].reset(digit);
    cols[c].reset(digit);
    sqrs[s].reset(digit);
}

/**
 * shows the board at the current state
 */
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

/**
 * returns the index of a 3x3 cell based on the input row and column
 * @param r row inside the 3x3 cell
 * @param c column inside the 3x3 cell
 * @return an index from 0-8 starting at row=0 and column=0
 */
int RecursiveSolver::getCell(int r, int c) {
    return (r / 3) * 3 + c / 3;
}

/**
 * solves a given sudoku board, either randomly (used for boards that start off completely empty),
 * or not, which is faster
 *
 * It then informs about the number of found solutions
 *
 * @param isRandom determines if the solution should look more random
 */
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