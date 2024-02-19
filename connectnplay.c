#include "connectnplay.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

//Computes whether or not the player won horizontally
//@inputs: the 2d board, the number of rows, the number of columns, the number of pieces in a row to win
//@returns: if winning horizontally was true or false
bool wonHorizontally(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer){
    char currentPiece;
    if(whichPlayer == 1){
        currentPiece = 'X';
    } else if(whichPlayer == 2){
        currentPiece = 'O';
    }
    int numSame;
    for(int i=0; i<numRows; i++){
        numSame = 0;
        for(int j=0; j<numCols; j++){
            if(board[j+1][i] == currentPiece){
                numSame++;
            } else if(board[j+1][i] != currentPiece){
                numSame = 0;
            }
            if(numSame == piecesToWin){
                return true;
            }
        }
    }
    return false;
}

//Computes whether or not the player won vertically
//@inputs: the 2d board, the number of rows, the number of columns, the number of pieces in a row to win
//@returns: if winning vertically was true or false
bool wonVertically(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer){
    char currentPiece;
    if(whichPlayer == 1){
        currentPiece = 'X';
    } else if(whichPlayer == 2){
        currentPiece = 'O';
    }
    int numSame;
    for(int i=0; i<numCols; i++){
        numSame = 0;
        for(int j=0; j<numRows; j++){
            if(board[i+1][j] == currentPiece){
                numSame++;
            } else if(board[i+1][j] != currentPiece){
                numSame = 0;
            }
            if(numSame == piecesToWin){
                return true;
            }
        }
    }
    return false;
}

//Computes whether or not the player won left diagonally
//@inputs: the 2d board, the number of rows, the number of columns, the number of pieces in a row to win
//@returns: if winning left diagonally was true or false
bool wonLeftDiagonally(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer){
    char currentPiece;
    if(whichPlayer == 1){
        currentPiece = 'X';
    } else if(whichPlayer == 2){
        currentPiece = 'O';
    }
    int sameNum = 0;
    for(int j=2; j<=numCols; j++){
        for(int i=1; i<=j; i++){ 
            if(board[i][numRows-1+(i-1)-(j-2)] == currentPiece){
                sameNum++;
            } else if(board[i][numRows-1+(i-1)-(j-2)] != currentPiece){
                sameNum = 0;
            }
            if(sameNum == piecesToWin){
                    return true;
            }
        }
        sameNum = 0;
    }
    sameNum = 0;
    for(int j=2; j<=numCols; j++){
        for(int i=1; i<=j; i++){ 
            if(board[numCols - (i-1)][(2-i)+(j-2)] == currentPiece){
                sameNum++;
            } else if(board[numCols - (i-1)][(2-i)+(j-2)] != currentPiece){
                sameNum = 0;
            }
            if(sameNum == piecesToWin){
                    return true;
            }
        }
        sameNum = 0;
    }
        sameNum = 0;
        for(int i=0; i< numCols; i++){
            if(board[i][i] == currentPiece){
                sameNum++;
            } else if(board[i][i] != currentPiece){
                sameNum = 0;
            }
            if(sameNum == piecesToWin){
                return true;
            }
        }
    return false;
}

//Computes whether or not the player won right diagonally
//@inputs: the 2d board, the number of rows, the number of columns, the number of pieces in a row to win
//@returns: if winning right diagonally was true or false
bool wonRightDiagonally(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer){
    char currentPiece;
    if(whichPlayer == 1){
        currentPiece = 'X';
    } else if(whichPlayer == 2){
        currentPiece = 'O';
    }
    int sameNum = 0;
    for(int j=2; j<=numCols; j++){
        for(int i=1; i<=j; i++){ 
            if(board[numCols - (i-1)][numRows-1+(i-1)-(j-2)] == currentPiece){
                sameNum++;
            } else if(board[numCols - (i-1)][numRows-1+(i-1)-(j-2)] != currentPiece){
                sameNum = 0;
            }
            if(sameNum == piecesToWin){
                    return true;
            }
        }
        sameNum = 0;
    }
    sameNum = 0;
    for(int j=2; j<=numCols; j++){
        for(int i=1; i<=j; i++){ 
            if(board[i][(2-i)+(j-2)] == currentPiece){
                sameNum++;
            } else if(board[i][(2-i)+(j-2)] != currentPiece){
                sameNum = 0;
            }
            if(sameNum == piecesToWin){
                    return true;
            }
        }
        sameNum = 0;
    }

    sameNum = 0;
    for(int j=0; j<numCols; j++){
        for(int i=0; i< numCols; i++){
            if((numCols) - i + j < 1 || (numCols) - i + j > numCols + 1){
            } else if(board[(numCols) - i - 1 + j][i] == currentPiece){
                sameNum++;
            } else if(board[(numCols) - i - 1 + j][i] != currentPiece){
                sameNum = 0;
            }
            if(sameNum == piecesToWin){
                return true;
            }
        }
        sameNum = 0;
    }
    return false;
}

