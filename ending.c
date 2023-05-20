#include "ending.h"

void victory(party *player, companion *companion, item **head, int eventNum, bool hardMode) {
    
    char yesOrNo;
    
    printVictory();
    credits();
    
    player->numWins++;
    printf("Number of Losses: %d\n", player->numLosses);
    sleep(1);
    printf("Number of Wins: %d\n", player->numWins);
    sleep(5);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Thanks for playing!\n");
    sleep(2);
    if (hardMode) {
        printf("WHAT you BEAT HARD MODE??!!\n");
        sleep(3);
        printf("You must REALLY enjoy GRINDING...\n");
        sleep(3);
        printf("I hereby grant you the title: \n");
        sleep(3);
        printf("%s, the GREATEST HERO IN HEROVILLE\n", player->name);
        sleep(5);
        printf("truly.\n");
        sleep(10);
    }
    else {
        printf("%s, a TRUE HERO!\n", player->name);
        sleep(10);
    }
    
    printf("Would you like to save your character and items?\n");
    printf("(Type y/n)\n");
    scanf("%*c%c", &yesOrNo);
    if (yesOrNo == 'y') {
        saveCharacter(*player, eventNum);
        saveItems(*player, head);
        saveCompanion(*player, *companion);
    }
}

void gameOver(party *player, companion *companion, item **head, int event) {
    
    char yesOrNo;
    
    printLose();
    
    player->numLosses++;
    
    printf("Would you like to save your character and items?\n");
    printf("(Type y/n)\n");
    scanf("%*c%c", &yesOrNo);
    if (yesOrNo == 'y') {
        saveCharacter(*player, event);
        saveItems(*player, head);
        saveCompanion(*player, *companion);
    }
}

void credits(void) {
    
    printf("CREDITS: \n");
    sleep(3);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("CODE: \n");
    sleep(1);
    printf("NICK BROWN");
    sleep(5);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("SCRIPT: \n");
    sleep(1);
    printf("NICK BROWN");
    sleep(3);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("ARTWORK: \n");
    sleep(1);
    printf("NICK BROWN");
    sleep(3);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
}
