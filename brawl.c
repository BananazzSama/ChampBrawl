#include"header/brawl.h"
#include"header/utility.h"
#include"header/ansicolorcode.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Targets: 1 for enemy, 2 for ally spells

//Temporary variables to keep some spells/champions informations related in memory

int already1OnTeam;
int already2OnTeam;
int already3OnTeam;

char champ1[char_size];
char champ2[char_size];
char champ3[char_size];
char champ4[char_size];
char champ5[char_size];
char champ6[char_size];

char tempName[char_size];
char tempDesc[char_size];
char tempAutoAtk[char_size];
char tempSpell1[char_size];
char tempSpell2[char_size];
char tempSpellName[char_size];
char tempSpellDesc[char_size];
char tempSpellText1[char_size];
int tempCurrentHp, tempMaxHp, tempAtk, tempDef, tempSpeed, tempAgility, tempSpellDamage, tempSpellAccuracy, tempSpellCooldown, tempSpellTarget, tempSpellTargetNb, tempSpellNature;

int tempChar;

//Here's were players' usernames and team names are registered
char player1Username[30];
char player2Username[30];
char player1Team[30];
char player2Team[30];

//Here we initialize the 6 playable Champions of the players
champion champs[6];

//Same with the 6 Champions, we initialize the 2 teams of Champions
team teams[2];

void createSpell(int nb, char* spellPath, int slot){

    FILE* spellFile;
    char chain[char_size];
    spellFile = fopen(spellPath, "r");

    int line = 0;

    if(spellFile == NULL){
        printf("No Spell file detected !\n");
        exit(1);
    }

    else if(spellFile != NULL){
        printf("Spell file sucessfuly opened !\n");
        while(fgets(chain, char_size, spellFile) != NULL){
            line += 1;
            if(line!=8){
                chain[strlen(chain) - 1] = '\0';
            }

            //The program will read every lines of the spell.txt and execute different tasks depending on the current line (name, description, damage, cooldown, target, number of targets...)
            if(line==1){strcpy(tempSpellName, chain);}
            else if(line==2){strcpy(tempSpellDesc, chain);}
            else if(line==3){tempSpellDamage = atoi(chain);}
            else if(line==4){tempSpellCooldown = atoi(chain);}
            else if(line==5){tempSpellTarget = atoi(chain);}
            else if(line==6){tempSpellTargetNb = atoi(chain);}
            else if(line==7){strcpy(tempSpellText1, chain);}
            else if(line==8){tempSpellNature = atoi(chain);}
        }

        if(slot == 0){ //If it's an auto attack
            strcpy(champs[nb-1].autoAttack.name, tempSpellName);
            strcpy(champs[nb-1].autoAttack.desc, tempSpellDesc);
            champs[nb-1].autoAttack.damage = tempSpellDamage;
            champs[nb-1].autoAttack.cooldown = tempSpellCooldown;
            champs[nb-1].autoAttack.target = tempSpellTarget;
            champs[nb-1].autoAttack.targetNb = tempSpellTargetNb;
            strcpy(champs[nb-1].autoAttack.text1, tempSpellText1);
            champs[nb-1].autoAttack.spellNature = tempSpellNature;
            champs[nb-1].autoAttack.currentCd = tempSpellCooldown;
        }

        if(slot == 1){ //If it's spell 1
            strcpy(champs[nb-1].spell1.name, tempSpellName);
            strcpy(champs[nb-1].spell1.desc, tempSpellDesc);
            champs[nb-1].spell1.damage = tempSpellDamage;
            champs[nb-1].spell1.cooldown = tempSpellCooldown;
            champs[nb-1].spell1.target = tempSpellTarget;
            champs[nb-1].spell1.targetNb = tempSpellTargetNb;
            strcpy(champs[nb-1].spell1.text1, tempSpellText1);
            champs[nb-1].spell1.spellNature = tempSpellNature;
            champs[nb-1].spell1.currentCd = tempSpellCooldown;
        }

        if(slot == 2){  //If it's spell 1
            strcpy(champs[nb-1].spell2.name, tempSpellName);
            strcpy(champs[nb-1].spell2.desc, tempSpellDesc);
            champs[nb-1].spell2.damage = tempSpellDamage;
            champs[nb-1].spell2.cooldown = tempSpellCooldown;
            champs[nb-1].spell2.target = tempSpellTarget;
            champs[nb-1].spell2.targetNb = tempSpellTargetNb;
            strcpy(champs[nb-1].spell2.text1, tempSpellText1);
            champs[nb-1].spell2.spellNature = tempSpellNature;
            champs[nb-1].spell2.currentCd = tempSpellCooldown;
        }

        fclose(spellFile);
    }
}

