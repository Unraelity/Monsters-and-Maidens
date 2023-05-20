#include "monster.h"

void createMonster(monster *monster, int event, bool hardMode) {
    
    int randomizeMonster = (rand() % 5);
    
    if (hardMode != true) {
        if (event == 0) {
            strcpy(monster->name, "SLIME");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 12;
            monster->hp = 12;
            monster->magicDefense = 5;
            monster->attack = 5;
            monster->defense = 5;
            monster->speed = 5;
            monster->level = 1;
            monster->goldYield = 1;
            monster->expYield = 7;
        }
        else if (event < 4) {
            if ((randomizeMonster == 0) || (randomizeMonster == 1) || (randomizeMonster == 2)) {
                strcpy(monster->name, "SLIME");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 14;
                monster->hp = 14;
                monster->magicDefense = 6;
                monster->attack = 6;
                monster->defense = 6;
                monster->speed = 6;
                monster->level = 2;
                monster->goldYield = 2;
                monster->expYield = 8;
            }
            else if (randomizeMonster == 3) {
                strcpy(monster->name, "WIZARD");
                monster->magicUser = true;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 13;
                monster->hp = 13;
                monster->maxMP = 13;
                monster->mp = 13;
                monster->magicDefense = 7;
                monster->attack = 5;
                monster->defense = 5;
                monster->speed = 8;
                monster->level = 2;
                monster->magic[0][0] = HEAL;
                monster->magic[0][1] = 9;
                monster->magic[1][0] = FIRE;
                monster->magic[1][1] = 9;
                monster->goldYield = 5;
                monster->expYield = 10;
            }
            else if (randomizeMonster == 4) {
                strcpy(monster->name, "SNAKE");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 12;
                monster->hp = 12;
                monster->magicDefense = 7;
                monster->attack = 9;
                monster->defense = 7;
                monster->speed = 10;
                monster->level = 2;
                monster->goldYield = 3;
                monster->expYield = 9;
            }
        }
        else if (event == 4) {
            strcpy(monster->name, "GIANT");
            monster->magicUser = false;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 20;
            monster->hp = 20;
            monster->magicDefense = 11;
            monster->attack = 12;
            monster->defense = 21;
            monster->speed = 12;
            monster->level = 5;
            monster->goldYield = 10;
            monster->expYield = 100;
        }
        else if ((event > 4) && (event < 9)) {
            if (randomizeMonster == 0) {
                strcpy(monster->name, "SLIME");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 20;
                monster->hp = 20;
                monster->magicDefense = 9;
                monster->attack = 9;
                monster->defense = 9;
                monster->speed = 9;
                monster->level = 5;
                monster->goldYield = 5;
                monster->expYield = 40;
            }
            else if ((randomizeMonster == 1) || (randomizeMonster == 2)) {
                strcpy(monster->name, "CHICKPEE");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 19;
                monster->hp = 19;
                monster->magicDefense = 8;
                monster->attack = 10;
                monster->defense = 8;
                monster->speed = 11;
                monster->level = 5;
                monster->goldYield = 3;
                monster->expYield = 40;
            }
            else if (randomizeMonster == 3) {
                strcpy(monster->name, "WIZARD");
                monster->magicUser = true;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 20;
                monster->hp = 20;
                monster->maxMP = 19;
                monster->mp = 19;
                monster->magicDefense = 12;
                monster->attack = 8;
                monster->defense = 8;
                monster->speed = 15;
                monster->level = 5;
                monster->magic[0][0] = HEAL;
                monster->magic[0][1] = 18;
                monster->magic[1][0] = FIRE;
                monster->magic[1][1] = 17;
                monster->goldYield = 10;
                monster->expYield = 55;
            }
            else if (randomizeMonster == 4) {
                strcpy(monster->name, "SNAKE");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 22;
                monster->hp = 22;
                monster->magicDefense = 11;
                monster->attack = 15;
                monster->defense = 11;
                monster->speed = 15;
                monster->level = 5;
                monster->goldYield = 7;
                monster->expYield = 50;
            }
        }
        else if (event == 9) {
            strcpy(monster->name, "MEGA CHICKEN");
            monster->magicUser = false;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 41;
            monster->hp = 41;
            monster->magicDefense = 17;
            monster->attack = 27;
            monster->defense = 20;
            monster->speed = 29;
            monster->level = 15;
            monster->goldYield = 20;
            monster->expYield = 200;
        }
        else if ((event > 9) && (event < 14)) {
            strcpy(monster->name, "SUPER SLIME");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 48;
            monster->hp = 48;
            monster->magicDefense = 23;
            monster->attack = 23;
            monster->defense = 23;
            monster->speed = 23;
            monster->level = 15;
            monster->goldYield = 12;
            monster->expYield = 30;
        }
        else if (event == 14) {
            strcpy(monster->name, "LORD SLIME");
            monster->magicUser = false;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 115;
            monster->hp = 115;
            monster->magicDefense = 37;
            monster->attack = 37;
            monster->defense = 37;
            monster->speed = 37;
            monster->level = 25;
            monster->goldYield = 30;
            monster->expYield = 300;
        }
        else if ((event > 14) && (event < 19)) {
            if ((randomizeMonster == 0) || (randomizeMonster == 1) || (randomizeMonster == 2)) {
                strcpy(monster->name, "ORC");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 69;
                monster->hp = 69;
                monster->magicDefense = 67;
                monster->attack = 37;
                monster->defense = 67;
                monster->speed = 45;
                monster->level = 25;
                monster->goldYield = 10;
                monster->expYield = 50;
            }
            else {
                strcpy(monster->name, "ARCHER");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = true;
                monster->maxHP = 55;
                monster->hp = 55;
                monster->magicDefense = 37;
                monster->attack = 67;
                monster->defense = 37;
                monster->speed = 62;
                monster->level = 25;
                monster->goldYield = 10;
                monster->expYield = 50;
            }
        }
        else if (event == 19) {
            strcpy(monster->name, "KING PORK");
            monster->magicUser = true;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 130;
            monster->hp = 130;
            monster->maxMP = 119;
            monster->mp = 119;
            monster->magicDefense = 68;
            monster->attack = 82;
            monster->defense = 68;
            monster->speed = 96;
            monster->magic[0][0] = HEAL;
            monster->magic[0][1] = 123;
            monster->magic[1][0] = FIRE;
            monster->magic[1][1] = 112;
            monster->level = 35;
            monster->goldYield = 0;
            monster->expYield = 0;
        }
    }
    else {
        if (event < 4) {
            if ((randomizeMonster == 0) || (randomizeMonster == 1) || (randomizeMonster == 2)) {
                strcpy(monster->name, "SLIME");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 100;
                monster->hp = 100;
                monster->magicDefense = 54;
                monster->attack = 54;
                monster->defense = 54;
                monster->speed = 54;
                monster->level = 35;
                monster->goldYield = 10;
                monster->expYield = 50;
            }
            else if (randomizeMonster == 3) {
                strcpy(monster->name, "WIZARD");
                monster->magicUser = true;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 94;
                monster->hp = 94;
                monster->maxMP = 83;
                monster->mp = 83;
                monster->magicDefense = 71;
                monster->attack = 40;
                monster->defense = 36;
                monster->speed = 89;
                monster->magic[0][0] = HEAL;
                monster->magic[0][1] = 110;
                monster->magic[1][0] = FIRE;
                monster->magic[1][1] = 99;
                monster->level = 35;
                monster->goldYield = 25;
                monster->expYield = 60;
            }
            else if (randomizeMonster == 4) {
                strcpy(monster->name, "SNAKE");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 96;
                monster->hp = 96;
                monster->magicDefense = 60;
                monster->attack = 71;
                monster->defense = 53;
                monster->speed = 75;
                monster->level = 35;
                monster->goldYield = 15;
                monster->expYield = 55;
            }
        }
        else if (event == 4) {
            strcpy(monster->name, "GIANT");
            monster->magicUser = false;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 122;
            monster->hp = 122;
            monster->magicDefense = 63;
            monster->attack = 95;
            monster->defense = 185;
            monster->speed = 32;
            monster->level = 45;
            monster->goldYield = 50;
            monster->expYield = 500;
        }
        else if ((event > 4) && (event < 9)) {
            if (randomizeMonster == 0) {
                strcpy(monster->name, "SLIME");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 126;
                monster->hp = 126;
                monster->magicDefense = 68;
                monster->attack = 68;
                monster->defense = 68;
                monster->speed = 68;
                monster->level = 45;
                monster->goldYield = 25;
                monster->expYield = 200;
            }
            else if ((randomizeMonster == 1) || (randomizeMonster == 2)) {
                strcpy(monster->name, "CHICKPEE");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 104;
                monster->hp = 104;
                monster->magicDefense = 41;
                monster->attack = 72;
                monster->defense = 50;
                monster->speed = 77;
                monster->level = 45;
                monster->goldYield = 15;
                monster->expYield = 200;
            }
            else if (randomizeMonster == 3) {
                strcpy(monster->name, "WIZARD");
                monster->magicUser = true;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 118;
                monster->hp = 118;
                monster->maxMP = 104;
                monster->mp = 104;
                monster->magicDefense = 90;
                monster->attack = 50;
                monster->defense = 45;
                monster->speed = 113;
                monster->magic[0][0] = HEAL;
                monster->magic[0][1] = 140;
                monster->magic[1][0] = FIRE;
                monster->magic[1][1] = 126;
                monster->level = 45;
                monster->goldYield = 50;
                monster->expYield = 275;
            }
            else if (randomizeMonster == 4) {
                strcpy(monster->name, "SNAKE");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 109;
                monster->hp = 109;
                monster->magicDefense = 76;
                monster->attack = 90;
                monster->defense = 67;
                monster->speed = 95;
                monster->level = 45;
                monster->goldYield = 35;
                monster->expYield = 250;
            }
        }
        else if (event == 9) {
            strcpy(monster->name, "MEGA CHICKEN");
            monster->magicUser = false;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 158;
            monster->hp = 158;
            monster->magicDefense = 71;
            monster->attack = 137;
            monster->defense = 82;
            monster->speed = 132;
            monster->level = 55;
            monster->goldYield = 100;
            monster->expYield = 1000;
        }
        else if ((event > 9) && (event < 14)) {
            strcpy(monster->name, "SUPER SLIME");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 241;
            monster->hp = 241;
            monster->magicDefense = 126;
            monster->attack = 126;
            monster->defense = 126;
            monster->speed = 126;
            monster->level = 55;
            monster->goldYield = 60;
            monster->expYield = 150;
        }
        else if (event == 14) {
            strcpy(monster->name, "LORD SLIME");
            monster->magicUser = false;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 290;
            monster->hp = 290;
            monster->magicDefense = 213;
            monster->attack = 213;
            monster->defense = 213;
            monster->speed = 213;
            monster->level = 65;
            monster->goldYield = 150;
            monster->expYield = 1500;
        }
        else if ((event > 14) && (event < 19)) {
            if ((randomizeMonster == 0) || (randomizeMonster == 1) || (randomizeMonster == 2)) {
                strcpy(monster->name, "ORC");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = false;
                monster->maxHP = 193;
                monster->hp = 193;
                monster->magicDefense = 179;
                monster->attack = 128;
                monster->defense = 179;
                monster->speed = 109;
                monster->level = 65;
                monster->goldYield = 50;
                monster->expYield = 250;
            }
            else {
                strcpy(monster->name, "ARCHER");
                monster->magicUser = false;
                monster->boss = false;
                monster->longDistance = true;
                monster->maxHP = 193;
                monster->hp = 193;
                monster->magicDefense = 128;
                monster->attack = 179;
                monster->defense = 128;
                monster->speed = 129;
                monster->level = 65;
                monster->goldYield = 50;
                monster->expYield = 250;
            }
        }
        else if (event == 19) {
            strcpy(monster->name, "KING PORK");
            monster->magicUser = true;
            monster->boss = true;
            monster->longDistance = false;
            monster->maxHP = 267;
            monster->hp = 267;
            monster->maxMP = 244;
            monster->mp = 244;
            monster->magicDefense = 140;
            monster->attack = 170;
            monster->defense = 140;
            monster->speed = 200;
            monster->level = 75;
            monster->magic[0][0] = HEAL;
            monster->magic[0][1] = 259;
            monster->magic[1][0] = FIRE;
            monster->magic[1][1] = 236;
            monster->goldYield = 0;
            monster->expYield = 0;
        }
    }
}
   
