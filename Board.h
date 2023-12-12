//
// Created by petrs on 24.10.2023.
//

#ifndef PIA_SUDOKU_BOARD_H
#define PIA_SUDOKU_BOARD_H

#include "vector"
#include <array>
#include <map>
#include <set>
#include <unordered_set>
#include <string>

using namespace std;

class Board {
public:
    Board();
    explicit Board(string data);

    int getS(int r, int c);
    bool isEmpty(int r, int c);
    void set(int r, int c, int n);

    vector<vector<int>> board = {
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
    };
};


#endif //PIA_SUDOKU_BOARD_H
