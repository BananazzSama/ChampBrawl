#ifndef UTILITY_H
#define UTILITY_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Function that wait for secs until an action is done
void wait(unsigned int secs);

//Clear the terminal
void clearScreen();

//Center the text on screen(takes text and terminal width)
void centerText(char *text, int fieldWidth);

//Scan that ask for a number beetween min and max
int scan(int min,int max);

//Display main menu
void printMainMenu();

//Display champ selection menu
void printChampSelect();

//Display ending screen
void printEnding(char* winnerName, char* winnerTeam);

#endif