#include "battle.h"

int battleTime(party *player, monster *monster, item **head, item **tail, int i, bool hardMode) {
    
    companion companion;
    companion.tamed = false;
    int turnsAtHalfHP = 0, turnAtQuarterHP = 0;
    stat statBoosts[2];
    
    setStatBoosts(statBoosts);
    createMonster(monster, i, hardMode);
    saveRealStats(statBoosts, *player, *monster);
    printBattle(*player, *monster);
    
    int playerChoice, turnOrder = 0, useMagic = 0, useItem = 0;
    
    if (monster->boss) {
        printf("Oh no you encountered %s!\n", monster->name);
        sleep(1);
        printDialogue(*monster);
        bossIntimidation(*player, *monster, statBoosts);
        implementStatChanges(statBoosts, player, monster);
        
    }
    else {
        printf("Oh no you encountered a %s!\n", monster->name);
        sleep(1);
    }
    
    while ((player->hp > 0) && (monster->hp > 0)) {
        
        useMagic = 0;
        useItem = 0;
        
        printPlayerStats(*player, *monster);
        
        playerChoice = battleMenu();
        turnOrder = determineTurn(*player, *monster);
        
        switch (playerChoice) {
            case 1:
                if (monster->longDistance) {
                    printf("%s is too far for a basic attack!\n", monster->name);
                    sleep(1);
                }
                else {
                    if (turnOrder == -1) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, &companion, -1);
                        if (player->hp > 0) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            attack(player, monster, 1);
                        }
                    }
                    else if (turnOrder == 1) {
                        printf("%s's turn!\n", player->name);
                        sleep(1);
                        attack(player, monster, 1);
                        if (monster->hp > 0) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, &companion, -1);
                        }
                    }
                }
                break;
                
            case 2:
                
                useMagic = magicMenu(player, monster);
                
                if ((useMagic != 0) && (useMagic != -1)) {
                    if (turnOrder == -1) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, &companion, -1);
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            heal(player, monster, 1);
        
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, &companion, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                fire(player, monster, 1);
                            }
                        }
                    }
                    else if (turnOrder == 1) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            heal(player, monster, 1);
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, &companion, -1);
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            fire(player, monster, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, &companion, -1);
                            }
                        }
                    }
                }
                
                break;
            case 3:
                
                useItem = itemsMenu(player, head, tail, &statBoosts[PLAYER_STATS]);
                
                if (useItem == 0) {
                    printf("%s's turn!\n", monster->name);
                    sleep(1);
                    monsterTurn(player, monster, &companion, -1);
                }
                if (useItem == 1) {
                    printf("You threw your BONE!\n");
                    sleep(1);
                    printf("... ");
                    sleep(1);
                    printf("It didn't do anything!\n");
                    sleep(1);
                    printf("%s's turn!\n", monster->name);
                    sleep(1);
                    monsterTurn(player, monster, &companion, -1);
                }
                
                else if (useItem == 2) {
                    printf("You swung your FISH!\n");
                    sleep(1);
                    printf("... ");
                    sleep(1);
                    printf("It didn't do anything!\n");
                    sleep(1);
                    printf("%s's turn!\n", monster->name);
                    sleep(1);
                    monsterTurn(player, monster, &companion, -1);
                }
                else if (useItem == 3) {
                    implementStatChanges(statBoosts, player, monster);
                    printf("%s's turn!\n", monster->name);
                    sleep(1);
                    monsterTurn(player, monster, &companion, -1);
                }
                
                break;
            case 4:
                printBattleStats(*player, *monster, companion);
                break;
            case 5:
                if (monster->boss) {
                    printf("You can't runaway from a BOSS! Wierdo...\n");
                    sleep(1);
                }
                else if (player->speed < monster->speed) {
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
        
        if ((useMagic != -1) && (useItem != -1)) {
            checkStatusConditions(player, monster);
        }
        useMagic= 0;
        useItem = 0;
        
        if ((player->hp > 0) && (monster->hp > 0)) {
            if ((strcmp(monster->name, "KING PORK") == 0) && (monster->hp <= (monster->maxHP /2))) {
                kingPorkFinalStand(*player, monster, statBoosts, &turnsAtHalfHP, &turnAtQuarterHP);
                implementStatChanges(statBoosts, player, monster);
            }
        }
        
        if (player->hp <= 0) {
            printf("You were defeated by %s!\n", monster->name);
            sleep(1);
            return -1;
        }
        
        else if ((monster->hp <= 0) && (monster->boss)) {
            
            resetStats(statBoosts, player);
            
            if (strcmp(monster->name, "KING PORK") == 0){
                printf("YOU BEAT the FINAL BOSS! I knew you could DO IT!\n");
                sleep(2);
                return 1;
            }
            else {
                printf("I CAN'T BELIEVE IT!!! You defeated %s!\n", monster->name);
                sleep(2);
                gainEXP(player, *monster);
                gainGold(player, *monster);
                treasure(player, head, tail);
                printHouse();
                printf("%s's HP and MP was restored.\n", player->name);
                strcpy(player->statusCondition, "NONE");
                sleep(1);
                player->hp = player->maxHP;
                player->mp = player->maxMP;
                return 1;
            }
        }
        
        else if (monster->hp <= 0) {
            
            resetStats(statBoosts, player);
            
            printf("%s was defeated.\n", monster->name);
            sleep(1);
            printf("Easy peasy!\n");
            sleep(1);
            gainEXP(player, *monster);
            gainGold(player, *monster);
            return 1;
        }
        
    }
    return 0;
}