void monsterTurn(party *player, monster *monster, companion *companion, int turn) {
    
    if (strcmp(monster->name, "SLIME") == 0) {
        attack(player, monster, turn);
    }
    
    else if (strcmp(monster->name, "WIZARD") == 0) {
        wizard(player, monster, turn);
    }
    
    else if (strcmp(monster->name, "SNAKE") == 0) {
        strike(player, monster, turn);
    }
    
    else if (strcmp(monster->name, "CHICKPEE") == 0) {
        attack(player, monster, turn);
    }
    
    else if (strcmp(monster->name, "GIANT") == 0) {
        attack(player, monster, turn);
    }
    else if (strcmp(monster->name, "MEGA CHICKEN") == 0) {
        attack(player, monster, turn);
    }
    else if (strcmp(monster->name, "SUPER SLIME") == 0) {
        attack(player, monster, turn);
    }
    else if (strcmp(monster->name, "LORD SLIME") == 0) {
        attack(player, monster, turn);
    }
    else if (strcmp(monster->name, "ORC") == 0) {
        attack(player, monster, turn);
    }
    else if (strcmp(monster->name, "ARCHER") == 0) {
        attack(player, monster, turn);
    }
    else if (strcmp(monster->name, "KING PORK") == 0) {
        kingPork(player, monster, companion, turn);
    }
}

