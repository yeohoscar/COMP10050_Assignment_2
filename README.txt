Structures were used to represent the players and the board. The colours were represented by enumerations.
They were declared and initialised in a header file so they can be easily included in all the source
files since they are needed everywhere. This saves having to pass the structs into all the functions.

To check a move, I have to check for several conditions:
    - if the cell is within board limits
    - if the cell is empty
    - if at least one adjacent cell contains a tile of the opposite colour
        > if a valid adjacent cell exists, a tile of the same colour must exist at the end of that direction.

To check directions, I made a function that checks in all eight directions.
The change in x and y coordinates when moving in a direction can be modelled as 0, 1, or -1.
    - 0 = no change in coordinate
    - 1  = increase in coordinate
    - -1 = decrease in coordinate
This allows me to create a 2D array containing the changes in all eight directions.
Using this array, I can check along all the directions in one function.

To flip tiles, after confirming that a move in that direction is valid, I reverse the change in coordinates and
change the tile colour as I go until I reach the original starting point.

To end the game, either the entire board is filled or the two players can't make any moves.
    - To check if the entire board is filled, I can check if the sum of the player scores equal the total number of tiles
      on the board (64).
    - To check if the both players can't make any moves, I added a boolean variable to the player struct. If no valid
      moves are found, the variable is set to false. If both players have the variable as false, then the game is over.
Before each turn, a predicate function will check these conditions to determine if the game is over.



