//Noah Chang - ECS36A
//Displays levels of the pascal triangle determined by user

#include <stdio.h>

//Creates levels of the pascal triangle and prints for user
//@inputs: the number of levels wanted by user
//@returns: none, prints result
void makeTriangle(int numLevels){
    int runningLevel[28] = {1, 1};
    int tempRunningLevel[28] = {1, 1};
    int addedNumber;
    int numInts = numLevels;
    if(numLevels >= 1){
        printf("1\n");
    }
    if(numLevels >= 2){
        for(int j=2; j<=numLevels; j++){
            printf("1 ");
            for(int i=0; i<j; i++){
                runningLevel[i] = tempRunningLevel[i];
                //printf("%d", runningLevel[i]);
            }
            for(int i=1; i<j; i++){
                if(i == j-1){
                    tempRunningLevel[i] = 1;
                } else{
                    addedNumber = runningLevel[i-1] + runningLevel[i];
                    printf("%d ", addedNumber);
                    tempRunningLevel[i] = addedNumber;
                }
            }
            numInts += 1;
            printf("1\n");
        }
    }
}

//Gets how many levels the user wants
//@inputs: none, gets input from user
//@returns: none, moves to makeTriangle function
int main(){
    int numLevels;
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf(" %d", &numLevels);
    makeTriangle(numLevels);
    return 0;
}