void strike(party *player, monster *monster, int turn) {
    
    int roll = (rand() % 10), poisonRoll = (rand() % 2), damage;
    
    printf("%s is striking!\n", monster->name);
    usleep(100000);
    if (roll == 0) {
        printf("Hah too slow!\n");
        sleep(1);
    }
    else {
        damage = attackDamage(*player, *monster, turn);
        printf("The %s did %d damage!\n", monster->name, damage);
        sleep(1);
        player->hp = player->hp - damage;
    }
    if ((poisonRoll == 1) && (strcmp(player->statusCondition, "NONE") == 0)) {
        printf("%s was POISONED!\n", player->name);
        strcpy(player->statusCondition, "POISON");
        sleep(2);
    }
    
}

void wizard(party *player, monster *monster, int turn) {
    
    int roll = (rand() % 10);
    
    if ((monster->hp <= (monster->maxHP / 2)) && (monster->mp >= 3)) {
        heal(player, monster, turn);
    }
    else if ((roll >= 1) && (monster->mp >= 5)) {
        fire(player, monster, turn);
    }
    else {
        attack(player, monster, turn);
    }
    
}

void bossIntimidation(party player, monster monster, stat statChanges[2]) {
    
    if (strcmp(monster.name, "GIANT") == 0) {
        printf("THE GIANT ROARED AT YOU!\n");
        sleep(2);
        printf("%s's ATTACK FELL!\n", player.name);
        statChanges[PLAYER_STATS].attackChange /= 1.5;
        sleep(2);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        printf("THE MEGA CHICKEN DROPPED FEATHERS ON THE FIELD!\n");
        sleep(2);
        printf("%s's SPEED FELL A LOT!\n", player.name);
        statChanges[PLAYER_STATS].speedChange /= 1.5;
        statChanges[PLAYER_STATS].speedChange /= 1.5;
        sleep(2);
    }
    else if (strcmp(monster.name, "LORD SLIME") == 0) {
        printf("LORD SLIME USED HIS MAGICAL POWER!\n");
        sleep(2);
        printf("ALL %s's MAGIC ABILITIES FELL!\n", player.name);
        statChanges[PLAYER_STATS].magicChange /= 1.5;
        statChanges[PLAYER_STATS].magicDefenseChange /= 1.5;
        sleep(2);
    }
    else if (strcmp(monster.name, "KING PORK") == 0) {
        printf("KING PORK SUMMONED HIS INNER STRENGTH!\n");
        sleep(2);
        printf("ALL %s's STATS FELL!\n", player.name);
        statChanges[PLAYER_STATS].attackChange /= 1.5;
        statChanges[PLAYER_STATS].defenseChange /= 1.5;
        statChanges[PLAYER_STATS].speedChange /= 1.5;
        statChanges[PLAYER_STATS].magicChange /= 1.5;
        statChanges[PLAYER_STATS].magicDefenseChange /= 1.5;
        sleep(2);
    }
}

