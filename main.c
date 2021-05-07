//COMP10500: Assignment 2
//Oscar Yeoh 20403662

#include <time.h>
#include <string.h>
#include "game.h"
#include "print.h"

int main(void) {
    //Get current time
    time_t t;
    time(&t);
    char *currTime = ctime(&t);
    currTime[strcspn(currTime, "\n")] = '\0';

    //Run game
    gameStart();
    runGame();
    printBoard();
    printResults(currTime);

    return 0;
}