int determineTurn(party player, monster monster) {
    
    int turnOrder = rand() % 2;
    
    if (player.speed > monster.speed) {
        return 1;
    }
    else if (player.speed < monster.speed) {
        return -1;
    }
    else if (turnOrder == 1) {
        return -1;
    }
    else {
        return 1;
    }
    
}

void attack(party *player, monster *monster, int turn) {

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
            damage = attackDamage(*player, *monster, turn);
            printf("You did %d damage!\n", damage);
            sleep(1);
            monster->hp = monster->hp - damage;
        }
    }
    
    else if (turn == -1) {
        printf("%s is attacking!\n", monster->name);
        usleep(100000);
        if (roll == 0) {
            printf("Hah the %s missed!\n", monster->name);
            sleep(1);
        }
        else {
            damage = attackDamage(*player, *monster, turn);
            printf("The %s did %d damage!\n", monster->name, damage);
            sleep(1);
            player->hp = player->hp - damage;
        }
    }
    
}

int attackDamage(party player, monster monster, int turn) {
    
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
        damage /=  monster.defense;
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
        
        damage = ((2 * (monster.level)) + 10) / 5;
        damage *= monster.attack;
        damage /= player.defense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    
    return 0;
}

int battleTime2(party *player, monster *monster, companion *companion, item **head, item **tail, int i, bool hardMode) {
    
    int turnsAtHalfHP = 0, turnsAtQuarterHP = 0, turnsUntamed = 0;
    stat statBoosts[2];
    
    setStatBoosts(statBoosts);
    createMonster(monster, i, hardMode);
    saveRealStats(statBoosts, *player, *monster);
    printBattle2(*player, *monster, *companion);
    
    int playerChoice, turnOrder = 0, useMagic = 0, useItem = 0;
    
    if (monster->boss) {
        printf("Oh no you encountered %s!\n", monster->name);
        sleep(1);
        printDialogue(*monster);
        bossIntimidation(*player, *monster, statBoosts);
        implementStatChanges(statBoosts, player, monster);
    }
    else {
        printf("Oh no you encountered a %s!\n", monster->name);
        sleep(1);
    }
    
    while ((player->hp > 0) && (monster->hp > 0)) {
        
        useMagic = 0;
        useItem = 0;
        
        printPlayerStats(*player, *monster);
        
        playerChoice = battleMenu();
        turnOrder = determineTurn2(*player, *monster, *companion);
        
        switch (playerChoice) {
            case 1:
                if (monster->longDistance) {
                    printf("%s is too far for a basic attack!\n", monster->name);
                    sleep(1);
                }
                else {
                    if (turnOrder == -3) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, companion, -1);
                        if (player->hp > 0) {
                            if (companion->tamed) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                            else {
                                confusedCompanion(player, companion, &turnsUntamed);
                            }
                            if ((player->hp > 0) && (monster->hp > 0)) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                attack2(player, monster, companion, 1);
                            }
                        }
                    }
                    if (turnOrder == -2) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, companion, -1);
                        if (player->hp > 0) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            attack2(player, monster, companion, 1);
                            if (monster->hp > 0) {
                                if (companion->tamed) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                }
                                else {
                                    confusedCompanion(player, companion, &turnsUntamed);
                                }
                            }
                        }
                    }
                    else if (turnOrder == 3) {
                        printf("%s's turn!\n", player->name);
                        sleep(1);
                        attack2(player, monster, companion, 1);
                        if (monster->hp > 0) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                            if (player->hp > 0) {
                                if (companion->tamed) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                }
                                else {
                                    confusedCompanion(player, companion, &turnsUntamed);
                                }
                            }
                        }
                    }
                    else if (turnOrder == 2) {
                        printf("%s's turn!\n", player->name);
                        sleep(1);
                        attack2(player, monster, companion, 1);
                        if (monster->hp > 0) {
                            if (player->hp > 0) {
                                if (companion->tamed) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                }
                                else {
                                    confusedCompanion(player, companion, &turnsUntamed);
                                }
                                if ((player->hp > 0) && (monster->hp > 0)) {
                                    printf("%s's turn!\n", monster->name);
                                    sleep(1);
                                    monsterTurn(player, monster, companion, -1);
                                }
                            }
                        }
                    }
                    else if (turnOrder == 12) {
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                        if ((player->hp > 0) && (monster->hp > 0)) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                attack2(player, monster, companion, 1);
                            }
                        }
                    }
                    else if (turnOrder == 11) {
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                        if ((player->hp > 0) && (monster->hp > 0)) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            attack2(player, monster, companion, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, companion, -1);
                            }
                        }
                    }

                }
                break;
                
            case 2:
                
                useMagic = magicMenu(player, monster);
                
                if ((useMagic != 0) && (useMagic != -1)) {
                    if (turnOrder == -3) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                            if (player->hp > 0) {
                                if (companion->tamed) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                }
                                else {
                                    confusedCompanion(player, companion, &turnsUntamed);
                                }
                                if ((player->hp > 0) && (monster->hp > 0)) {
                                    printf("%s's turn!\n", player->name);
                                    sleep(1);
                                    heal(player, monster, 1);
                                }
                            }
                        }
                        
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                            if (player->hp > 0) {
                                if (companion->tamed) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                }
                                else {
                                    confusedCompanion(player, companion, &turnsUntamed);
                                }
                                if ((player->hp > 0) && (monster->hp > 0)) {
                                    printf("%s's turn!\n", player->name);
                                    sleep(1);
                                    fire(player, monster, 1);
                                }
                            }
                        }
                    }
                    
                    else if (turnOrder == -2) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                heal(player, monster, 1);
                                if (monster->hp > 0) {
                                    if (companion->tamed) {
                                        printf("%s's turn!\n", companion->name);
                                        sleep(1);
                                        attack2(player, monster, companion, 10);
                                    }
                                    else {
                                        confusedCompanion(player, companion, &turnsUntamed);
                                    }
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                fire(player, monster, 1);
                                if (monster->hp > 0) {
                                    if (companion->tamed) {
                                        printf("%s's turn!\n", companion->name);
                                        sleep(1);
                                        attack2(player, monster, companion, 10);
                                    }
                                    else {
                                        confusedCompanion(player, companion, &turnsUntamed);
                                    }
                                    attack2(player, monster, companion, 10);
                                }
                            }
                        }
                    }
                        
                    else if (turnOrder == 3) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            heal(player, monster, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, companion, -1);
                                if (player->hp > 0) {
                                    if (companion->tamed) {
                                        printf("%s's turn!\n", companion->name);
                                        sleep(1);
                                        attack2(player, monster, companion, 10);
                                    }
                                    else {
                                        confusedCompanion(player, companion, &turnsUntamed);
                                    }
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            fire(player, monster, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, companion, -1);
                                if (player->hp > 0) {
                                    if (companion->tamed) {
                                        printf("%s's turn!\n", companion->name);
                                        sleep(1);
                                        attack2(player, monster, companion, 10);
                                    }
                                    else {
                                        confusedCompanion(player, companion, &turnsUntamed);
                                    }
                                }
                            }
                        }
                    }
                    
                    else if (turnOrder == 2) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            heal(player, monster, 1);
                            if (monster->hp > 0) {
                                if (player->hp > 0) {
                                    if (companion->tamed) {
                                        printf("%s's turn!\n", companion->name);
                                        sleep(1);
                                        attack2(player, monster, companion, 10);
                                    }
                                    else {
                                        confusedCompanion(player, companion, &turnsUntamed);
                                    }
                                    if ((player->hp > 0) && (monster->hp > 0)) {
                                        printf("%s's turn!\n", monster->name);
                                        sleep(1);
                                        monsterTurn(player, monster, companion, -1);
                                    }
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            fire(player, monster, 1);
                            if (monster->hp > 0) {
                                if (player->hp > 0) {
                                    if (companion->tamed) {
                                        printf("%s's turn!\n", companion->name);
                                        sleep(1);
                                        attack2(player, monster, companion, 10);
                                    }
                                    else {
                                        confusedCompanion(player, companion, &turnsUntamed);
                                    }
                                    if ((player->hp > 0) && (monster->hp > 0)) {
                                        printf("%s's turn!\n", monster->name);
                                        sleep(1);
                                        monsterTurn(player, monster, companion, -1);
                                    }
                                }
                            }
                        }
                    }
                    
                    else if (turnOrder == 12) {
                        if (useMagic == 1) {
                            if (companion->tamed) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                            else {
                                confusedCompanion(player, companion, &turnsUntamed);
                            }
                            if ((player->hp > 0) && (monster->hp > 0)) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, companion, -1);
                                if (player->hp > 0) {
                                    printf("%s's turn!\n", player->name);
                                    sleep(1);
                                    heal(player, monster, 1);
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            if (companion->tamed) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                            else {
                                confusedCompanion(player, companion, &turnsUntamed);
                            }
                            if ((player->hp > 0) && (monster->hp > 0)) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, companion, -1);
                                if (player->hp > 0) {
                                    printf("%s's turn!\n", player->name);
                                    sleep(1);
                                    fire(player, monster, 1);
                                }
                            }
                        }
                    }
                    
                    else if (turnOrder == 11) {
                        if (useMagic == 1) {
                            if (companion->tamed) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                            else {
                                confusedCompanion(player, companion, &turnsUntamed);
                            }
                            if ((player->hp > 0) && (monster->hp > 0)) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                heal(player, monster, 1);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", monster->name);
                                    sleep(1);
                                    monsterTurn(player, monster, companion, -1);
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            if (companion->tamed) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                            else {
                                confusedCompanion(player, companion, &turnsUntamed);
                            }
                            if ((player->hp > 0) && (monster->hp > 0)) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                fire(player, monster, 1);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", monster->name);
                                    sleep(1);
                                    monsterTurn(player, monster, companion, -1);
                                }
                            }
                        }
                    }
                    
                }
                
                break;
                    
            case 3:
                
                useItem = itemsMenu(player, head, tail, &statBoosts[PLAYER_STATS]);
                
                if (useItem == 0) {
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, companion, -1);
                        if (player->hp > 0) {
                            if (companion->tamed) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                            else {
                                confusedCompanion(player, companion, &turnsUntamed);
                            }
                        }
                    }
                    else {
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                        if ((player->hp > 0) && (monster->hp > 0)) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                        }
                    }
                }
                
                else if (useItem == 1) {
                    printf("You threw your BONE!\n");
                    sleep(1);
                    printf("... ");
                    sleep(1);
                    printf("It didn't do anything!\n");
                    sleep(1);
                    
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, companion, -1);
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                    }
                    else {
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                        if ((player->hp > 0) && (monster->hp > 0)) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                        }
                    }
                }
                
                else if (useItem == 2) {
                    printf("You swung your FISH!\n");
                    sleep(1);
                    printf("... ");
                    sleep(1);
                    printf("It didn't do anything!\n");
                    sleep(1);
                    
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, companion, -1);
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                    }
                    else {
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                        if ((player->hp > 0) && (monster->hp > 0)) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                        }
                    }
                }
                else if (useItem == 3) {
                    implementStatChanges(statBoosts, player, monster);
                    
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, companion, -1);
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                    }
                    else {
                        if (companion->tamed) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                        }
                        else {
                            confusedCompanion(player, companion, &turnsUntamed);
                        }
                        if ((player->hp > 0) && (monster->hp > 0)) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, companion, -1);
                        }
                    }
                }
                
                break;
            case 4:
                printBattleStats(*player, *monster, *companion);
                break;
            case 5:
                if (monster->boss) {
                    printf("You can't runaway from a BOSS! Wierdo...\n");
                    sleep(1);
                }
                else if (player->speed < monster->speed) {
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
        
        if ((useMagic != -1) && (useItem != -1)) {
            checkStatusConditions(player, monster);
        }
        useMagic= 0;
        useItem = 0;
        
        if ((player->hp > 0) && (monster->hp > 0)) {
            if ((strcmp(monster->name, "KING PORK") == 0) && (monster->hp <= (monster->maxHP /2))) {
                kingPorkFinalStand(*player, monster, statBoosts, &turnsAtHalfHP, &turnsAtQuarterHP);
                implementStatChanges(statBoosts, player, monster);
            }
        }
        
        if (player->hp <= 0) {
            printf("You were defeated by %s!\n", monster->name);
            sleep(1);
            return -1;
        }
        
        else if ((monster->hp <= 0) && (monster->boss)) {
            
            resetStats(statBoosts, player);
            
            if (strcmp(monster->name, "KING PORK") == 0){
                printf("YOU BEAT the FINAL BOSS! I knew you could DO IT!\n");
                sleep(2);
                return 1;
            }
            else {
                printf("I CAN'T BELIEVE IT!!! You defeated %s!\n", monster->name);
                sleep(2);
                gainEXP(player, *monster);
                companionEXP(companion, *monster);
                gainGold(player, *monster);
                treasure(player, head, tail);
                printHouse();
                printf("%s's HP and MP was restored.\n", player->name);
                strcpy(player->statusCondition, "NONE");
                sleep(1);
                player->hp = player->maxHP;
                player->mp = player->maxMP;
                return 1;
            }
        }
        
        else if (monster->hp <= 0) {
            
            resetStats(statBoosts, player);
            
            printf("%s was defeated.\n", monster->name);
            sleep(1);
            printf("Easy peasy!\n");
            sleep(1);
            gainEXP(player, *monster);
            companionEXP(companion, *monster);
            gainGold(player, *monster);
            return 1;
        }
        
    }
    return 0;
}

