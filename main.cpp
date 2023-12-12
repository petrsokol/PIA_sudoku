#include <iostream>
#include "Board.h"
#include "RecursiveSolver.h"
#include "Creator.h"


int main() {

    std::cout << "DOBRÝ DEN!!!!! \n";

    // example boards for testing the RecursiveSolver performance
    Board clue17("........1.....2.3...4.56.........45..1........7..8.......1....7..5....8.3....9...");
    Board kaggle(".....48...1.2367..5.3.176.93..5.....1.942...6.751.8..2.9...5..7..2...43.7..68.9.1");
    Board biased("...9.45.8..........89.32..4.746.523...5...4..3...47...6...5.....127..6....8.....1");
    Board multi ("2957438614318659..8761925433874592166123894955492167387635341899286713541549386..");
    Board hassen("...6..4..7....36......91.8...........5.18...3...3.6.45.4.2...6.9.3.......2....1..");
    Board empty (".................................................................................");
    Board master(".37.8.5.9..6.........1..8..6...3.....534...7.1.......5.....2.4..98.1...75........");
    Board wrong ("337.8.5.9..6.........1..8..6...3.....534...7.1.......5.....2.4..98.1...75........");

    RecursiveSolver rSolver(wrong);
    rSolver.show();
    rSolver.solveSudoku(false); //solver runs faster with randomness turned off (isRandom = false)
    std::cout << rSolver.solutions << std::endl;

    Board custom = Creator::create();
    Board reduced = Creator::subtract(60, custom);
    RecursiveSolver solver(reduced);
    solver.solveSudoku(false);

    return 0;

}