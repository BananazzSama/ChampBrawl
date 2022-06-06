#ifndef BRAWL_H
#define BRAWL_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define char_size 3000
#define username_max 30
#define size(arr) ( sizeof(arr)/sizeof (arr[0]))

typedef struct{ //Define Spells structure, to create spells that Champions will use to fight
    char name[char_size]; 
    char desc[char_size];
    int damage;
    int cooldown;
    int currentCd;
    int target;
    int targetNb;
    char text1[char_size];
    int spellNature;
}spell;

typedef struct{ //Define Champions structure, to make playable characters, named Champions
    char name[char_size];
    char desc[char_size];
    int currentHp;
    int maxHp;
    int atk;
    int def;
    int speed;
    int agility;
    spell autoAttack;
    spell spell1;
    spell spell2;
    int team;
    int status;
}champion;

typedef struct{ //Define Teams structure, to stock all 3 player's Champions
    char name[char_size];
    champion champ1;
    champion champ2;
    champion champ3;
}team;

//createSpell is a fonction that reads a spell's informations from a .txt file to put it in the program and assign it to the selected Champion
//The Champion who receive the spell is selected by the "nb" parameter (1,2,3 for the first player's champs and 4,5,6 for the second player's)
void createSpell(int nb, char* spellPath, int slot);

//createChamp is a fonction that reads a Champion's informations from a .txt file to put it in the program
//nb: 1,2,3 for player 1; 4,5,6 for player 2
void createChamp(int nb, char* champAddress);

//Function to create the Champion selection screen
//team takes 1 parameter: 1 for Team 1 or 2 for Team 2
void assembleTeam(int team);

//displayChampHP is a fuction that prints all the Champions' HP
void displayChampHP();

//makeOrder is a sorting function to define when the Champions play (based on speed)(takes champ[] and tab's length)
void makeOrder(champion tab[], int length);

//useSpell make a Champion use a spell(takes the spell user and the launched spell)
void useSpell(champion user, spell usedSpell);

//applySpell is a function that apply all the changes like damage on the target
//Takes spell user, the target, launched spell and tab index
void applySpell(champion user, champion target, spell usedSpell, int nb);

//champTurn is a function that displays all the informations the user needs to play a Champion's turn
//Takes the concerned Champion
void champTurn(champion champ);

//Check if a Champion is dead(takes the Champion that needs to be checked and tab index)
void deathCheck(champion champ, int nb);

//Function to make all the battle
void brawl(void);

#endif