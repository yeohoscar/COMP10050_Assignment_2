//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include <stdbool.h>
#include "checkMove.h"
#include "dataStructures.h"

void checkMove(int row, int column) {
    if (board.gameBoard[row - 1][column - 'a'] != EMPTY || isOnBoard(row - 1, column - 'a')) {
        printf("This move is not valid.\n");
        return;
    }

    else {
        PieceColour *move = &board.turnColour;
        PieceColour otherPiece;

        if (*move == WHITE) {
            otherPiece = BLACK;
        }

        else {
            otherPiece = WHITE;
        }

        checkRow(row, column, otherPiece, move);
    }

}

void checkRow(int row, int column, PieceColour otherPiece, PieceColour move) {
    column++;

    if (isOnBoard(row, column) && board.gameBoard[row][column] == otherPiece) {
        column++;

        if (!(isOnBoard(row, column))) {
            return;
        }

        while (board.gameBoard[row][column] == otherPiece) {
            column++;

            if (!(isOnBoard(row, column))) {
                return;
            }
        }

        if (board.gameBoard[row][column] == move) {
            printf("This is a valid move.");
        }

        else {
            printf("This move is not valid.");
        }
    }
}

bool isOnBoard(int x, int y) {
    return x < 8 && x > -1 && y < 8 && y > -1;
}