void kingPork(party *player, monster *monster, companion *companion, int turn) {
    
    int roll = (rand() % 10);
    
    if ((monster->hp <= (monster->maxHP / 4)) && (monster->mp >= 3)) {
        heal(player, monster, turn);
    }
    else if ((roll == 9) && (companion->tamed)) {
        printf("KING PORK used a SPELL that turned %s against YOU!\n", companion->name);
        sleep(3);
        companion->tamed = false;
    }
    else if ((roll >= 1) && (monster->mp >= 5)) {
        fire(player, monster, turn);
    }
    else {
        attack(player, monster, turn);
    }
}

void kingPorkFinalStand(party player, monster *monster, stat statChanges[2], int *turnAtHalfHP, int *turnAtQuarterHP) {
    
    if (*turnAtHalfHP == 0) {
        printf("KING PORK: YOU have done well to make it THIS FAR, HERO...\n");
        sleep(2);
        printf("KING PORK: But it is time to END THIS!\n");
        sleep(2);
        printf("KING PORK's OFFENSIVE STATS AND SPEED INCREASED!\n");
        statChanges[PLAYER_STATS].attackChange *= 1.5;
        statChanges[PLAYER_STATS].speedChange *= 1.5;
        statChanges[PLAYER_STATS].magicChange *= 1.5;
        (*turnAtHalfHP)++;
        sleep(2);
        
        printf("D: AGREED!\n");
        sleep(2);
        printf("KING PORK's DEFENSIVE STATS DECREASED!\n");
        statChanges[PLAYER_STATS].defenseChange /= 1.5;
        statChanges[PLAYER_STATS].magicDefenseChange /= 1.5;
        sleep(2);
    }
    
    if ((monster->hp <= (monster->maxHP / 4)) && (*turnAtQuarterHP == 0)) {
        printf("D: It's TIME TO END THIS %s!\n", player.name);
        sleep(2);
        (*turnAtQuarterHP)++;
    }
}
