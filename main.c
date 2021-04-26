#include <stdio.h>
#include "game.h"
#include "dataStructures.h"
#include "print.h"
#include "checkMove.h"

int main(void) {
    gameStart();
    runGame();
    return 0;
}

void writeResults() {
    FILE *fp;

    if ((fp = fopen("othello-results.txt", "a+")) == NULL) {
        printf("Error opening file.");
        exit(0);
    } else {
        time_t t;
        time(&t);

        fprintf(fp, "%s Winner: %s Score: %s (%c) %d:%d %s (%c)", ctime(&t), !winner!, player1.name, player1.colour, player1.score, player2.score, player2.name, player2.colour);
        fclose(fp);
    }
}