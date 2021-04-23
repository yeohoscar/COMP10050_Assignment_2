//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include <stdbool.h>
#include "checkMove.h"
#include "dataStructures.h"

bool showValidMoves() {
    bool existValidMove = false;

    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (board.gameBoard[i][j] == VALID) {
                board.gameBoard[i][j] = EMPTY;
            }

            if (board.gameBoard[i][j] == EMPTY) {
                if (checkMove((int) i, (int) j, false)) {
                    existValidMove = true;
                    board.gameBoard[i][j] = VALID;
                }
            }
        }
    }

    return existValidMove;
}

bool checkMove(int row, int column, bool flip) {
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

    if ((board.gameBoard[row][column] != EMPTY && board.gameBoard[row][column] != VALID) || !(isOnBoard(row, column))) {
        return false;
    }

    else {
        board.gameBoard[row][column] = EMPTY;
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
            x += xChange;
            y += yChange;

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
                    validMove = true;

                    if (flip) {
                        while (!(x == row && y == column)) {
                            x -= xChange;
                            y -= yChange;
                            board.gameBoard[x][y] = *move;
                        }
                    }
                }
            }
        }

        return validMove;
    }
}

bool isOnBoard(int x, int y) {
    return x < 8 && x > -1 && y < 8 && y > -1;
}