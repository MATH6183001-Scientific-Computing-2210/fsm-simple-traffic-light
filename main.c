#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils/constants.h"
#include "utils/display.h"

#include "mylib/combLogic.h"

void printState(int state[2]){
    /*
        convert encoded state bact to string
    */
    char stateStr[7];
    if(state[0]==0 && state[1]==0){
        stateStr[0] = 'r';
        stateStr[1] = 'e';
        stateStr[2] = 'd';
        stateStr[3] = '\0';
    } else if (state[0]==0 && state[1]==1){
        stateStr[0] = 'y';
        stateStr[1] = 'e';
        stateStr[2] = 'l';
        stateStr[3] = 'l';
        stateStr[4] = 'o';
        stateStr[5] = 'w';
    } else if (state[0]==1 && state[1]==0){
        stateStr[0] = 'g';
        stateStr[1] = 'r';
        stateStr[2] = 'e';
        stateStr[3] = 'e';
        stateStr[4] = 'n';
    }
    printf("State: %s \n", stateStr);
}

void printOutput(int output[3]){
    /*
        convert encoded output back to string
    */
    if(output[0]==1 && output[1]==0 && output[2]==0){
        printf("Output: %s\n","red");
    } else if(output[0]==0 && output[1]==1 && output[2]==0){
        printf("Output: %s\n","yellow");
    } else if(output[0]==0 && output[1]==0 && output[2]==1){
        printf("Output: %s\n","green");
    } else {
        printf("Output: %s\n","undefined");
    }
}

int main(void){
    
    // def
    const int TIMEOUT = 3; // TIMEOUT for the timer

    // initialization
    int output[3] = {1,0,0};
    int presentState[2] = {0,0};
    int nextState[2];
    int i = 0;
    int input = 0;

    // fsm routine
    while(1){

        // timer starts
        for(i = 1; i <= TIMEOUT; i++){
            sleep(1); // 1s tick

            input = 0; // 0 means 'not expired yet'
            
            // calculate the combinatorial logic
            calcOutput(presentState,output);
            calcNextState(presentState,input,nextState);
            
            // display
            //printState(presentState);
            //printOutput(output);
            displayOutput(i,output);

            // assign present state as the next state
            presentState[0] = nextState[0];
            presentState[1] = nextState[1];
        }

        // transition
        input = 1;
        calcOutput(presentState,output);
        calcNextState(presentState,input,nextState);
        presentState[0] = nextState[0];
        presentState[1] = nextState[1];

    }


    return 0;
}