void createChamp(int nb, char* champAddress){
 
    FILE* file;
    char chain[char_size];
    file = fopen(champAddress, "r");

    int line = 0;

    if(file == NULL){
        printf("No Champion file detected !\n");
        exit(1);
    }

    else if(file != NULL){
        printf("Champion file sucessfuly opened !\n");
        while(fgets(chain, char_size, file) != NULL){
            line += 1;
            if(line!=11){
                chain[strlen(chain) - 1] = '\0';
            }

            //The program will read every lines of the champion.txt and execute different tasks depending on the current line like with the spell one)
            if(line==1){strcpy(tempName, chain);}
            else if(line==2){strcpy(tempDesc, chain);}
            else if(line==3){tempCurrentHp = atoi(chain);}
            else if(line==4){tempMaxHp = atoi(chain);}
            else if(line==5){tempAtk = atoi(chain);}
            else if(line==6){tempDef = atoi(chain);}
            else if(line==7){tempSpeed = atoi(chain);}
            else if(line==8){tempAgility = atoi(chain);}
            else if(line==9){strcpy(tempAutoAtk, chain);}
            else if(line==10){strcpy(tempSpell1, chain);}
            else if(line==11){strcpy(tempSpell2, chain);}
        }

        strcpy(champs[nb-1].name, tempName);
        strcpy(champs[nb-1].desc, tempDesc);
        champs[nb-1].currentHp = tempCurrentHp;
        champs[nb-1].maxHp = tempMaxHp;
        champs[nb-1].atk = tempAtk;
        champs[nb-1].def = tempDef;
        champs[nb-1].speed = tempSpeed;
        champs[nb-1].agility = tempAgility;
        champs[nb-1].status = 1;

        if(nb <= 3){  //If nb is 1,2 or 3 its a Champion in Team 1
            champs[nb-1].team = 1;
        }
        else{  //If nb is 4,5 or 6 its a Champion in Team 2
            champs[nb-1].team = 2;
        }


        fclose(file);

        //Here we assign spells to Champions using tempChar to make sure each champ has the right spell
        if(tempChar == 1){
            createSpell(nb, "data/spell/lightning_incision.txt", 0);
            createSpell(nb, "data/spell/electric_slice.txt", 1);
            createSpell(nb, "data/spell/thunderstrike.txt", 2);
        }
        else if(tempChar == 2){
            createSpell(nb, "data/spell/kings_fist.txt", 0);
            createSpell(nb, "data/spell/eye_of_the_demon_king.txt", 1);
            createSpell(nb, "data/spell/earthquake.txt", 2);
        }
        else if(tempChar == 3){
            createSpell(nb, "data/spell/barbarian_opening.txt", 0);
            createSpell(nb, "data/spell/naingarian_fervor.txt", 1);
            createSpell(nb, "data/spell/naingui_instinct.txt", 2);
        }
        else if(tempChar == 4){
            createSpell(nb, "data/spell/balanced_slash.txt", 0);
            createSpell(nb, "data/spell/blessed_magic.txt", 1);
            createSpell(nb, "data/spell/dark_energy.txt", 2);
        }
        else if(tempChar == 5){
            createSpell(nb, "data/spell/astro_attack.txt", 0);
            createSpell(nb, "data/spell/astro_beam.txt", 1);
            createSpell(nb, "data/spell/astro_light.txt", 2);
        }
        else if(tempChar == 6){
            createSpell(nb, "data/spell/slime_punch.txt", 0);
            createSpell(nb, "data/spell/blob.txt", 1);
            createSpell(nb, "data/spell/hnouna.txt", 2);
        }
        else if(tempChar == 7){
            createSpell(nb, "data/spell/slice.txt", 0);
            createSpell(nb, "data/spell/perfect_execution.txt", 1);
            createSpell(nb, "data/spell/focus.txt", 2);
        }
    }
}

