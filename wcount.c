//Noah Chang - ECS
//Counts the number words contained within a file

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//Counts the number of words in the file and prints result
//@inputs: the arguments from the command line
//@returns: None
void readFile(char** argv){
    FILE* file = NULL;
    int wordCount = 0;
    bool hasBeenSpace = true;

    file = fopen(argv[1], "r");
    if(file == NULL){
        return;
    }
    char c;
    fscanf(file, "%c", &c);
    while(!feof(file)){
        //printf("%c", c);
        if(isspace(c)){
            hasBeenSpace = true;
        }
        if(!isspace(c) && hasBeenSpace){
            wordCount++;
            hasBeenSpace = false;
        }
        fscanf(file, "%c", &c);
    }
    printf("There are %d word(s).", wordCount);
    fclose(file);
}

//Gets the arguments from command line
//@inputs: the number of arguments, the arguments on the commandline
//@returns: None
int main(int argc, char** argv){
    if(argc == 2){
        readFile(argv);
    }
    return 0;
}