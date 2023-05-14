#include "ending.h"

void victory(party *player, companion *companion, item **head, int eventNum) {
    
    char yesOrNo;
    
    printVictory();
    
    player->numWins++;
    printf("Number of Losses: %d\n", player->numLosses);
    sleep(1);
    printf("Number of Wins: %d\n", player->numWins);
    sleep(1);
    
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
