//
// Created by petrs on 24.10.2023.
//

#include "Board.h"

#include <utility>
#include <cmath>

using namespace std;

Board::Board() = default;

Board::Board(vector<int> board) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            Board::board[r][8-c] = int(board[r] / pow(10, c)) % 10; //8-c, jinak zrcadlově
        }
    }
}

Board::Board(vector<vector<int>> board) {
    Board::board = std::move(board);
}

//Board clue17("........1.....2.3...4.56.........45..1........7..8.......1....7..5....8.3....9...");
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


int Board::getS(int r, int c) {
    return board[r][c];
}

bool Board::isEmpty(int r, int c) {
    return board[r][c] == 0;
}

void Board::set(int r, int c, int n) {
    board[r][c] = n;
}