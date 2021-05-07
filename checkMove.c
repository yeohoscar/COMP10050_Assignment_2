//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include <stdbool.h>
#include "checkMove.h"

//Check board for current player's valid moves
bool showValidMoves() {
    board.currentPlayer->existValidMove = false;

    //Check every cell
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (checkMove((int) i, (int) j, false)) { //checks if cell is a valid move
                board.currentPlayer->existValidMove = true; //there exists a move that can be made
                board.gameBoard[i][j] = VALID; // marks the cell as valid
            }
        }
    }

    return board.currentPlayer->existValidMove;
}

//Checks if putting a piece in the cell is a valid move
bool checkMove(int row, int column, bool flip) { //flip controls if piece are flipped. If flip is false, function only checks if move is valid. If true, pieces are flipped
    bool validMove = false;
    int direction[8][2] = { //2d array containing the change in x and y values when moving in the eight directions.
            {1, 0},   //right
            {-1, 0},  //left
            {0, 1},   //up
            {0, -1},  //down
            {1, 1},   //up and right
            {-1, 1},  //up and left
            {1, -1},  //down and right
            {-1, -1}, //down and left
    };

    if (flip && board.gameBoard[row][column] != VALID) {
        printf("Invalid move. Please try again.\n");
        return false;
    }

    if (board.gameBoard[row][column] != EMPTY && board.gameBoard[row][column] != VALID) {
        return false;
    } else {
        board.gameBoard[row][column] = EMPTY;
        PieceColour *move = &board.currentPlayer->colour;
        PieceColour otherPiece;

        if (*move == WHITE) {
            otherPiece = BLACK;
        } else {
            otherPiece = WHITE;
        }

        //checks in all eight directions
        for (size_t i = 0; i < 8; i++) {
            int x = row;
            int y = column;
            int xChange = direction[i][0];
            int yChange = direction[i][1];
            x += xChange;
            y += yChange;

            //If the next piece in the direction of the move is the opposite colour
            if (isOnBoard(x, y) && board.gameBoard[x][y] == otherPiece) {
                //Move in current direction
                x += xChange;
                y += yChange;

                if (!(isOnBoard(x, y))) { //if it goes off the board
                    continue;
                }

                //Keep moving in the direction until it is not the other colour
                while (board.gameBoard[x][y] == otherPiece) {
                    x += xChange;
                    y += yChange;

                    if (!(isOnBoard(x, y))) {
                        break;
                    }
                }

                //After the chain of other colours, if the cell contains the current player's piece
                if (board.gameBoard[x][y] == *move) {
                    validMove = true;

                    if (flip) { //If pieces are to be flipped
                        while (!(x == row && y == column)) { //move in opposite direction, flipping each piece
                            x -= xChange;
                            y -= yChange;
                            board.gameBoard[x][y] = *move;
                            board.currentPlayer->score++;
                            board.otherPlayer->score--;
                        }

                        board.otherPlayer->score++;
                    }
                }
            }
        }

        return validMove;
    }
}

//Predicate function to check if the coordinates are on the board
bool isOnBoard(int x, int y) {
    return x < 8 && x > -1 && y < 8 && y > -1;
}