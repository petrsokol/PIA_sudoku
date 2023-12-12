//
// Created by petrs on 05.12.2023.
//

#ifndef PIA_SUDOKU_CREATOR_H
#define PIA_SUDOKU_CREATOR_H


#include "Board.h"

/**
 * A class for creating sudoku problems for people to solve
 */
class Creator {

public:
    static Board create();

    static Board subtract(int n, Board board);

    static bool check(Board board);
};


#endif //PIA_SUDOKU_CREATOR_H
