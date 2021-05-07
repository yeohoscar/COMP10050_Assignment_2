Structures were used to represent the players and the board. The colours were represented by enumerations.
They were declared and initialised in a header file so they can be easily included in all the source
files since they are needed everywhere. This saves having to pass the structs into all the functions.
All the initialisation is handled by the "gameStart" function. It sets up everything needed for the game.

To check moves, I decided that it would be better to find all valid moves and show it to the player rather than check
each player move everytime a move is inputted. This makes it easier to play the game, in my opinion, as the player does
not need to search the board for moves. To do this, the function "checkValidMoves" iterates through all the cells on the
board and calls "checkMove" to determine if placing a tile in that cell is a valid move. If it is, that cell is marked with
an "X". During a player's turn, if the cell selected does not contain an "X", that move is rejected without the need to check
it.

To check a move, I have to check for several conditions:
    - if the cell is within board limits
    - if the cell is empty
    - if at least one adjacent cell contains a tile of the opposite colour
        > if a valid adjacent cell exists, a tile of the same colour must exist at the end of that direction.

To check in a direction, I made a function that checks in all eight directions (checkMove).
The change in x and y coordinates when moving in a direction can be modelled as 0, 1, or -1.
    - 0 = no change in coordinate value
    - 1  = increase in coordinate value
    - -1 = decrease in coordinate value
This allows me to create a 2D array containing the changes in all eight directions.
Using this array, I can check along all the directions in one function. The function loops through the 2D array. For each
iteration, the function will use the current coordinate change values to move in a direction. After every iteration, the
function will have checked in all 8 directions, and if any of those directions resulted in pieces being flipped, then the
move is valid.

To flip tiles, after confirming that a move in that direction is valid, I reverse the change in coordinates and
change the tile colour as I go until I reach the original starting point. The flip portion is also in "checkMove". However,
it is controlled by a boolean variable that is hardcoded into the program. Since checking a move and flipping tiles use the
same algorithm, I judged that it would be better to fuse the two together and control whether tiles are to be flipped or not.

To end the game, either the entire board is filled or the two players can't make any moves.
    - To check if the entire board is filled, I can check if the sum of the player scores equal the total number of tiles
      on the board (64).
    - To check if the both players can't make any moves, I added a boolean variable to the player struct. If no valid
      moves are found, the variable is set to false. If both players have the variable as false, then the game is over.
Before each turn, a predicate function (gameOver) will check these conditions to determine if the game is over.

Finally, the function "printResult" is used to write the results to file. The contents are:
    - Time at start of game
    - Game result i.e. Draw or Winner: "Winner name"
    - Player names and colour
    - Score
This is all written to a file called "othello-results.txt".

https://github.com/yeohoscar/COMP10050_Assignment_2.git
