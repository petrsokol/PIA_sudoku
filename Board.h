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

/*
 * getRow(int row)
 * return array<int, 9> //vektory
 *
 * getColumn(int col)
 * return array<int, 9>
 *
 * getBox(int k) //
 * return array<array< int, 3>, 3>
 *
 * int getSquare(int row, int col)
 * return int square
 *
 * void setSquare(int row, int col)
 *
 * void setSquareGuess(int row, int col)
 *
 * vector<int> getValid(int row, int col);
 *
 * bool isValid()
 * bool isEmpty(int row, int col)
 * bool isPlayerPlaced(int row, int col) //který čísla položil hráč a který byly zadaný
 */

class Board {
public:
    Board();
    Board(string data);
    Board(vector<int> board);
    Board(vector<vector<int>> board);

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
private:
    //board - vektor vektorů, něco jako vector<vector< int, 9>, 9>

};


#endif //PIA_SUDOKU_BOARD_H
