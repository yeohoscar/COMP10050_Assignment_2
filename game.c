//
// Created by yeoho on 23/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "checkMove.h"
#include "print.h"

//Initialises everything needed for the game
void gameStart() {
    printf("Welcome to Othello!\n"
           "Place tiles to capture the other player's pieces.\n"
           " - Tiles can only be captured if the a tile is placed in a line containing adjecent tiles of the other colour and ending in your colour in that direction."
           "Valid moves are marked with an X.\n"
           "The game ends when neither player can make a move or the board is filled.\n\n");

    //Get player names and assigns them colours
    printf("Player 1, please enter your name: ");
    scanf("%s", player1.name);
    player1.colour = BLACK;

    printf("Player 2, please enter your name: ");
    scanf("%s", player2.name);
    player2.colour = WHITE;

    //Fills board array with empty space
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            board.gameBoard[i][j] = EMPTY;
        }
    }

    //Place the starting pieces on the board
    board.gameBoard[3][3] = WHITE;
    board.gameBoard[3][4] = BLACK;
    board.gameBoard[4][3] = BLACK;
    board.gameBoard[4][4] = WHITE;

    //Assign the starting values to the players
    player1.score = 2;
    player1.existValidMove = true;
    player2.score = 2;
    player2.existValidMove = true;

    //Set current turn to player 1
    board.currentPlayer = &player1;
    board.otherPlayer = &player2;
}

//Handles the running of the game
void runGame() {
    int row, column;
    char passInput;

    while (!gameOver()) { //Predicate function that checks if game end conditions are met
        if (!showValidMoves()) { //Scans for valid moves
            while (passInput != 'p') {
                printf("\n%s, you have no available moves. Please enter 'p' to pass", board.currentPlayer->name);
                scanf(" %c", &passInput);
            }

        } else {
            printBoard();

            do {
                getMove(&row, &column); //Gets player's move
            } while (!checkMove(row, column, true)); //Checks if move is valid. If yes, flips the pieces.
        }

        //Change current turn to the other player
        if (&(*board.currentPlayer) == &player1) {
            board.currentPlayer = &player2;
            board.otherPlayer = &player1;
        } else {
            board.currentPlayer = &player1;
            board.otherPlayer = &player2;
        }

        passInput = '\0'; //resets passInput
    }
}

//Takes in board coordinate variables and assigns user inputted coordinates to them
void getMove(int *row, int *column) {
    char input[2];
    char *alphaColumn;

    printf("\n%s, please enter a move (Format: '1d'): ", board.currentPlayer->name);
    fflush(stdin);
    fgets(input, 3, stdin); //Takes in user input as a string

    *row = strtol(input, &alphaColumn, 10) - 1; //Assigns the integer part of the string to row and subtract 1 since array starts at 0 but grid starts at 1
    *column = (int)(*alphaColumn) - 'a'; //Typecast the character part of the string to int to get ASCII value, then subtract 'a' to integer value for array
}

//Predicate function to check if game is over
bool gameOver() {
    //If all tiles are filled, or no valid moves exist, end the game
    if ((player1.score + player2.score == 64) || (player1.existValidMove == false && player2.existValidMove == false)) {
        return true;
    } else { //else continue the game
        return false;
    }
}