#ifndef CONNECTNPLAY_H
    #define CONNECTNPLAY_H
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <ctype.h>
    bool wonHorizontally(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer);
    bool wonVertically(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer);
    bool wonLeftDiagonally(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer);
    bool wonRightDiagonally(char** board, int numRows, int numCols, int piecesToWin, int whichPlayer);
    bool tieGame(char** board, int numRows, int numCols, char emptyChar);
    int winConditions(int whichPlayer, char** board, int numRows, int numCols, char emptyChar, int piecesToWin);
    bool isValid(char** board, int numArgsRead, int playerMove, int numCols, char emptyChar);
    int player1Turn(char** *board, int numRows, int numCols, char emptyChar, int piecesToWin);
    int player2Turn(char** *board, int numRows, int numCols, char emptyChar, int piecesToWin);
    void printWinner(int winner);
#endif