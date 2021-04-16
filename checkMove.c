//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include <stdbool.h>
#include "checkMove.h"
#include "dataStructures.h"

void checkMove(int row, int column) {
    bool validMove = false;
    int direction[8][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
            {1, 1},
            {-1, 1},
            {1, -1},
            {-1, -1},
    };

    if (board.gameBoard[row][column] != EMPTY || isOnBoard(row, column)) {
        printf("This move is not valid.\n");
        return;
    }

    else {
        PieceColour *move = &board.turnColour;
        PieceColour otherPiece;

        if (*move == WHITE) {
            otherPiece = BLACK;
        } else {
            otherPiece = WHITE;
        }

        for (size_t i = 0; i < 8; i++) {
            int x = row;
            int y = column;
            int xChange = direction[i][0];
            int yChange = direction[i][1];

            if (isOnBoard(row, column) && board.gameBoard[x][y] == otherPiece) {
                x += xChange;
                y += yChange;

                if (!(isOnBoard(x, y))) {
                    continue;
                }

                while (board.gameBoard[x][y] == otherPiece) {
                    x += xChange;
                    y += yChange;

                    if (!(isOnBoard(x, y))) {
                        break;
                    }
                }

                if (board.gameBoard[x][y] == *move) {
                    while (x != row && y != column) {
                        x -= xChange;
                        y -= yChange;
                        board.gameBoard[x][y] = *move;
                    }

                    validMove = true;
                }
            }
        }
    }
}

bool isOnBoard(int x, int y) {
    return x < 8 && x > -1 && y < 8 && y > -1;
}