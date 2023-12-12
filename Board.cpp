//
// Created by petrs on 24.10.2023.
//

#include "Board.h"

#include <utility>
#include <cmath>
#include <iostream>

using namespace std;

Board::Board() = default;

/**
 * Constructor
 * @param data string of length 81 - either number from 1-9 or "." for empty square
 */
Board::Board(string data) {
    int n;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == '.') {
            n = 0;
        } else {
            n = int(unsigned(data[i])) - 48;
        }
        board[i/9][i%9] = n;
    }
}

/**
 * returns an index of a 3x3 cell in which the [row, column] square is located
 * @param r (int) chosen row
 * @param c (int) chosen column
 * @return number of a 3x3 at corresponding row and column
 */
int Board::getS(int r, int c) {
    return board[r][c];
}

/**
 *
 * @param r board row
 * @param c board column
 * @return true -> square at row, column does not have a value
 */
bool Board::isEmpty(int r, int c) {
    return board[r][c] == 0;
}

/**
 *
 * @param r board row
 * @param c board column
 * @param n number you want to set at corresponding [row, column]
 */
void Board::set(int r, int c, int n) {
    board[r][c] = n;
}
