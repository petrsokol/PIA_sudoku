//
// Created by petrs on 05.12.2023.
//

#ifndef PIA_SUDOKU_CREATOR_H
#define PIA_SUDOKU_CREATOR_H


#include "Board.h"

class Creator {

public:
    static Board create();

    static Board subtract(int n, Board board);

    static bool check(Board board);
};


#endif //PIA_SUDOKU_CREATOR_H
