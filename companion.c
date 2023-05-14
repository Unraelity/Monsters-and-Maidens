#include "companion.h"

void createCompanion(companion *companion) {
    
    strcpy(companion->name, "WOLF");
    companion->hp = 15;
    companion->maxHP = 15;
    companion->attack = 7;
    companion->defense = 5;
    companion->speed = 11;
    companion->level = 3;
    companion->maxEXP = 7;
    companion->exp = 0;
    companion->tamed = false;
    
}

void getCompanion(party player, companion *companion) {
    
    FILE *inp;
    char fileName[50];
    strcpy(fileName, player.name);
    
    strcat(fileName, "'s_Companion.txt\0");
    inp = fopen(fileName, "r");
    
    if (inp == NULL) {
        printf("Looks like you didn't have any companions.\n");
        sleep(1);
    }
    else {
        
        fscanf(inp, "%s %d %d %d %d %d %d", companion->name, &companion->maxHP, &companion->attack, &companion->speed, &companion->maxEXP, &companion->exp, &companion->level);
        printf("Found your buddy %s.\n", companion->name);
        sleep(1);
        companion->tamed = true;
        
        fclose(inp);
    }
    
}

int companionBattle(party *player, companion *companion, item **head, item **tail) {
    
    int playerChoice, turnOrder, useItem;
    char companionName[50];
    
    printCompanionBattle(*player, *companion);
    
    printf("Oh no you encountered a %s!\n", companion->name);
    sleep(1);
    printf("D: What a FOUL BEAST!\n");
    sleep(1);
    
    while ((player->hp > 0) && (companion->hp > 0)) {
        
        useItem = 0;
        
        printf("%s:%d/%d:%d/%d   %s:%d/%d\n", player->name, player->hp, player->maxHP, player->mp, player->maxMP, companion->name, companion->hp, companion->maxHP);
        
        playerChoice = battleMenu();
        turnOrder = rand() % 2;
        
        switch (playerChoice) {
            case 1:
                if (turnOrder == 0) {
                    printf("%s's turn!\n", companion->name);
                    sleep(1);
                    untamedAttack(player, companion, -1);
                    if (player->hp > 0) {
                        printf("%s's turn!\n", player->name);
                        sleep(1);
                        untamedAttack(player, companion, 1);
                    }
                }
                else if (turnOrder == 1) {
                    printf("%s's turn!\n", player->name);
                    sleep(1);
                    untamedAttack(player, companion, 1);
                    if (companion->hp > 0) {
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        untamedAttack(player, companion, -1);
                    }
                }
                break;
                
            case 2:
                
                printf("You can't use magic on this DIGUSTING CREATURE!\n");
                sleep(1);
                break;
    
            case 3:
                
                useItem = itemsMenu(player, head, tail);
                
                if (useItem == 1) {
                    printf("You TAMED it?\n");
                    sleep(1);
                    printf("Why would you TAME such a DISGUSTING CREATURE???\n");
                    sleep(1);
                    companion->tamed = true;
                    printf("What would you like to name it?\n");
                    scanf("%s", companionName);
                    strcpy(companion->name, companionName);
                    printf("%s joined the PARTY.", companion->name);
                    return 1;
                }
                else if (useItem == 0) {
                    printf("%s's turn!\n", companion->name);
                    sleep(1);
                    untamedAttack(player, companion, -1);
                }
                
                break;
            case 4:
                if (player->speed < companion->speed) {
                    printf("Can't get away!\n");
                    sleep(1);
                }
                else {
                    printf("You ran away!\n");
                    sleep(1);
                    return 0;
                }
            default:
                break;
        }
        
        if (player->hp <= 0) {
            printf("You were defeated by %s!\n", companion->name);
            sleep(2);
            return -1;
        }
        
        else if (companion->hp <= 0) {
            printf("The %s ran way!\n", companion->name);
            sleep(1);
            printf("Why do I feel kind of bad?\n");
            sleep(1);
            
            return 1;
        }
        
    }
    return 0;
}

void untamedAttack(party *player, companion *companion, int turn) {
    
    int roll = (rand() % 10);
    int damage;
    
    if (turn == 1) {
        printf("%s is attacking!\n", player->name);
        usleep(100000);
        if (roll == 0) {
            printf("Oh no you missed!\n");
            sleep(1);
        }
        else {
            damage = untamedAttackDamage(*player, *companion, turn);
            printf("You did %d damage!\n", damage);
            sleep(1);
            companion->hp = companion->hp - damage;
        }
    }
    
    else if (turn == -1) {
        printf("%s is attacking!\n", companion->name);
        usleep(100000);
        if (roll == 0) {
            printf("Hah the %s missed\n", companion->name);
            sleep(1);
        }
        else {
            damage = untamedAttackDamage(*player, *companion, turn);
            printf("The %s did %d damage!\n", companion->name, damage);
            sleep(1);
            player->hp = player->hp - damage;
        }
    }
    
}

int untamedAttackDamage(party player, companion companion, int turn) {
    
    float damage, crit;
    int critRoll = (rand() % 10);
    
    if (turn == 1) {
      
        if (critRoll == 9) {
            crit = 1.5;
            printf("Critical hit! ");
        }
        else {
            crit = 1;
        }
        
        damage = ((2 * (player.level)) + 10) / 5;
        damage *= player.attack;
        damage /=  companion.defense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    else if (turn == -1) {
        
        if (critRoll == 9) {
            crit = 1.5;
            printf("Yikes critical hit! ");
        }
        else {
            crit = 1;
            printf("Ouch! ");
        }
        
        damage = ((2 * (companion.level)) + 10) / 5;
        damage *=  companion.attack;
        damage /= player.defense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    
    return 0;
}

void saveCompanion(party player, companion companion) {
    
    if (companion.tamed) {
        FILE *outp;
        
        char fileName[50];
        
        strcpy(fileName, player.name);
        strcat(fileName, "'s_Companion.txt\0");
        outp = fopen(fileName, "w");
        fprintf(outp, "%s %d %d %d %d %d %d", companion.name, companion.maxHP, companion.attack, companion.speed, companion.maxEXP, companion.exp, companion.level);
        fclose(outp);
        printf("Companion saved!\n");
        usleep(100000);
    }
    
}
