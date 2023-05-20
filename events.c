#include "events.h"

int events(party player, companion companion, monster monster, item *itemHead, item *itemTail, int eventNum, bool hardMode) {
    
    char continues;
    int timesShopped = 0, timesTraded = 0, timesRiddled = 0, tipTimes = 0, i, win, eventRandomizer, j = 0;
    stat statBoosts[2] = {0};
    strcpy(player.statusCondition, "NONE");
    
    for (i = eventNum; i < ENDGAME; i++) {
        
        continues = 'n';
        strcpy(monster.statusCondition, "NONE");
        
        printf("(Type c to continue, p for check your stats, i for items, s for shop, t for tips or q to save and quit)\n");
        while ((continues != 'c') && (continues != 'q')) {
            scanf("%*c%c", &continues);
            if (continues == 't') {
                tipTimes = printTips(player, companion, tipTimes);
                printf("(Type c to continue, p for check your stats, i for items, s for shop, t for tips or q to save and quit)\n");
            }
            else if (continues == 's') {
                timesShopped = shop(&player, companion, &itemHead, &itemTail, timesShopped);
                printf("(Type c to continue, p for check your stats, i for times, s for shop, t for tips or q to save and quit)\n");
            }
            else if (continues == 'p') {
                printStats(player, companion);
                printf("(Type c to continue, p for check your stats, i for items, s for shop, t for tips or q to save and quit)\n");
            }
            else if (continues == 'i') {
                while (continues != 'n') {
                    printf("%s:%d/%d:%d/%d\n", player.name, (int)player.hp, (int)player.maxHP, (int)player.mp, (int)player.maxMP);
                    itemsMenu(&player, &itemHead, &itemHead, &statBoosts[PLAYER_STATS]);
                    printf("Would you like to use another item? (y\\n)\n");
                    scanf("%*c%c", &continues);
                    while ((continues != 'y') && (continues != 'n')) {
                        scanf("%*c%c", &continues);
                    }
                }
                printf("(Type c to continue, p for check your stats, i for items, s for shop, t for tips or q to save and quit)\n");
            }
        }
        
        if (continues == 'q') {
            saveCharacter(player, i);
            saveItems(player, &itemHead);
            saveCompanion(player, companion);
            return 0;
        }
        
        if ((i == 4) && (companion.tamed != true)) {
            createCompanion(&companion);
            win = companionBattle(&player, &companion, &itemHead, &itemTail);
            
            if (win == -1) {
                gameOver(&player, &companion, &itemHead, i);
                return -1;
            }
            
            continues = 'n';
            
            printf("(Type c to continue, p for check your stats, s for shop, t for tips or q to save and quit)\n");
            while ((continues != 'c') && (continues != 'q')) {
                scanf("%*c%c", &continues);
                if (continues == 't') {
                    tipTimes = printTips(player, companion, tipTimes);
                    printf("(Type c to continue, p for check your stats, s for shop, t for tips or q to save and quit)\n");
                }
                else if (continues == 's') {
                    timesShopped = shop(&player, companion, &itemHead, &itemTail, timesShopped);
                    printf("(Type c to continue, p for check your stats, s for shop, t for tips or q to save and quit)\n");
                }
                else if (continues == 'p') {
                    printStats(player, companion);
                    printf("(Type c to continue, p for check your stats, s for shop, t for tips or q to save and quit)\n");
                }
                else if (continues == 'i') {
                    while (continues != 'n') {
                        printf("%s:%d/%d:%d/%d\n", player.name, (int)player.hp, (int)player.maxHP, (int)player.mp, (int)player.maxMP);
                        itemsMenu(&player, &itemHead, &itemHead, &statBoosts[PLAYER_STATS]);
                        printf("Would you like to use another item? (y\\n)\n");
                        scanf("%*c%c", &continues);
                        while ((continues != 'y') && (continues != 'n')) {
                            scanf("%*c%c", &continues);
                        }
                    }
                    printf("(Type c to continue, p for check your stats, i for items, s for shop, t for tips or q to save and quit)\n");
                }
            }
            
            if (continues == 'q') {
                saveCharacter(player, i);
                saveItems(player, &itemHead);
                saveCompanion(player, companion);
                return 0;
            }
        }
        
        eventRandomizer = rand() % 15;
        
        if (j >= 4) {
            if (eventRandomizer < 5) {
                eventRandomizer = 6;
            }
            else if ((eventRandomizer >= 5) && (eventRandomizer < 10)) {
                eventRandomizer = 9;
            }
            else if ((eventRandomizer >= 10) && (eventRandomizer < 15)) {
                eventRandomizer = 8;
            }
        }
        
        if ((eventRandomizer == 6) && (i > 0) && (i != 4) && (i != 9) && (i != 14) && (i != 19)) {
                win = dealWithDevil(&player, companion, &timesTraded);
                j = 0;
        }
        else if ((eventRandomizer == 9) && (i > 0) && (i != 4) && (i != 9) && (i != 14) && (i != 19)) {
                win = goneFishing(&player, companion, &itemHead, &itemTail);
                j = 0;
        }
        else if ((eventRandomizer == 8) && (i > 0) && (i != 4) && (i != 9) && (i != 14) && (i != 19)) {
                win = riddleMan(&player, &itemHead, &itemTail, &timesRiddled);
                j = 0;
        }
        else {
            if (companion.tamed) {
                win = battleTime2(&player, &monster, &companion, &itemHead, &itemTail, i, hardMode);
                j++;
            }
            else {
                win = battleTime(&player, &monster, &itemHead, &itemTail, i, hardMode);
                j++;
            }
        }
        
        if (win == -1) {
            gameOver(&player, &companion, &itemHead, i);
            return -1;
        }
        
    }
    
    victory(&player, &companion, &itemHead, i, hardMode);
    
    return 1;
}

