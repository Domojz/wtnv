#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>

using namespace std;

string input;

//player stats - add as needed
int playerDead = 0;
int playerHatedByGlowCloud = 0;
int playerMetTheMan = 0;

void intro();
void sceneOne();
void sceneTwo();

void meetTheStranger();

int theRandomizer();

void setup() {
    // put your setup code here, to run once:
    
    // Serial.begin(9600);
    // randomSeed(analogRead(A0));
}

int main() {
    // put your main code here, to run repeatedly:
    intro();
    srand ( unsigned(time(NULL)));
    while(1) {
        theRandomizer();
        if (playerDead == 1)
        {
            printf("You are dead. Game over.");
            return 1;
        }
    }
    
}
int theRandomizer() {
    int sceneNum = rand() % 3; //CHANGE TO SCENECOUNTS + 1
    int dead = 0;
    switch (sceneNum) {
        case 1:
            sceneOne();
            break;
        case 2:
            sceneTwo();
            break;
    }
    return dead;
}


void intro() {
    
    
    printf("   \n");
    
    printf("   _ _ _ ____ _    ____ ____ _  _ ____\n");
    printf("   | | | |___ |    |    |  | |\\/| |___\n");
    printf("   |_|_| |___ |___ |___ |__| |  | |___\n");
    printf("\n");
    printf("   ___ ____\n");
    printf("    |  |  |\n");
    printf("    |  |__|\n");
    printf("\n");
    printf("   _  _ _ ____ _  _ ___    _  _ ____ _    ____\n");
    printf("   |\\ | | | __ |__|  |     |  | |__| |    |___\n");
    printf("   | \\| | |__] |  |  |      \\/  |  | |___ |___\n");
    printf("   \n");
    printf("By domojz-vance\n");
}
void sceneOne() {
START:
    printf("You pass the Glow Cloud on the street. Either HAIL or say HELLO.\n>");
    cin >> input;
    if(input == "HAIL") {
        printf("ALL HAIL THE GLOW CLOUD. ALL HAIL.\n");
        return;
    }
    else if(input == "HELLO") {
        printf("You must hail the Mighty Glow Cloud! It spares you out of spite.\nYou are now HATED BY THE GLOW CLOUD.\n");
        playerHatedByGlowCloud = 1;
        return;
    }
    else
    {
        printf("(error)\n");
        goto START;
    }
}


void meetTheStranger(){
START:
    printf("meet a mysterious stranger. You do not recognize him. He is wearing a tan jacket and carrying a deerskin suitcase. This seems odd until he tells you that he is a fly salesman.\n");
    if (playerMetTheMan == 1) {
        printf("He says hello as if he knows you, but you do not know him.\n");
        return;
    }
    else
    {
        printf("The man tells you that great mysteries are afoot. He gives you a paper. There are words on it that you cannot read.\n");
        return;
    }
}

void sceneTwo() {
START:
    printf("Animal carcasses begin falling from the sky as you are eating dinner at Big Rico's Pizza. You worry about the strength of the roof. You can either try to HIDE downstairs in the basement or ASK the Glow Cloud to stop.\n>");
    cin >> input;
    if(input == "HIDE") {
        printf("You go to the basment and ");
        meetTheStranger();
        return;
    }
    else if (input == "ASK")
    {
        if (playerHatedByGlowCloud == 1)
        {
            printf("The Glow Cloud Hates you! It strikes you with a dead snake.\n");
            playerDead = 1;
            return;
        }
        else
        {
            printf("The Glow Cloud realizes it is being melodramatic, and politely stops.\n");
            return;
        }
    }
    else
    {
        goto START;
    }
}
