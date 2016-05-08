#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

string input;

//player stats - add as needed
int playerDead = 0;
int playerHatedByGlowCloud = 0;
int playerHasPaper = 0;
int playerHasWeapon = 0;
int moreWorms = 0;
int wormsAreDone = 0;
int playerReadPaper = 0;
int playerReadMorse = 0;

string nvWords[10] = {"night",           "vale",          "carlos",                  "worms",             "hide",         "king", "city","dragon","dogpark","bluffs"};
string nvMorse[10] = {"-. .. --. .... -","...- .- .-.. .","-.-. .- .-. .-.. --- ...",".-- --- .-. -- ...",".... .. -.. .","-.- .. -. --.","-.-. .. - -.--","-.. .-. .- --. --- -.","-.. --- --. .--. .- .-. -.-","-... .-.. ..- ..-. ..-. ..."};

string messageOne;
string messageOneMorse;
string messageTwo;
string messageTwoReversed;

void intro();
void sceneOne();
void sceneTwo();
void sceneThree();
void sceneFour();
void sceneFive();
void sceneSix();

void meetTheStranger();
void wormsTwo();

void theRandomizer();

void setup() {
    // put your setup code here, to run once:
    
    // Serial.begin(9600);
    // randomSeed(analogRead(A0));
}

int main() {
    // put your main code here, to run repeatedly:
    intro();
    srand ( unsigned(time(NULL)));
    int messageOneIndex = rand() % 11;
    int messageTwoIndex = rand() % 11;
    messageOne = nvWords[messageOneIndex];
    messageOneMorse = nvMorse[messageOneIndex];
    messageTwo = nvWords[messageTwoIndex];
    messageTwoReversed = messageTwo;
   reverse(messageTwoReversed.begin(),messageTwoReversed.end());
   // cout << endl << messageOne << messageOneMorse << endl << messageTwo << messageTwoReversed;
    
    while(1) {
        theRandomizer();
        if (playerDead == 1)
        {
            printf("You are dead. Game over.\n>");
            while (1);
        }
    }
    
}
void theRandomizer() {
    int sceneNum = rand() % 5; //CHANGE TO SCENECOUNTS + 1
  //  int dead = 0;
    switch (sceneNum) {
        case 1:
            sceneOne();
            break;
        case 2:
            sceneTwo();
            break;
        case 3:
            sceneThree();
            break;
        case 4:
            sceneFour();
            break;
        case 5:
            sceneFive();
            break;
    }
  //  return dead;
}


void intro() {
    printf("\033[35m_ _ _ ____ _    ____ ____ _  _ ____\033[0m\n");
    printf("\033[35m| | | |___ |    |    |  | |\\/| |___\033[0m\n");
    printf("\033[35m|_|_| |___ |___ |___ |__| |  | |___\033[0m\n");
    printf("\n");
    usleep(500000);
        printf("\033[35m___ ____\033[0m\n");
    printf("\033[35m |  |  |\033[0m\n");
    printf("\033[35m |  |__|\033[0m\n");
    printf("\n");
    usleep(500000);
    printf("\033[35m_  _ _ ____ _  _ ___    _  _ ____ _    ____\033[0m\n");
    printf("\033[35m|\\ | | | __ |__|  |     |  | |__| |    |___\033[0m\n");
    printf("\033[35m| \\| | |__] |  |  |      \\/  |  | |___ |___\033[0m\n");
    printf("\n");
    usleep(500000);
    printf("By domojz-vance\n");
    printf("Some quotes by Cecilspeaks.\n");
    printf("Thanks to (PLACEHOLDER)\n\n");
    usleep(1000000);
}

void sceneOne() {
START:
    printf("You pass the Glow Cloud on the street. Either HAIL or say HELLO.\n>");
    cin >> input;
    if(input == "HAIL") {
        printf("ALL HAIL THE GLOW CLOUD. ALL HAIL.\n\n>");
        return;
    }
    else if(input == "HELLO") {
        if (playerHatedByGlowCloud == 1)
        {
            printf("The Glow Cloud has warned you about this. It kills you with a buffalo\n");
            playerDead = 1;
            return;
        }
        else
        {
        
        printf("You must hail the Mighty Glow Cloud! It spares you out of spite. You are now HATED BY THE GLOW CLOUD.\n\n>");
        playerHatedByGlowCloud = 1;
        return;
        }
        }
    else
    {
        printf("(error)\n\n>");
        goto START;
    }
}




