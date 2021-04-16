//
// Created by yeoho on 16/04/2021.
//

#ifndef ASSIGNMENT_2_DATASTRUCTURES_H
#define ASSIGNMENT_2_DATASTRUCTURES_H

typedef enum othelloColour {
    BLACK = 'B',
    WHITE = 'W',
    EMPTY = ' ',
} PieceColour;

typedef struct board {
    char gameBoard[8][8];
    int turn;
} Board;

typedef struct player {
    char name[20];
    PieceColour colour;
    int score;
} Player;

Player player1, player2;
Board board;

#endif //ASSIGNMENT_2_DATASTRUCTURES_H
