//Noah Chang - ECS36A
//Sets up a board determined by user amd plays Connect N with winning parameters determined by user
//Sections inspired by Matthew Butner - "Tic Tac Toe"

#include <stdio.h>
#include <stdbool.h>
#include "connectnsetup.h"
#include "connectnplay.h"

int main(int argc, char** argv){
    int winner, numRows, numCols, piecesToWin;
    char emptyChar = '*';
    char** board;
    getInput(&numRows, &numCols, &piecesToWin, argv, argc);
    board = makeBoard(numRows, numCols, emptyChar);
    do{
        winner = player1Turn(&board, numRows, numCols, emptyChar, piecesToWin);
        if(winner == 0 || winner == 1 || winner == 2){
            break;
        }
        winner = player2Turn(&board, numRows, numCols, emptyChar, piecesToWin);
        if(winner == 0 || winner == 1 || winner == 2){
            break;
        }
    }while(true);
    printWinner(winner);
    deleteBoard(&board, numCols);
    return 0;
}