#include"header/ansicolorcode.h" //We import all the headers we'll need to make ChampBrawl work perfectly
#include"header/brawl.h"
#include"header/utility.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#define username_max 30
#define size(arr) ( sizeof(arr)/sizeof (arr[0]))

int main(int argc, char *argv[]){

    printMainMenu(); //Display the main menu

    assembleTeam(1); //Create Player 1 Team
    assembleTeam(2); //Create Player 2 Team

    clearScreen();

    brawl(); //Launch the battle
    
    return 0;
}