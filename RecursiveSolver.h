//
// Created by petrs on 11.11.2023.
//

#ifndef PIA_SUDOKU_RECURSIVESOLVER_H
#define PIA_SUDOKU_RECURSIVESOLVER_H

#include <array>
#include <bitset>
#include <vector>
#include "Board.h"

using namespace std;


class RecursiveSolver {

public:
    explicit RecursiveSolver(Board board);
    void show();
    void solveSudoku();
private:
    bool solve(int rStart, int cStart);

    Board board;

    array<bitset<9>, 9> rows = {0};
    array<bitset<9>, 9> cols = {0};
    array<bitset<9>, 9> sqrs = {0};

    static int nextRow(int r, int c);
    static int nextCol(int c);
    static int getCell(int r, int c);
    pair<int, int> nextEmptyPos(int r, int c);

    void updatePos(int r, int c, int digit);
    void undoPos(int r, int c, int digit);

    int solutions = 0;
};


#endif //PIA_SUDOKU_RECURSIVESOLVER_H
