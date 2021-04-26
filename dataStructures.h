//
// Created by yeoho on 16/04/2021.
//

#ifndef ASSIGNMENT_2_DATASTRUCTURES_H
#define ASSIGNMENT_2_DATASTRUCTURES_H

#include <stdbool.h>

typedef enum othelloColour {
    BLACK = 'B',
    WHITE = 'W',
    EMPTY = ' ',
    VALID = 'X',
} PieceColour;

typedef struct board {
    char gameBoard[8][8];
} Board;

typedef struct player {
    char name[20];
    PieceColour colour;
    int score;
    bool existValidMove;
} Player;

Player player1, player2;
Player *currentPlayer;
Board board;

#endif //ASSIGNMENT_2_DATASTRUCTURES_H