void printCharSelection(){  //For Champion selection, we check if the Champion has not been selected in the team, the we display it if it hasn't

    if(already1OnTeam != 1 && already2OnTeam != 1 && already3OnTeam != 1){
        printf("1: Raiju" reset r);
        printf("Rôle : Assassin | Raiju est un redoutable sabreur doté de la mystérieuse Grâce\ndu Dieu de la foudre Raijin"r r);
    }
    if(already1OnTeam != 2 && already2OnTeam != 2 && already3OnTeam != 2){
        printf("2: King Ohm" reset r);
        printf("Rôle : Tank | King ohm est un roi ayant fait un pacte avec un démon pour\nacquérir un pouvoir capable de protéger son royaume."r r);
    }
    if(already1OnTeam != 3 && already2OnTeam != 3 && already3OnTeam != 3){
        printf("3: Badasz Brabus" reset r);
        printf("Rôle : Guerrier | Badasz Brabus est un jeune barbare qui protège le royaume\nde Naingar."r r);
    }
    if(already1OnTeam != 4 && already2OnTeam != 4 && already3OnTeam != 4){
        printf("4: Beigaa" reset r);
        printf("Rôle : Mage | Beigaa est un hybride mystérieux Ange et Démon qui use ses dons\npour aider les mortels."r r);
    }
    if(already1OnTeam != 5 && already2OnTeam != 5 && already3OnTeam != 5){
        printf("5: Astro" reset r);
        printf("Rôle : Support | Astro est un être provenant d'une espèce capable de manipuler\nles étoiles. Ses pouvoirs dépassent l'entendement."r r);
    }
    if(already1OnTeam != 6 && already2OnTeam != 6 && already3OnTeam != 6){
        printf("6: Morvo" reset r);
        printf("Rôle : Tank | Morvo est un tas de morve étonnamment résistant qui a pris vie."r r);
    }
    if(already1OnTeam != 7 && already2OnTeam != 7 && already3OnTeam != 7){
        printf("7: No.7" reset r);
        printf("Rôle : Assassin | No.7 est une humaine génétiquement modifiée et formée comme\nune machine à tuer."r r);
    }

}

