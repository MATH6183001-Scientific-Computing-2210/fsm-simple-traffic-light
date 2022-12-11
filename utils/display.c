#include <stdio.h>
#include <string.h>
#include "constants.h"

void displayCircle(char mode[]){
    if(!strcmp(mode,"red")){
        printf("│ %sxxxx%s │\n",RED,COLOR_RESET);
        printf("│%sxxxxxx%s│\n",RED,COLOR_RESET);
        printf("│ %sxxxx%s │\n",RED,COLOR_RESET);
    } else if(!strcmp(mode,"green")){
        printf("│ %sxxxx%s │\n",GREEN,COLOR_RESET);
        printf("│%sxxxxxx%s│\n",GREEN,COLOR_RESET);
        printf("│ %sxxxx%s │\n",GREEN,COLOR_RESET);
    } else if(!strcmp(mode,"yellow")){
        printf("│ %sxxxx%s │\n",YELLOW,COLOR_RESET);
        printf("│%sxxxxxx%s│\n",YELLOW,COLOR_RESET);
        printf("│ %sxxxx%s │\n",YELLOW,COLOR_RESET);
    } else {
        printf("│ xxxx │\n");
        printf("│xxxxxx│\n");
        printf("│ xxxx │\n");
    }
}

void displayTrafficLight(int mode[3]){

    printf("\n");
    printf("┌──────┐\n");
    if(mode[0] == 1){displayCircle("red");}
    else{displayCircle("white");}
    printf("│      │\n");
    if(mode[1] == 1){displayCircle("yellow");}
    else{displayCircle("white");}
    printf("│      │\n");
    if(mode[2] == 1){displayCircle("green");}
    else{displayCircle("white");}
    printf("└──────┘\n");
}

void displayTimer(int value){
    printf("Timer: %d\n",value);
}

void displayOutput(int value, int modes[3]){
    printf(ANSI_CLEAR_SCREEN);
    fflush(stdout);
    printf(ANSI_TOP_LEFT);
    displayTimer(value);
    displayTrafficLight(modes);
}