#include"header/utility.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void wait(unsigned int secs){
    unsigned int retTime = time(0) + secs; 
    while (time(0) < retTime); //Loop until it's time
}

void clearScreen(){
    printf("\033[H\033[2J"); //ANSI code to clear
}

void centerText(char *text, int fieldWidth){
    int padlen = (fieldWidth - strlen(text)) / 2; //We determine margin
    printf("%*s%s%*s\n", padlen, "", text, padlen, "");
} 

int scan(int min,int max){

    int ask;

    while(1){
        if (scanf("%d",&ask)==0){
            printf("\nEcrivez un chiffre :\n\n");
        }
        else if(ask<min || ask>max){
            printf("\nEcrivez un chiffre entre %d et %d:\n\n", min, max);

        }
        else{
            return ask;
        }
        scanf("%*[^\n]%*1[\n]");
    }
}

void printMainMenu(){
    clearScreen();
    printf("\n\n");
    centerText("///////////////", 80);
    centerText("//CHAMPBRAWL!//", 80);
    centerText("///////////////", 80);
    printf("\n\n\n\n\n");
    centerText(">Jouer<", 80);
    while(getchar() != '\n');
    clearScreen();
}

void printChampSelect(){
    centerText("//////////////////////////", 80);
    centerText("//SELECTION DE CHAMPIONS//", 80);
    centerText("//////////////////////////", 80);
    printf("\n\n");
}

void printEnding(char* winnerName, char* winnerTeam){
    clearScreen();
    centerText("/////////////////", 80);
    centerText("//FIN DE PARTIE//", 80);
    centerText("/////////////////", 80);
    printf("\n\n");
    printf("Victoire de %s avec son équipe: %s !", winnerName, winnerTeam);
    while(getchar() != '\n');
}