void assembleTeam(int team){

    if(team == 1){

        printChampSelect();

        printf("Joueur 1, entrez votre nom d'Invocateur\n\n");
        scanf("%29[0-9a-zA-Z ]", player1Username);

        printf("\n\n%s, entrez le nom de votre équipe\n\n", player1Username);
        scanf(" %29[0-9a-zA-Z ]", player1Team);
        clearScreen();

        printChampSelect();

        printf("Choisissez votre 1er Champion\n");
        printCharSelection();

        int selectedChamp1 = scan(1, 7);

        //Bunch of verifications to select Champions with scanf
        if(selectedChamp1 == 1){
            tempChar = 1;
            strncpy(champ1, "Raiju", char_size);
            createChamp(1, "data/champion/raiju.txt");
            printf("Le 1er Champion de %s est Raiju !\n", player1Username);
            already1OnTeam = 1;
        }
        else if(selectedChamp1 == 2){
            tempChar = 2;
            strncpy(champ1, "King Ohm", char_size);
            createChamp(1, "data/champion/king_ohm.txt");
            printf("Le 1er Champion de %s est King Ohm !\n", player1Username);
            already1OnTeam = 2;
        }
        else if(selectedChamp1 == 3){
            tempChar = 3;
            strncpy(champ1, "Badasz Brabus", char_size);
            createChamp(1, "data/champion/badasz_brabus.txt");
            printf("Le 1er Champion de %s est Badasz Brabus !\n", player1Username);
            already1OnTeam = 3;
        }
        else if(selectedChamp1 == 4){
            tempChar = 4;
            strncpy(champ1, "Beigaa", char_size);
            createChamp(1, "data/champion/beigaa.txt");
            printf("Le 1er Champion de %s est Beigaa !\n", player1Username);
            already1OnTeam = 4;
        }
        else if(selectedChamp1 == 5){
            tempChar = 5;
            strncpy(champ1, "Astro", char_size);
            createChamp(1, "data/champion/astro.txt");
            printf("Le 1er Champion de %s est Astro !\n", player1Username);
            already1OnTeam = 5;
        }
        else if(selectedChamp1 == 7){
            tempChar = 7;
            strncpy(champ1, "No. 7", char_size);
            createChamp(1, "data/champion/no7.txt");
            printf("Le 1er Champion de %s est No. 7 !\n", player1Username);
            already1OnTeam = 6;
        }

        clearScreen();
        printChampSelect();

        printf("Choisissez votre 2ème Champion\n");
        printCharSelection();

        int selectedChamp2 = scan(1, 7);

        if(selectedChamp2 == 1){
            tempChar = 1;
            strncpy(champ2, "Raiju", char_size);
            createChamp(2, "data/champion/raiju.txt");
            printf("Le 2ème Champion de %s est Raiju !\n", player1Username);
            already2OnTeam = 1;
        }
        else if(selectedChamp2 == 2){
            tempChar = 2;
            strncpy(champ2, "King Ohm", char_size);
            createChamp(2, "data/champion/king_ohm.txt");
            printf("Le 2ème Champion de %s est King Ohm !\n", player1Username);
            already2OnTeam = 2;
        }
        else if(selectedChamp2 == 3){
            tempChar = 3;
            strncpy(champ2, "Badasz Brabus", char_size);
            createChamp(2, "data/champion/badasz_brabus.txt");
            printf("Le 2ème Champion de %s est Badasz Brabus !\n", player1Username);
            already2OnTeam = 3;
        }
        else if(selectedChamp2 == 4){
            tempChar = 4;
            strncpy(champ2, "Beigaa", char_size);
            createChamp(2, "data/champion/beigaa.txt");
            printf("Le 2ème Champion de %s est Beigaa !\n", player1Username);
            already2OnTeam = 4;
        }
        else if(selectedChamp2 == 5){
            tempChar = 5;
            strncpy(champ2, "Astro", char_size);
            createChamp(2, "data/champion/astro.txt");
            printf("Le 2ème Champion de %s est Astro !\n", player1Username);
            already2OnTeam = 5;
        }
        else if(selectedChamp2 == 7){
            tempChar = 7;
            strncpy(champ2, "No. 7", char_size);
            createChamp(2, "data/champion/no7.txt");
            printf("Le 2ème Champion de %s est No. 7 !\n", player1Username);
            already2OnTeam = 7;
        }

        clearScreen();
        printChampSelect();

        printf("Choisissez votre 3ème Champion\n");
        printCharSelection();

        int selectedChamp3 = scan(1, 7);

        if(selectedChamp3 == 1){
            tempChar = 1;
            strncpy(champ3, "Raiju", char_size);
            createChamp(3, "data/champion/raiju.txt");
            printf("Le 3ème Champion de %s est Raiju !\n", player1Username);
            already3OnTeam = 1;
        }
        else if(selectedChamp3 == 2){
            tempChar = 2;
            strncpy(champ3, "Raiju", char_size);
            createChamp(3, "data/champion/king_ohm.txt");
            printf("Le 3ème Champion de %s est King Ohm !\n", player1Username);
            already3OnTeam = 2;
        }
        else if(selectedChamp3 == 3){
            tempChar = 3;
            strncpy(champ3, "Badasz Brabus", char_size);
            createChamp(3, "data/champion/badasz_brabus.txt");
            printf("Le 3ème Champion de %s est Badasz Brabus !\n", player1Username);
            already3OnTeam = 3;
        }
        else if(selectedChamp3 == 4){
            tempChar = 4;
            strncpy(champ3, "Beigaa", char_size);
            createChamp(3, "data/champion/beigaa.txt");
            printf("Le 3ème Champion de %s est Beigaa !\n", player1Username);
            already3OnTeam = 4;
        }
        else if(selectedChamp3 == 5){
            tempChar = 5;
            strncpy(champ3, "Astro", char_size);
            createChamp(3, "data/champion/astro.txt");
            printf("Le 3ème Champion de %s est Astro !\n", player1Username);
            already3OnTeam = 5;
        }
        else if(selectedChamp3 == 7){
            tempChar = 7;
            strncpy(champ3, "No. 7", char_size);
            createChamp(3, "data/champion/no7.txt");
            printf("Le 3ème Champion de %s est No. 7 !\n", player1Username);
            already3OnTeam = 7;
        }

        clearScreen();
    }

    if(team == 2){

        printChampSelect();

        printf("Joueur 2, entrez votre nom d'Invocateur\n\n");
        scanf(" %29[0-9a-zA-Z ]", player2Username);

        printf("\n\n%s, entrez le nom de votre équipe\n\n", player2Username);
        scanf(" %29[0-9a-zA-Z ]", player2Team);
        clearScreen();

        printChampSelect();

        printf("Choisissez votre 1er Champion\n");
        printCharSelection();

        int selectedChamp1 = scan(1, 7);

        if(selectedChamp1 == 1){
            tempChar = 1;
            strncpy(champ4, "Raiju", char_size);
            createChamp(4, "data/champion/raiju.txt");
            printf("Le 1er Champion de %s est Raiju !\n", player2Username);
            already1OnTeam = 1;
        }
        else if(selectedChamp1 == 2){
            tempChar = 2;
            strncpy(champ4, "King Ohm", char_size);
            createChamp(4, "data/champion/king_ohm.txt");
            printf("Le 1er Champion de %s est King Ohm !\n", player2Username);
            already1OnTeam = 2;
        }
        else if(selectedChamp1 == 3){
            tempChar = 3;
            strncpy(champ4, "Badasz Brabus", char_size);
            createChamp(4, "data/champion/badasz_brabus.txt");
            printf("Le 1er Champion de %s est Badasz Brabus !\n", player2Username);
            already1OnTeam = 3;
        }
        else if(selectedChamp1 == 4){
            tempChar = 4;
            strncpy(champ4, "Beigaa", char_size);
            createChamp(4, "data/champion/beigaa.txt");
            printf("Le 1er Champion de %s est Beigaa !\n", player2Username);
            already1OnTeam = 4;
        }
        else if(selectedChamp1 == 5){
            tempChar = 5;
            strncpy(champ4, "Astro", char_size);
            createChamp(4, "data/champion/astro.txt");
            printf("Le 1er Champion de %s est Astro !\n", player2Username);
            already1OnTeam = 5;
        }
        else if(selectedChamp1 == 7){
            tempChar = 7;
            strncpy(champ4, "No. 7", char_size);
            createChamp(4, "data/champion/no7.txt");
            printf("Le 1er Champion de %s est No. 7 !\n", player2Username);
            already1OnTeam = 6;
        }

        clearScreen();
        printChampSelect();

        printf("Choisissez votre 2ème Champion\n");
        printCharSelection();

        int selectedChamp2 = scan(1, 7);

        if(selectedChamp2 == 1){
            tempChar = 1;
            strncpy(champ5, "Raiju", char_size);
            createChamp(5, "data/champion/raiju.txt");
            printf("Le 2ème Champion de %s est Raiju !\n", player2Username);
            already2OnTeam = 1;
        }
        else if(selectedChamp2 == 2){
            tempChar = 2;
            strncpy(champ5, "King Ohm", char_size);
            createChamp(5, "data/champion/king_ohm.txt");
            printf("Le 2ème Champion de %s est King Ohm !\n", player2Username);
            already2OnTeam = 2;
        }
        else if(selectedChamp2 == 3){
            tempChar = 3;
            strncpy(champ5, "Badasz Brabus", char_size);
            createChamp(5, "data/champion/badasz_brabus.txt");
            printf("Le 2ème Champion de %s est Badasz Brabus !\n", player2Username);
            already2OnTeam = 3;
        }
        else if(selectedChamp2 == 4){
            tempChar = 4;
            strncpy(champ5, "Beigaa", char_size);
            createChamp(5, "data/champion/beigaa.txt");
            printf("Le 2ème Champion de %s est Beigaa !\n", player2Username);
            already2OnTeam = 4;
        }
        else if(selectedChamp2 == 5){
            tempChar = 5;
            strncpy(champ5, "Astro", char_size);
            createChamp(5, "data/champion/astro.txt");
            printf("Le 2ème Champion de %s est Astro !\n", player2Username);
            already2OnTeam = 5;
        }
        else if(selectedChamp2 == 7){
            tempChar = 7;
            strncpy(champ5, "No. 7", char_size);
            createChamp(5, "data/champion/no7.txt");
            printf("Le 2ème Champion de %s est No. 7 !\n", player2Username);
            already2OnTeam = 7;
        }

        clearScreen();
        printChampSelect();

        printf("Choisissez votre 3ème Champion\n");
        printCharSelection();

        int selectedChamp3 = scan(1, 7);

        if(selectedChamp3 == 1){
            tempChar = 1;
            strncpy(champ6, "Raiju", char_size);
            createChamp(6, "data/champion/raiju.txt");
            printf("Le 3ème Champion de %s est Raiju !\n", player2Username);
            already3OnTeam = 1;
        }
        else if(selectedChamp3 == 2){
            tempChar = 2;
            strncpy(champ6, "King Ohm", char_size);
            createChamp(6, "data/champion/king_ohm.txt");
            printf("Le 3ème Champion de %s est King Ohm !\n", player2Username);
            already3OnTeam = 2;
        }
        else if(selectedChamp3 == 3){
            tempChar = 3;
            strncpy(champ6, "Badasz Brabus", char_size);
            createChamp(6, "data/champion/badasz_brabus.txt");
            printf("Le 3ème Champion de %s est Badasz Brabus !\n", player2Username);
            already3OnTeam = 3;
        }
        else if(selectedChamp3 == 4){
            tempChar = 4;
            strncpy(champ6, "Beigaa", char_size);
            createChamp(6, "data/champion/beigaa.txt");
            printf("Le 3ème Champion de %s est Beigaa !\n", player2Username);
            already3OnTeam = 4;
        }
        else if(selectedChamp3 == 5){
            tempChar = 5;
            strncpy(champ6, "Astro", char_size);
            createChamp(6, "data/champion/astro.txt");
            printf("Le 3ème Champion de %s est Astro !\n", player2Username);
            already3OnTeam = 5;
        }
        else if(selectedChamp3 == 7){
            tempChar = 7;
            strncpy(champ6, "No. 7", char_size);
            createChamp(6, "data/champion/no7.txt");
            printf("Le 3ème Champion de %s est No. 7 !\n", player2Username);
            already3OnTeam = 7;
        }

        clearScreen();
    }

    already1OnTeam = 0;
    already2OnTeam = 0;
    already3OnTeam = 0;

    if(team == 1){
        teams[0].champ1 = champs[0];
        teams[0].champ2 = champs[1];
        teams[0].champ3 = champs[2];
    }
    else if(team == 2)
    {
        teams[1].champ1 = champs[3];
        teams[1].champ2 = champs[4];
        teams[1].champ3 = champs[5];
    }

}

