#include "riddles.h"

int riddleMan(party *player, item **head, item **tail, int *timesPlayed) {
    
    printRiddleMaster(*player);
    sleep(1);
    
    int randQuestion = 0, question[3] = {-1};
    char userAnswer, correctAnswer;
    
    if (*timesPlayed == 0) {
        printf("RIDDLEMASTER: Hello WANDERING HERO. How would YOU like to PLAY a LITTLE GAME?\n");
        sleep(3);
        printf("D: I don't know this guy is kinda CREEPY.\n");
        sleep(1);
        printf("RIDDLEMASTER: You do realize I am standing right here right?\n");
        sleep(2);
        printf("RIDDLEMASTER: Answer my 3 questions correctly and receive a prize...\n");
        sleep(2);
        printf("RIDDLEMASTER: Answer a question incorrectly and receive nothing...\n");
        sleep(2);
    }
    else {
        printf("RIDDLEMASTER: Hello again, OLD FRIENDS.\n");
        sleep(1);
        printf("D: Oh jeez, not THIS GUY AGAIN.\n");
        sleep(1);
        printf("RIDDLEMASTER: Still standing right here...\n");
        sleep(1);
        printf("RIDDLEMASTER: Shall we play another GAME?\n");
        sleep(1);
        printf("RIDDLEMASTER: You know the rules let's hop to it.\n");
        sleep(2);
    }
    
    (*timesPlayed)++;
    
    for (int i = 0; i < 3; i++) {
        
        while ((randQuestion == question[0]) || (randQuestion == question[1])) {
            randQuestion = (rand() % 10) + 1;
        }
        
        printf("Question %d:  ", i+1);
        sleep(1);
        
        switch(randQuestion) {
            case 1:
                question[i] = 1;
                printf("What has to be BROKEN before you can use it?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. A CAR\n");
                sleep(1);
                printf("b. AN EGG\n");
                sleep(1);
                printf("c. A LEG\n");
                correctAnswer = 'b';
                sleep(3);
                printf("D: Proably not a leg.\n");
                sleep(1);
                break;
            case 2:
                question[i] = 2;
                printf("What is always IN FRONT of you but CANNOT be SEEN?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. THE FUTURE\n");
                sleep(1);
                printf("b. YOUR FEET\n");
                sleep(1);
                printf("c. ANYTHING BEHIND WALLS\n");
                correctAnswer = 'a';
                sleep(3);
                printf("D: Can't you always see what's in front of you? Isn't that the point of seeing?\n");
                sleep(3);
                break;
            case 3:
                question[i] = 3;
                printf("What can you keep after giving it to someone?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. YOUR PRIZED POSSESSION\n");
                sleep(1);
                printf("b. A SECRET\n");
                sleep(1);
                printf("c. YOUR WORD\n");
                correctAnswer = 'c';
                sleep(3);
                printf("D: That's a tough one...\n");
                sleep(1);
                break;
            case 4:
                question[i] = 4;
                printf("A man dies of old age on his 25th birthday. How is this possible?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. HE WAS BORN ON FEBRUARY 29TH.\n");
                sleep(1);
                printf("b. HE LIVED DURING MEDIEVAL TIMES.\n");
                sleep(1);
                printf("c. I DON'T KNOW. A CAR ACCIDENT?\n");
                correctAnswer = 'a';
                sleep(3);
                printf("D: What kind of 'QUESTION' is that?? How could we KNOW this?\n");
                sleep(3);
                break;
            case 5:
                question[i] = 5;
                printf("WHO IS THE SMARTEST MAN IN THE WORLD?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. KING PORK\n");
                sleep(1);
                printf("b. %s\n", player->name);
                sleep(1);
                printf("c. RIDDLEMASTER\n");
                correctAnswer = 'c';
                sleep(3);
                printf("D: I think I COULD guess this one.\n");
                sleep(1);
                break;
            case 6:
                question[i] = 6;
                printf("WHAT IS BLACK WHEN IT'S CLEAN AND WHITE WHEN IT'S DIRTY?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. A BLACK CAR\n");
                sleep(1);
                printf("b. A CHALKBOARD\n");
                sleep(1);
                printf("c. SPACE\n");
                correctAnswer = 'b';
                sleep(3);
                printf("D: I'm starting to NOT LIKE this guy.\n");
                sleep(1);
                break;
            case 7:
                question[i] = 7;
                printf("I'M LIGHT AS A FEATHER, YET THE STRONGEST PERSON CAN'T HOLD ME FOR FIVE MINUTES. WHAT AM I?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. YOUR BREATH\n");
                sleep(1);
                printf("b. A THOUGHT\n");
                sleep(1);
                printf("c. HOPE DURING DARK TIMES\n");
                correctAnswer = 'a';
                sleep(3);
                printf("D: Hope during dark times?? Aren't we a little DOOM and GLOOM.\n");
                sleep(1);
                printf("RIDDLEMASTER: Just answer the question.\n");
                sleep(1);
                break;
            case 8:
                question[i] = 8;
                printf("WHAT GETS WET WHILE DRYING?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. HAIR\n");
                sleep(1);
                printf("b. A FISH\n");
                sleep(1);
                printf("c. A TOWEL\n");
                correctAnswer = 'c';
                sleep(3);
                printf("D: That doesn't even make sense. Doesn't that make an OXYMORON??\n");
                sleep(3);
                printf("RIDDLEMASTER: Your an OXYMORON...\n");
                sleep(1);
                break;
            case 9:
                question[i] = 9;
                printf("WHERE DOES TODAY COME BEFORE YESTERDAY?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. A TIME MACHINE\n");
                sleep(1);
                printf("b. A DICTIONARY\n");
                sleep(1);
                printf("c. A TOWEL\n");
                correctAnswer = 'b';
                sleep(3);
                printf("D: A TIME MACHINE? Isn't this supposed to be MEDIEVAL TIMES? How are there TIME MACHINES??\n");
                sleep(3);
                printf("RIDDLEMASTER: I don't know. I don't make the questions.\n");
                sleep(2);
                printf("D: If YOU don't make the questions, WHO DOES?\n");
                sleep(2);
                printf("RIDDLEMASTER: ...\n");
                sleep(3);
                break;
            case 10:
                question[i] = 10;
                printf("IT BELONGS TO YOU, BUT OTHER PEOPLE USE IT MORE THAN YOU DO. WHAT IS IT?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. YOUR NAME\n");
                sleep(1);
                printf("b. YOUR LOVE\n");
                sleep(1);
                printf("c. YOUR FRONT DOOR\n");
                correctAnswer = 'a';
                sleep(3);
                printf("D: What the...\n");
                sleep(1);
                break;
            default:
                question[i] = 5;
                printf("WHO IS THE SMARTEST MAN IN THE WORLD?\n");
                sleep(3);
                printf("Is it: \n");
                sleep(1);
                printf("a. KING PORK.\n");
                sleep(1);
                printf("b. %s.\n", player->name);
                sleep(1);
                printf("c. RIDDLEMASTER.\n");
                correctAnswer = 'c';
                sleep(3);
                printf("D: I think I COULD guess this one.\n");
                sleep(1);
        }
        
        printf("(Type a, b or c)\n");
        scanf("%*c%c", &userAnswer);
        
        while ((userAnswer != 'a') && (userAnswer != 'b') && (userAnswer != 'c')) {
            printf("(Type a, b or c)\n");
            scanf("%*c%c", &userAnswer);
        }
        
        printf("RIDDLEMASTER: THAT'S");
        usleep(100000);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        
        
        if (userAnswer == correctAnswer) {
            printf("CORRECT!\n");
            sleep(1);
            if (i == 0) {
                printf("RIDDLEMASTER: NEXT QUESTION\n");
                sleep(1);
            }
            else if (i == 1) {
                printf("RIDDLEMASTER: FINAL QUESTION\n");
                sleep(1);
            }
        }
        else {
            printf("WRONG!\n");
            sleep(1);
            printf("RIDDLEMASTER: Better luck next time!\n");
            sleep(1);
            return 1;
        }
        
    }
    
    printf("RIDDLEMASTER: Nice RIDDLING!\n");
    sleep(1);
    printf("RIDDLEMASTER: As promised here's your PRIZE...\n");
    sleep(2);
    
    int treasureNum = rand() % 12;
    item newItem;
    
    if ((treasureNum == 0) || (treasureNum == 10) || (treasureNum == 11)) {
            
        int gold = rand() % 50;
        player->gold = player->gold + gold + 10;
        printf("You got %d G from the RIDDLEMASTER!\n", gold + 10);
        sleep(1);
            
    }
    else if (treasureNum == 1) {
            
        strcpy(newItem.name, "POTION");
        addItem(player, &newItem, head, tail);
        printf("You got a POTION from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 2) {
            
        strcpy(newItem.name, "ELIXIR");
        addItem(player, &newItem, head, tail);
        printf("You got an ELIXIR from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 3) {
            
        strcpy(newItem.name, "ANTIDOTE");
        addItem(player, &newItem, head, tail);
        printf("You got an ANTIDOTE from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 4) {
            
        strcpy(newItem.name, "OINTMENT");
        addItem(player, &newItem, head, tail);
        printf("You got an OINTMENT from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 5) {
            
        strcpy(newItem.name, "X-ATTACK");
        addItem(player, &newItem, head, tail);
        printf("You got an X-ATTACK from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 6) {
            
        strcpy(newItem.name, "X-DEFENSE");
        addItem(player, &newItem, head, tail);
        printf("You got an X-DEFENSE from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 7) {
            
        strcpy(newItem.name, "X-MAGIC");
        addItem(player, &newItem, head, tail);
        printf("You got an X-MAGIC from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
    else if (treasureNum == 8) {
            
        strcpy(newItem.name, "X-MAGIC-DEFENSE");
        addItem(player, &newItem, head, tail);
        printf("You got an X-MAGIC-DEFENSE from the RIDDLEMASTER!\n");
        sleep(1);
         
    }
    else if (treasureNum == 9) {
            
        strcpy(newItem.name, "X-SPEED");
        addItem(player, &newItem, head, tail);
        printf("You got an X-SPEED from the RIDDLEMASTER!\n");
        sleep(1);
            
    }
        
    printf("RIDDLEMASTER: LET's PLAY AGAIN SOMETIME!\n");
    sleep(1);
    return 1;
    
}