int determineTurn2(party player, monster monster, companion companion) {
    
    int turnOrder = rand() % 2;
    
    if ((companion.speed < monster.speed) && (player.speed > monster.speed)) {
        return 3;
    }
    else if ((companion.speed > monster.speed) && (player.speed > companion.speed)) {
        return 2;
    }
    else if ((companion.speed > player.speed) && (companion.speed < monster.speed)) {
        return -3;
    }
    else if ((companion.speed < player.speed) && (player.speed < monster.speed)) {
        return -2;
    }
    else if ((companion.speed > monster.speed) && (player.speed < monster.speed)) {
        return 12;
    }
    else if ((companion.speed > player.speed) && (monster.speed < player.speed)) {
        return 11;
    }
    else if (turnOrder == 1) {
        return -2;
    }
    else {
        return 2;
    }
    
}

void attack2(party *player, monster *monster, companion *companion, int turn) {

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
            damage = attackDamage2(*player, *monster, *companion, turn);
            printf("You did %d damage!\n", damage);
            sleep(1);
            monster->hp = monster->hp - damage;
        }
    }
    
    else if (turn == -1) {
        printf("%s is attacking!\n", monster->name);
        usleep(100000);
        if (roll == 0) {
            printf("Hah the %s missed!\n", monster->name);
            sleep(1);
        }
        else {
            damage = attackDamage2(*player, *monster, *companion, turn);
            printf("The %s did %d damage!\n", monster->name, damage);
            sleep(1);
            player->hp = player->hp - damage;
        }
    }
    else if (turn == 10) {
        printf("%s is attacking!\n", companion->name);
        usleep(100000);
        if (roll == 0) {
            printf("It missed. Guess it needs better training...\n");
            sleep(1);
        }
        else {
            damage = attackDamage2(*player, *monster, *companion, turn);
            printf("It did %d damage!\n", damage);
            sleep(1);
            monster->hp = monster->hp - damage;
        }
    }
}

int attackDamage2(party player, monster monster, companion companion, int turn) {
    
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
        damage /=  monster.defense;
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
        
        damage = ((2 * (monster.level)) + 10) / 5;
        damage *= monster.attack;
        damage /= player.defense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    else if (turn == 10) {
        
        if (critRoll == 9) {
            crit = 1.5;
            printf("CRITICAL HIT! Good Dog. ");
        }
        else {
            crit = 1;
        }
        
        damage = ((2 * (companion.level)) + 10) / 5;
        damage *= companion.attack;
        damage /=  monster.defense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    
    
    return 0;
}
