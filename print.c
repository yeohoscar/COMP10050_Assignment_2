//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include "print.h"
#include "dataStructures.h"

void printBoard() {
    printf("Score: %s (%c) %d:%d %s (%c)", player1.name, player1.colour, player1.score, player2.score, player2.name, player2.colour);

    for (size_t i = 0; i < 8; i++) {
        printf("\n   --- --- --- --- --- --- --- --- \n");
        printf("%u ", i + 1);

        for (size_t j = 0; j < 8; j++) {
            printf("| %c ", board.gameBoard[i][j]);
        }

        printf("|");
    }

    printf("\n   --- --- --- --- --- --- --- --- \n");
    printf("    a   b   c   d   e   f   g   h  ");
}
