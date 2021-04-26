//
// Created by yeoho on 23/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "checkMove.h"
#include "print.h"

void gameStart() {
    printf("Player 1, please enter your name: ");
    scanf("%s", player1.name);
    player1.colour = BLACK;

    printf("Player 2, please enter your name: ");
    scanf("%s", player2.name);
    player2.colour = WHITE;


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
    player1.existValidMove = true;
    player2.score = 2;
    player2.existValidMove = true;

    currentPlayer = &player1;
}

void runGame() {
    int row, column;
    char passInput;

    while (!gameOver()) {
        if (!showValidMoves()) {
            while (passInput != 'p') {
                printf("No available moves. Please enter 'p' to pass");
                scanf("%c", &passInput);
            }

        } else {
            printBoard();

            do {
                getMove(&row, &column);
            } while (!checkMove(row, column, true));
        }

        if (&(*currentPlayer) == &player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }

        passInput = 'a';
    }
}

void getMove(int *row, int *column) {
    char input[2];
    char *alphaColumn;

    printf("\nPlease enter a move (Format: '1d'): ");
    fflush(stdin);
    fgets(input, 3, stdin);

    *row = strtol(input, &alphaColumn, 10) - 1;
    *column = (int)(*alphaColumn) - 'a';
}

bool gameOver() {
    if ((player1.score + player2.score == 64) || (player1.existValidMove == false && player2.existValidMove == false)) {
        return true;
    } else {
        return false;
    }
}