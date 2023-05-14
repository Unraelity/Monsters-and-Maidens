#include "player.h"

void playerInfo(party *player, item **itemHead, item **itemTail) {
    
    char yesOrNo;
    
    printf("What is your name hero?\n");
    scanf("%s", player->name);
    printf("Are you sure? That's an odd name. (y\\n)\n");
    scanf("%*c%c", &yesOrNo);
    
    while (yesOrNo == 'n') {
        printf("Then what is your name actually this time?\n");
        scanf("%s", player->name);
        printf("Are you sure? That's still an odd name. (y\\n)\n");
        scanf("%*c%c", &yesOrNo);
    }
    
    player->maxHP = 10;
    player->hp = 10;
    player->attack = 5;
    player->defense = 5;
    player->speed = 5;
    player->gold = 0;
    player->maxEXP = 7;
    player->exp = 0;
    player->level = 1;
    player->numWins = 0;
    player->numLosses = 0;
    
    setMagic(player);
    setItems(itemHead, itemTail);
    
}

int getStats(party *player, companion *companion, item **itemHead, item **itemTail, int eventNum) {
    
    char targetName[50], nameFile[50], fileName[50], yesOrNo = 'y', continued = 'y';
    FILE *inp;
    
    while (yesOrNo == 'y') {
        printf("I definitely didn't forget your name, but you how do you spell it again?\n");
        scanf("%s", targetName);
        
        strcpy(fileName, targetName);
        strcat(fileName, "'s_Stats.txt\0");
        inp = fopen(fileName, "r");
        
        while ((inp == NULL) &&  (yesOrNo != 'n')) {
            
            printf("I couldn't find your name. Make sure you spelled it right with all correct capitilization. \n");
            sleep(2);
            printf("It's hard work looking through files.\n");
            sleep(1);
            printf("Would you like to try again?\n");
            printf("(Type y/n)\n");
            scanf("%*c%c", &yesOrNo);
            while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
                printf("Type (y/n)\n");
                scanf("%*c%c", &yesOrNo);
            }
            
            if (yesOrNo == 'y') {
                printf("I definitely didn't forget your name, but you how do you spell it again?\n");
                scanf("%s", targetName);
                
                strcpy(fileName, targetName);
                strcat(fileName, "'s_Stats.txt\0");
                inp = fopen(fileName, "r");
            }
            
        }
        
        if (yesOrNo == 'n') {
            printf("Alright, I'll just set you up from the beginning.\n");
            sleep(1);
            playerInfo(player, itemHead, itemTail);
            break;
        }
        
        rewind(inp);
        
        while (fscanf(inp, "%s", nameFile) != EOF) {
            if (strcmp(targetName, nameFile) == 0) {
                strcpy(player->name, nameFile);
                fscanf(inp, " %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &player->maxHP, &player->maxMP, &player->magic[HEAL][1], &player->magic[FIRE][1], &player->magic[SHIELD][1], &player->magicDefense, &player->attack, &player->defense, &player->speed, &player->gold, &player->maxEXP, &player->exp, &player->level, &eventNum, &player->numWins, &player->numLosses);
            }
        }
        
        if (strcmp(player->name, targetName) != 0) {
            printf("I couldn't find your name. Make sure you spelled it right with all correct capitilization. \n");
            sleep(2);
            printf("It's hard work looking through files.\n");
            sleep(1);
            printf("Would you like to try again?\n");
            printf("(Type y/n)\n");
            scanf("%*c%c", &yesOrNo);
            while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
                printf("Type (y/n)\n");
                scanf("%*c%c", &yesOrNo);
            }
        }
        else {
            yesOrNo = 'n';
        }
        
        if (strcmp(player->name, targetName) == 0) {
            printf("Found ya! Welcome back %s!\n", player->name);
            sleep(1);
            printf("You were always my favorite! What do you mean I say that about everyone?\n");
            sleep(2);
            
            player->hp = player->maxHP;
            player->mp = player->maxMP;
            if (player->level >= 15) {
                player->magic[HEAL][0] = HEAL;
                player->magic[FIRE][0] = FIRE;
                player->magic[SHIELD][0] = SHIELD;
            }
            else if (player->level >= 10) {
                player->magic[HEAL][0] = HEAL;
                player->magic[FIRE][0] = FIRE;
                player->magic[SHIELD][0] = LOCKED;
            }
            else if (player->level >= 5) {
                player->magic[HEAL][0] = HEAL;
                player->magic[FIRE][0] = LOCKED;
                player->magic[SHIELD][0] = LOCKED;
            }
            else {
                player->magic[HEAL][0] = LOCKED;
                player->magic[FIRE][0] = LOCKED;
                player->magic[SHIELD][0] = LOCKED;
            }
            getItems(player, itemHead, itemTail);
            getCompanion(*player, companion);
            
            if (eventNum > 0) {
                printf("Would you like to continue from where you left off?\n");
                printf("(Type y/n)\n");
                scanf("%*c%c", &continued);
                while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
                    printf("Type (y/n)\n");
                    scanf("%*c%c", &yesOrNo);
                }
            }
            
            if (continued == 'n') {
                printf("Alright, I'll just set you up from the beginning, but you'll keep your stats and item from before.\n");
                sleep(2);
                eventNum = 0;
            }
        }
        
        else if (yesOrNo == 'n') {
            printf("Alright, I'll just set you up from the beginning.\n");
            sleep(1);
            playerInfo(player, itemHead, itemTail);
        }
        
        fclose(inp);
        
    }
    
    return eventNum;
}

void saveCharacter(party player, int eventNum) {
    
    FILE *outp;
    
    char fileName[50];
    
    strcpy(fileName, player.name);
    strcat(fileName, "'s_Stats.txt\0");
    outp = fopen(fileName, "w");
    
    if (eventNum == ENDGAME) {
        eventNum = 0;
    }
    else {
        printf("Progress saved!\n");
        sleep(1);
    }
    
    fprintf(outp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", player.name, player.maxHP, player.maxMP, player.magic[HEAL][1], player.magic[FIRE][1], player.magic[SHIELD][1], player.magicDefense, player.attack, player.defense, player.speed, player.gold, player.maxEXP, player.exp, player.level, eventNum, player.numWins, player.numLosses);
    
    fclose(outp);
    printf("Stats saved!\n");
    usleep(100000);
    
}