void sceneTwo() {
START:
    printf("Animal carcasses begin falling from the sky as you are eating dinner at Big Rico's Pizza. You worry about the strength of the roof. You can either try to HIDE downstairs in the basement or ASK the Glow Cloud to stop.\n>");
    cin >> input;
    if(input == "HIDE") {
        printf("You go to the basment and meet a mysterious stranger. You do not recognize him. He is wearing a tan jacket and carrying a deerskin suitcase. This seems odd until he tells you that he is a fly salesman.\n\n>");
        if (playerHasPaper == 1) {
            printf("He says hello as if he knows you, but you do not know him.\n\n>");
            return;
        }
        else
        {
            printf("The gives you a paper. There are words on it that you cannot read.\n\n>");
            playerHasPaper = 1;
            return;
        }
    }
    
    else if (input == "ASK")
    {
        if (playerHatedByGlowCloud == 1)
        {
            printf("The Glow Cloud Hates you! It strikes you with a dead snake.\n\n>");
            playerDead = 1;
            return;
        }
        else
        {
            printf("The Glow Cloud realizes it is being melodramatic, and politely stops.\n\n>");
            return;
        }
    }
    else
    {
        goto START;
    }
}

void sceneThree()
{
START:
    if (moreWorms == 1) {
        wormsTwo();
        return;
    }
    if (wormsAreDone == 1) {
        return;
    }
    
    printf("The worms have returned. They’re doing all of the usual worm things: flying around and dropping trees onto cars and houses, spitting venom at people, and eating stray cats and then leaving large mewling pellets all about town. There is nothing to do but HIDE.\n>");
    cin >> input;
    if (input == "HIDE") {
    HIDE:
        printf("You hide, and you survive.\n");
        moreWorms = 1;
        return;
    }
    else
    {
        printf("Are you sure you do not want to HIDE?\n>");
        cin >> input;
        if (input == "HIDE") {
            goto HIDE;
        }
        else
        {
            printf("Are you completely sure?\n>");
            cin >> input;
            if (input == "HIDE") {
                goto HIDE;
            }
            else
            {
                if (playerHasWeapon == 1) {
                    printf("Something happens idk\n>");
                    return;
                }
                else
                {
                    printf("Why didn't you hide? You have been killed by a worm.");
                    playerDead = 1;
                    return;
                }
                
            }
        }
    }
    
}

void sceneFour() {
    if (playerHasPaper == 0)
    {
        printf("You see a glimpse of the future. Whoops, time must have broken again.\n\n");
        return;
    }
    if (playerReadPaper == 1)
    {
        printf("You remember the paper on your hand.\n");
        return;
    }
    else
    {
    printf("You realize that you have a piece of paper in your hand. You read it. It says:\n");
    cout << messageTwoReversed;
    printf(" :si drowssap ehT\n\n");
   // cin.get();
    return;
    }
}

void sceneFive()
{
    printf("You are laying in bed when you hear beeping coming from under your bed.\nIt says ");
    cout << messageOneMorse << endl << endl;
    playerReadMorse = 1;
}

void sceneSix()
{
START:
    string input;
    if (playerReadPaper == 1 && playerReadMorse == 1)
    {
        printf("You notice a blinking computer terminal on the side of the road. You can LOOK at the screen or CONTINUE walking.\n>");
        cin >> input;
        if (input == "LOOK")
        {
            
        }
        else if (input == "CONTINUE")
        {
            printf("You continue walking, but with an odd sense of regret.\n");
            return;
        }
        else
        {
            goto START;
        }
    }
    else
    {
        return;
    }
}


void wormsTwo() {;
    printf("The worms are back. Again. This time, City Council has changed the warning level to \"Worms!!\". It was previously \"worms…\". Still, are there is to do is HIDE.\n>");
    cin >> input;
    if (input == "HIDE") {
    HIDE:
        printf("You hide, and you survive until the worms back down, thanks to a flamethrower and fierce rhetoric by the City Council, resulting in some sick burns ... both metaphorically and literally..\n");
        wormsAreDone = 1;
        return;
    }
    else
    {
        printf("Are you sure you do not want to HIDE?\n>");
        cin >> input;
        if (input == "HIDE") {
            goto HIDE;
        }
        else
        {
            printf("Are you completely sure?\n>");
            cin >> input;
            if (input == "HIDE") {
                goto HIDE;
            }
            else
            {
                if (playerHasWeapon == 1) {
                    printf("Something happens idk\n>");
                    return;
                }
                else
                {
                    printf("Why didn't you hide? You have been killed by a worm.");
                    playerDead = 1;
                    return;
                }
                
            }
        }
    }
    
}