void displayChampHP(){

    printf("(%s)  ", player1Team);
    for(int i=0; i < 6; i++){
        if(champs[i].team == 1){
            if(strcmp(champ1, champs[i].name) == 0){
                printf("%d/%d | %s     ",champs[i].currentHp, champs[i].maxHp, champ1);
            }
            else if(strcmp(champ2, champs[i].name) == 0){
                printf("%d/%d | %s     ",champs[i].currentHp, champs[i].maxHp, champ2);
            }
            else if(strcmp(champ3, champs[i].name) == 0){
                printf("%d/%d | %s     ",champs[i].currentHp, champs[i].maxHp, champ3);
            }
        }
    }
    printf("\n\n");

    printf("(%s)  ", player2Team);
    for(int i=0; i < 6; i++){
        if(champs[i].team == 2){
            if(strcmp(champ4, champs[i].name) == 0){
                printf("%d/%d | %s     ",champs[i].currentHp, champs[i].maxHp, champ4);
            }
            else if(strcmp(champ5, champs[i].name) == 0){
                printf("%d/%d | %s     ",champs[i].currentHp, champs[i].maxHp, champ5);
            }
            else if(strcmp(champ6, champs[i].name) == 0){
                printf("%d/%d | %s     ",champs[i].currentHp, champs[i].maxHp, champ6);
            }
        }
    }
    printf("\n\n");
}

