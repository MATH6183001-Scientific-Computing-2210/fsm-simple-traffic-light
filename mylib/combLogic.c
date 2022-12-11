
void calcNextState(int presentState[2], int input, int nextState[2]){
    /*
        Given a present state and input, this function calculates the next state
    */
   
    // obtained from K-map
    nextState[0] = (presentState[0] & !input) | (presentState[1] & input);
    nextState[1] = (!presentState[0] & !presentState[1] & input) | 
        (presentState[1] & !input);
    
}

void calcOutput(int presentState[2], int output[3]){
    /*
        The output that shows which color will be displayed in the traffic light
        only depends on the present state
    */

    // obtained from K-map
    output[0] = !presentState[0] & !presentState[1];
    output[1] = presentState[1];
    output[2] = presentState[0];
}