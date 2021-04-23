//
// Created by yeoho on 16/04/2021.
//

#ifndef ASSIGNMENT_2_CHECKMOVE_H
#define ASSIGNMENT_2_CHECKMOVE_H

#include <stdbool.h>
#include "dataStructures.h"

bool showValidMoves();
bool checkMove(int row, int column, bool flip);
bool isOnBoard(int x, int y);

#endif //ASSIGNMENT_2_CHECKMOVE_H