void makeOrder(champion tab[], int length){

    int i;
    int d;
    champion buffer;

    //Here we sort in descending order

    i = 0;
    d = 0;

    for(d=0; d < length; d++)
        for(i=d; i < length; i++)

            if(tab[i].speed >= tab[d].speed)
            {
            buffer = tab[d];
            tab[d] = tab[i];
            tab[i] = buffer;
            }
}

void useSpell(champion user, spell usedSpell){

    int a, b, c = 0;
    int d, e, f = 0;

    int j = 0;
    int k = 0;

    champion champTeam1[3];
    champion champTeam2[3];

    for(int i = 0; i < 6; i++){
        if(champs[i].team == 1){
            if(j == 0){
                a = j;
            }
            else if(j == 1){
                b = j;
            }
            else if(j == 2){
                c = j;
            }
            j += 1;
        }
    }

    for(int i = 0; i < 6; i++){
        if(champs[i].team == 2){
            if(k == 0){
                d = k;
            }
            else if(k == 1){
                e = k;
            }
            else if(k == 2){
                f = k;
            }
            k += 1;
        }
    }

    if(usedSpell.target == 1){
        if(user.team == 1){
            printf("Sélectionnez une cible:\n\n");
            printf("1. %s\n", champs[d].name);
            printf("2. %s\n", champs[e].name);
            printf("3. %s\n", champs[f].name);

            int selectedTarget = scan(1, 3);

            printf("test\n");

            if(selectedTarget == 1){
                clearScreen();
                applySpell(user, champs[d], usedSpell, d);
            }
            else if(selectedTarget == 2){
                clearScreen();
                applySpell(user, champs[e], usedSpell, e);
            }
            else if(selectedTarget == 3){
                clearScreen();
                applySpell(user, champs[f], usedSpell, f);
            }
        }
        else if(user.team == 2){
            printf("Sélectionnez une cible:\n\n");
            printf("1. %s\n", champs[a].name);
            printf("2. %s\n", champs[b].name);
            printf("3. %s\n", champs[c].name);

            int selectedTarget = scan(1, 3);

            if(selectedTarget == 1){
                clearScreen();
                applySpell(user, champs[a], usedSpell, a);
            }
            else if(selectedTarget == 2){
                clearScreen();
                applySpell(user, champs[b], usedSpell, b);
            }
            else if(selectedTarget == 3){
                clearScreen();
                applySpell(user, champs[c], usedSpell, c);
            }
        }
    }
    else if(usedSpell.target == 2){
        if(user.team == 1){
            printf("Sélectionnez un allié:\n\n");
            printf("1. %s\n", champs[a].name);
            printf("2. %s\n", champs[b].name);
            printf("3. %s\n", champs[c].name);

            int selectedTarget = scan(1, 3);

            if(selectedTarget == 1){
                clearScreen();
                applySpell(user, champs[a], usedSpell, a);
            }
            else if(selectedTarget == 2){
                clearScreen();
                applySpell(user, champs[b], usedSpell, b);
            }
            else if(selectedTarget == 3){
                clearScreen();
                applySpell(user, champs[c], usedSpell, c);
            }
        }
        else if(user.team == 2){
            printf("Sélectionnez un allié:\n\n");
            printf("1. %s\n", champs[d].name);
            printf("2. %s\n", champs[e].name);
            printf("3. %s\n", champs[f].name);

            int selectedTarget = scan(1, 3);

            if(selectedTarget == 1){
                clearScreen();
                applySpell(user, champs[d], usedSpell, d);
            }
            else if(selectedTarget == 2){
                clearScreen();
                applySpell(user, champs[e], usedSpell, e);
            }
            else if(selectedTarget == 3){
                clearScreen();
                applySpell(user, champs[f], usedSpell, f);
            }
        }
    }

}

