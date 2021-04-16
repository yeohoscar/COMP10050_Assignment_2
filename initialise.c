//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include "initialise.h"
#include "dataStructures.h"

void gameStart() {
    printf("Player 1, please enter your name: ");
    scanf("%s", player1.name);
    player1.colour = WHITE;

    printf("Player 2, please enter your name: ");
    scanf("%s", player2.name);
    player2.colour = BLACK;


    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            board.gameBoard[i][j] = EMPTY;
        }
    }

    board.gameBoard[3][3] = WHITE;
    board.gameBoard[3][4] = BLACK;
    board.gameBoard[4][3] = BLACK;
    board.gameBoard[4][4] = WHITE;

    player1.score = 2;
    player2.score = 2;

    board.turnColour = player1.colour;
}
