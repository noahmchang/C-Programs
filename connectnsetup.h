#ifndef CONNECTNSETUP_H
    #define CONNECTNSETUP_H
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <ctype.h>
    void getInput(int* numRows, int* numCols, int* piecesToWin, char** argv, int argc);
    char** makeBoard(int numRows, int numCols, char emptyChar);
    void deleteBoard(char** *board, int numCols);
#endif