void applySpell(champion user, champion target, spell usedSpell, int nb){

    int finalDmg = (usedSpell.damage * user.atk) / (target.def / 2.6);

    if(usedSpell.spellNature == 1){
        champs[nb].currentHp -= finalDmg;
        if(champs[nb].currentHp >= 0){
            champs[nb].currentHp = 0;
        }
        printf("%s\n", usedSpell.text1);
        printf("Cela inflige %d dégâts à " RED "%s" reset "\n\n", finalDmg, target.name);
        printf("%d/%d | " RED "%s" reset "\n", champs[nb].currentHp, champs[nb].maxHp, target.name);
        wait(5);
        clearScreen();
    }

    else if(usedSpell.spellNature == 2){
        champs[nb].currentHp += finalDmg;
        if(champs[nb].currentHp > champs[nb].maxHp){
            champs[nb].currentHp = champs[nb].maxHp;
        }
        printf("%s\n", usedSpell.text1);
        printf("Cela soigne %d PV à " GRN "%s" reset "\n\n", finalDmg, target.name);
        printf("%d/%d | " BLU "%s" reset "\n", champs[nb].currentHp, champs[nb].maxHp, target.name);
        wait(5);
        clearScreen();
    }

    usedSpell.currentCd = 0;

} 

void champTurn(champion champ){

    char teamName[char_size];

    displayChampHP();

    if(champ.team == 1){
        strcpy(teamName, player1Team);
    }
    else if(champ.team == 2){
        strcpy(teamName, player2Team);
    }

    printf("Equipe: %s | Au tour de " UBLU "%s" reset "\n\n", teamName, champ.name);

    printf("1. %s\n", champ.autoAttack.name);
    printf("%s\n", champ.autoAttack.desc);
    printf("Inflige %d dégâts\n\n", champ.autoAttack.damage*champ.atk);
    

    if(champ.spell1.spellNature == 1){  //Check if it's an attack
        printf("2. %s\n", champ.spell1.name);
        printf("%s\n", champ.spell1.desc);
        printf("Inflige %d dégâts | Temps de recharge: " YELB "%d tours" reset "\n\n", champ.spell1.damage*champ.atk, champ.spell1.cooldown);
    }
    else if(champ.spell1.spellNature == 2){  //Check if it's a healing spell
        printf("2. %s\n", champ.spell1.name);
        printf("%s\n", champ.spell1.desc);
        printf("Soigne de %d PV | Temps de recharge: " YELB "%d tours" reset "\n\n", champ.spell1.damage*champ.atk, champ.spell1.cooldown);
    }


    if (champ.spell2.spellNature == 1){  //Check if it's an attack
        printf("3. %s\n", champ.spell2.name);
        printf("%s\n", champ.spell2.desc);
        printf("Inflige %d dégâts | Temps de recharge: " YELB "%d tours" reset "\n\n", champ.spell2.damage*champ.atk, champ.spell2.cooldown);
    }
    else if (champ.spell2.spellNature == 2){  //Check if it's a healing spell
        printf("3. %s\n", champ.spell2.name);
        printf("%s\n", champ.spell2.desc);
        printf("Soigne de %d PV | Temps de recharge: " YELB "%d tours" reset "\n\n", champ.spell2.damage*champ.atk, champ.spell2.cooldown);
    }
        
    int selectedSpell = scan(1, 3);

    if(selectedSpell == 1){
        clearScreen();
        useSpell(champ, champ.autoAttack);
    }
    else if(selectedSpell == 2){
        clearScreen();
        useSpell(champ, champ.spell1);
    }
    else if(selectedSpell == 3){
        clearScreen();
        useSpell(champ, champ.spell2);
    }
}

