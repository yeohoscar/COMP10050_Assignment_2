//
// Created by yeoho on 16/04/2021.
//

#ifndef ASSIGNMENT_2_CHECKMOVE_H
#define ASSIGNMENT_2_CHECKMOVE_H

#include "dataStructures.h"

void checkMove(int row, int column);
void checkRow(int row, int column, PieceColour otherPiece, PieceColour move);
bool isOnBoard(int x, int y);

#endif //ASSIGNMENT_2_CHECKMOVE_H