//Computes whether or not the game was a tie
//@inputs: the 2d board, the number of rows, the number of columns, the character for empty spaces, number of pieces in a row to win
//         the number of the player who is currently playing
//@returns: if the game being a tie was true or false
bool tieGame(char** board, int numRows, int numCols, char emptyChar){
    for(int i=0; i< numRows; i++){
        for(int j=0; j< numCols; j++){
            if(board[j+1][i] == emptyChar){
                return false;
            }
        }
    }
    // if(numRows < piecesToWin || numCols <  piecesToWin){
    //     printf("Player %d Won!\n", whichPlayer);
    //     exit(0);
    // }
    return true;    
}

//Analyzes each possibility to end the game
//@inputs: the player's number, the 2d board, the number of rows, the number of column, the character for empty spaces,
//         the number of pieces in a row to win
//@returns: 1 if first player won, 2 if second player won, 0 if it was a tie, 3 if the game continues
int winConditions(int whichPlayer, char** board, int numRows, int numCols, char emptyChar, int piecesToWin){
    if(whichPlayer == 1 && (wonVertically(board, numRows, numCols, piecesToWin, whichPlayer) || wonHorizontally(board, numRows, numCols, piecesToWin, whichPlayer) || 
    wonLeftDiagonally(board, numRows, numCols, piecesToWin, whichPlayer) || wonRightDiagonally(board, numRows, numCols, piecesToWin, whichPlayer))){
        return 1;
    } else if(whichPlayer == 2 && (wonVertically(board, numRows, numCols, piecesToWin, whichPlayer) || wonHorizontally(board, numRows, numCols, piecesToWin, whichPlayer) || 
    wonLeftDiagonally(board, numRows, numCols, piecesToWin, whichPlayer) || wonRightDiagonally(board, numRows, numCols, piecesToWin, whichPlayer))){
        return 2;
    } else if(tieGame(board, numRows, numCols, emptyChar)){
        return 0;
    } else{
        return 3;
    }
}

//Checks if the user's input was formatted properly
//@inputs: the 2d board, the number of arguments read, the column the player chose, the number of columns, the character for empty spaces
//@returns: if having a valid format is true or false
bool isValid(char** board, int numArgsRead, int playerMove, int numCols, char emptyChar){
    char character;
    bool formatIsValid = numArgsRead == 1;
    //Valid formatting check
    do{
        scanf("%c", &character);
        if(!isspace(character)){
            formatIsValid = false;
        }
    } while(character != '\n');
    if(playerMove >= 0 && playerMove <= numCols-1){
    } else{
        return false;
    }
    //If the column is full
    if(board[playerMove+1][0] != emptyChar){
        return false;
    }
    return formatIsValid;
}

//Gets input, places the player's piece, prints the board, and checks if the game is over
//@inputs: pointer to the 2d board, the number of rows, the number of columns, the character for the empty spaces,
//         the number of pieces in a row to win
//@returns: 1 if first player won, 0 if it was a tie, 3 if the game continues
int player1Turn(char** *board, int numRows, int numCols, char emptyChar, int piecesToWin){
    int whichPlayer = 1;
    int numArgsRead;
    int playerMove = -1;
    //Get input
    do{
        printf("Enter a column between 0 and %d to play in: ", numCols-1);
        numArgsRead = scanf("%d", &playerMove);
    }while(!isValid(*board, numArgsRead, playerMove, numCols, emptyChar));
    //Place piece
    int row = numRows-1;
    while((*board)[playerMove+1][row] != emptyChar){
        row--;
    }
    (*board)[playerMove+1][row] = 'X';
    //Print board
    for(int j=0; j<numRows+1; j++){
        for(int i=0; i<numCols+1; i++){
            printf("%c ", (*board)[i][j]);
        }
        printf("\n");
    }
    return winConditions(whichPlayer, *board, numRows, numCols, emptyChar, piecesToWin);
}

//Gets input, places the player's piece, prints the board, and checks if the game is over
//@inputs: pointer to the 2d board, the number of rows, the number of columns, the character for the empty spaces,
//         the number of pieces in a row to win
//@returns: 2 if second player won, 0 if it was a tie, 3 if the game continues
int player2Turn(char** *board, int numRows, int numCols, char emptyChar, int piecesToWin){
    int whichPlayer = 2;
    int numArgsRead;
    int playerMove = -1;
    //Get input
    do{
        printf("Enter a column between 0 and %d to play in: ", numCols-1);
        numArgsRead = scanf("%d", &playerMove);
    }while(!isValid(*board, numArgsRead, playerMove, numCols, emptyChar));
    //Place piece
    int row = numRows-1;
    while((*board)[playerMove+1][row] != emptyChar){
        row--;
    }
    (*board)[playerMove+1][row] = 'O';
    //Print board
    for(int j=0; j<numRows+1; j++){
        for(int i=0; i<numCols+1; i++){
            printf("%c ", (*board)[i][j]);
        }
        printf("\n");
    }
    return winConditions(whichPlayer, *board, numRows, numCols, emptyChar, piecesToWin);
}

//Prints who won or if there was a tie
//@inputs: 1 if first player won, 2 if second player won, 0 if the game was a tie
//@returns: None
void printWinner(int winner){
    if(winner == 1){
        printf("Player 1 Won!\n");
    } else if(winner == 2){
        printf("Player 2 Won!\n");
    } else{
        printf("Tie game!");
    }
}