void deathCheck(champion champ, int nb){
    if(champ.currentHp <= 0){
        champs[nb].status = 0;
    }
}


void brawl(){

    int brawling = 1;
    int numberOfChamps = 6;

    while(brawling == 1){

        int j = 0;
        int k = 0;

        int turn = 1;
        
        makeOrder(champs, numberOfChamps);  //We sort champs tab to make the fastest CHampions play first

        for(int i = 0; i < 6; i++){  //We assign Champions to teams to check win condition by verifying if team == 1 or team == 2
            if(champs[i].team == 1){
                if(j == 1){
                    teams[0].champ1 = champs[i];
                }
                else if(j == 2){
                    teams[0].champ2 = champs[i];
                }
                else if(j == 3){
                    teams[0].champ3 = champs[i];
                }
                j += 1;
            }   
        }

        for(int i = 0; i < 6; i++){  //We assign Champions to teams to check win condition by verifying if team == 1 or team == 2
            if(champs[i].team == 2){
                if(k == 1){
                    teams[1].champ1 = champs[i];
                }
                else if(k == 2){
                    teams[1].champ2 = champs[i];
                }
                else if(k == 3){
                    teams[1].champ3 = champs[i];
                }
                k += 1;
            }   
        }

        //We check win conditions for both teams
        if(teams[0].champ1.status == 0 && teams[0].champ2.status == 0 && teams[0].champ2.status == 0){
            brawling = 0;
            printEnding(player2Username, player2Team);
            break;
        }
        else if(teams[1].champ1.status == 0 && teams[1].champ2.status == 0 && teams[1].champ2.status == 0){
            brawling = 0;
            printEnding(player1Username, player1Team);
            break;
        }

        for(int i=0; i < 6; i++){  //We check if every Champion is dead to disable them
            for(int i=0; i < 6; i++){
                deathCheck(champs[i], i);
            }
            if(champs[i].status == 1){  //If a Champion is alive, he can play
                champTurn(champs[i]);
            }
        }

    }

}