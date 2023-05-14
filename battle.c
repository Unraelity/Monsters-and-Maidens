#include "battle.h"

int battleTime(party *player, monster *monster, item **head, item **tail, int i) {
    
    createMonster(monster, i);
    printBattle(*player, *monster);
    
    int playerChoice, turnOrder = 0, useMagic, useItem;
    
    if (monster->boss) {
        printf("Oh no you encountered %s!\n", monster->name);
        sleep(1);
        
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
                        monsterTurn(player, monster, -1);
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
                            monsterTurn(player, monster, -1);
                        }
                    }
                }
                break;
                
            case 2:
                
                useMagic = magicMenu(player, monster, 1);
                
                if (useMagic != -1) {
                    if (turnOrder == -1) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, -1);
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            heal(player, monster, 1);
        
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, -1);
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
                            monsterTurn(player, monster, -1);
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            fire(player, monster, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, -1);
                            }
                        }
                    }
                }
                
                break;
            case 3:
                
                useItem = itemsMenu(player, head, tail);
                
                if (useItem == 0) {
                    printf("%s's turn!\n", monster->name);
                    sleep(1);
                    monsterTurn(player, monster, -1);
                }
                else if (useItem == 1) {
                    printf("It had no effect!\n");
                    sleep(1);
                    printf("%s's turn!\n", monster->name);
                    sleep(1);
                    monsterTurn(player, monster, -1);
                }
                
                break;
            case 4:
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
        
        if (player->hp <= 0) {
            printf("You were defeated by %s!\n", monster->name);
            sleep(1);
            return -1;
        }
        
        else if ((monster->hp <= 0) && (monster->boss)) {
            
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
                sleep(1);
                player->hp = player->maxHP;
                player->mp = player->maxMP;
                return 1;
            }
        }
        
        else if (monster->hp <= 0) {
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
            printf("Hah the %s missed\n", monster->name);
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

int battleTime2(party *player, monster *monster, companion *companion, item **head, item **tail, int i) {
    
    createMonster(monster, i);
    printBattle2(*player, *monster, *companion);
    
    int playerChoice, turnOrder = 0, useMagic, useItem;
    
    if (monster->boss) {
        printf("Oh no you encountered %s!\n", monster->name);
        sleep(1);
        printDialogue(*monster);
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
                        monsterTurn(player, monster, -1);
                        if (player->hp > 0) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                attack2(player, monster, companion, 1);
                            }
                        }
                    }
                    if (turnOrder == -2) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                        if (player->hp > 0) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            attack2(player, monster, companion, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
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
                            monsterTurn(player, monster, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                            }
                        }
                    }
                    else if (turnOrder == 2) {
                        printf("%s's turn!\n", player->name);
                        sleep(1);
                        attack2(player, monster, companion, 1);
                        if (monster->hp > 0) {
                            if (player->hp > 0) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", monster->name);
                                    sleep(1);
                                    monsterTurn(player, monster, -1);
                                }
                            }
                        }
                    }
                    else if (turnOrder == 12) {
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                        if (monster->hp > 0) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                attack2(player, monster, companion, 1);
                            }
                        }
                    }
                    else if (turnOrder == 11) {
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                        if (monster->hp > 0) {
                            printf("%s's turn!\n", player->name);
                            sleep(1);
                            attack2(player, monster, companion, 1);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, -1);
                            }
                        }
                    }

                }
                break;
                
            case 2:
                
                useMagic = magicMenu(player, monster, 1);
                
                if (useMagic != -1) {
                    if (turnOrder == -3) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", player->name);
                                    sleep(1);
                                    heal(player, monster, 1);
                                }
                            }
                        }
                        
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", companion->name);
                                sleep(1);
                                attack2(player, monster, companion, 10);
                                if (monster->hp > 0) {
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
                            monsterTurn(player, monster, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                heal(player, monster, 1);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", monster->name);
                            sleep(1);
                            monsterTurn(player, monster, -1);
                            if (player->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                fire(player, monster, 1);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
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
                                monsterTurn(player, monster, -1);
                                if (player->hp > 0) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
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
                                monsterTurn(player, monster, -1);
                                if (player->hp > 0) {
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
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
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                    if (monster->hp > 0) {
                                        printf("%s's turn!\n", monster->name);
                                        sleep(1);
                                        monsterTurn(player, monster, -1);
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
                                    printf("%s's turn!\n", companion->name);
                                    sleep(1);
                                    attack2(player, monster, companion, 10);
                                    if (monster->hp > 0) {
                                        printf("%s's turn!\n", monster->name);
                                        sleep(1);
                                        monsterTurn(player, monster, -1);
                                    }
                                }
                            }
                        }
                    }
                    
                    else if (turnOrder == 12) {
                        if (useMagic == 1) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, -1);
                                if (player->hp > 0) {
                                    printf("%s's turn!\n", player->name);
                                    sleep(1);
                                    heal(player, monster, 1);
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", monster->name);
                                sleep(1);
                                monsterTurn(player, monster, -1);
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
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                heal(player, monster, 1);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", monster->name);
                                    sleep(1);
                                    monsterTurn(player, monster, -1);
                                }
                            }
                        }
                        else if (useMagic == 2) {
                            printf("%s's turn!\n", companion->name);
                            sleep(1);
                            attack2(player, monster, companion, 10);
                            if (monster->hp > 0) {
                                printf("%s's turn!\n", player->name);
                                sleep(1);
                                fire(player, monster, 1);
                                if (monster->hp > 0) {
                                    printf("%s's turn!\n", monster->name);
                                    sleep(1);
                                    monsterTurn(player, monster, -1);
                                }
                            }
                        }
                    }
                    
                }
                
                break;
                    
            case 3:
                
                useItem = itemsMenu(player, head, tail);
                
                if (useItem == 0) {
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                    }
                    else {
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                    }
                }
                
                if (useItem == 1) {
                    printf("You threw your BONE!\n");
                    sleep(1);
                    printf("... ");
                    sleep(1);
                    printf("It didn't do anything!\n");
                    
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                    }
                    else {
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                    }
                }
                
                if (useItem == 2) {
                    printf("You swung your FISH!\n");
                    sleep(1);
                    printf("... ");
                    sleep(1);
                    printf("It didn't do anything!\n");
                    
                    if (monster->speed > companion->speed) {
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                    }
                    else {
                        printf("%s's turn!\n", companion->name);
                        sleep(1);
                        attack2(player, monster, companion, 10);
                        printf("%s's turn!\n", monster->name);
                        sleep(1);
                        monsterTurn(player, monster, -1);
                    }
                }
                
                break;
            case 4:
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
        
        if (player->hp <= 0) {
            printf("You were defeated by %s!\n", monster->name);
            sleep(1);
            return -1;
        }
        
        else if ((monster->hp <= 0) && (monster->boss)) {
            
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
                sleep(1);
                player->hp = player->maxHP;
                player->mp = player->maxMP;
                return 1;
            }
        }
        
        else if (monster->hp <= 0) {
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
            printf("Hah the %s missed\n", monster->name);
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
