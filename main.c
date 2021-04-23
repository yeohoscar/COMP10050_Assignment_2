#include <stdio.h>
#include "initialise.h"
#include "dataStructures.h"
#include "print.h"
#include "checkMove.h"

int main(void) {
    gameStart();
    showValidMoves();
    checkMove(2,4,true);
    printBoard();

    return 0;
}
