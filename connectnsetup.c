#include "connectnsetup.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

//Gets the dimensions of the board and the pieces needed to win
//@inputs: address of number of rows, address of number of columns, number of pieces in a row to win
//         the arguments on the command line, the number of arguments on the command line
//@returns: None
void getInput(int* numRows, int* numCols, int* piecesToWin, char** argv, int argc){
    for(int i = 1; i<argc; i++){
        int scannedInt;
        char shouldBeEmpty;
        int numArgsRead = sscanf(argv[i], " %d %c", &scannedInt, &shouldBeEmpty);
        if(numArgsRead == 1 && i == 1){
            *numRows = scannedInt;
        } else if(numArgsRead == 1 && i == 2){
            *numCols = scannedInt;
        } else if(numArgsRead == 1 && i == 3){
            *piecesToWin = scannedInt;
        } else if(numArgsRead != 1){
            printf("Invalid format\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win\n");
            exit(0);
        }
    }
    if(argc < 4){
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    } else if(argc > 4){
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
}

//Creates space for the Board and assigns initial values
//@inputs: the number of rows, the number of column, the character for empty spaces
//@returns: the created 2d board
char** makeBoard(int numRows, int numCols, char emptyChar){
    char** board;
    board = (char**)calloc(numCols + 1, sizeof(char*));
    for(int i=0; i<numCols + 1; i++){
        (board)[i] = (char*)calloc(numRows+1, sizeof(char));
        for(int j=0; j<numRows; j++){
            (board)[i][j] = emptyChar;
        }
    }
    for(int j=0; j<numRows+1; j++){
        for(int i=0; i<numCols + 1; i++){
            if(j == numRows && i == 0){
                //printf(" ");
                board[0][numRows] = ' ';
            } else if(i == 0){
                //printf("%d", numRows - (j + 1));
                board[0][j] = ((numRows - (j + 1)) + '0');
            } else if(j == numRows){
                //printf("%d", i - 1);
                board[i][numRows] = ((i - 1) + '0');
            }
        }
    }

    for(int j=0; j<numRows + 1; j++){
        for(int i=0; i<numCols + 1; i++){
            printf("%c ", (board)[i][j]);
        }
        printf("\n");
    }
    return board;
}

//Deletes the space for the board when finished
//@inputs: pointer to the 2d board, number of columns
//@returns: None
void deleteBoard(char** *board, int numCols){
    for(int i=0; i<numCols + 1; i++){
        free((*board)[i]);
    }
    free(*board);
    *board = NULL;
}