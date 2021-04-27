//
// Created by yeoho on 16/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "print.h"
#include "dataStructures.h"

void printBoard() {
    printf("\nScore: %s (%c) %d:%d %s (%c)", player1.name, player1.colour, player1.score, player2.score, player2.name, player2.colour);

    for (size_t i = 0; i < 8; i++) {
        printf("\n   --- --- --- --- --- --- --- --- \n");
        printf("%u ", i + 1);

        for (size_t j = 0; j < 8; j++) {
            printf("| %c ", board.gameBoard[i][j]);
        }

        printf("|");
    }

    printf("\n   --- --- --- --- --- --- --- --- \n");
    printf("    a   b   c   d   e   f   g   h  ");
}

void printResults() {
    FILE *fp;

    if ((fp = fopen("othello-results.txt", "a+")) == NULL) {
        printf("Error opening file.");
        exit(0);
    } else {
        time_t t;
        time(&t);
        char *currTime = ctime(&t);
        currTime[strcspn(currTime, "\n")] = '\0';

        if (player1.score > player2.score) {
            fprintf(fp, "%s - Winner: %s - Score: %s (%c) %d:%d %s (%c)\n", currTime, player1.name, player1.name, player1.colour, player1.score, player2.score, player2.name, player2.colour);
        }

        else if (player1.score < player2.score) {
            fprintf(fp, "%s - Winner: %s - Score: %s (%c) %d:%d %s (%c)\n", currTime, player2.name, player1.name, player1.colour, player1.score, player2.score, player2.name, player2.colour);
        }

        else {
            fprintf(fp, "%s - Draw - Score: %s (%c) %d:%d %s (%c)\n", currTime, player1.name, player1.colour, player1.score, player2.score, player2.name, player2.colour);
        }

        fclose(fp);
    }
}