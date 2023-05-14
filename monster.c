#include "monster.h"

void createMonster(monster *monster, int event) {
    
    int randomizeMonster = (rand() % 5);
    
    if (event == 0) {
        strcpy(monster->name, "SLIME");
        monster->magicUser = false;
        monster->boss = false;
        monster->longDistance = false;
        monster->maxHP = 5;
        monster->hp = 5;
        monster->magicDefense = 3;
        monster->attack = 3;
        monster->defense = 3;
        monster->speed = 3;
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
            monster->maxHP = 12;
            monster->hp = 12;
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
            monster->maxHP = 16;
            monster->hp = 16;
            monster->maxMP = 13;
            monster->mp = 13;
            monster->magicDefense = 7;
            monster->attack = 4;
            monster->defense = 4;
            monster->speed = 6;
            monster->level = 2;
            monster->magic[0][0] = HEAL;
            monster->magic[0][1] = 14;
            monster->magic[1][0] = FIRE;
            monster->magic[1][1] = 8;
            monster->goldYield = 5;
            monster->expYield = 10;
        }
        else if (randomizeMonster == 4) {
            strcpy(monster->name, "SNAKE");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 14;
            monster->hp = 14;
            monster->magicDefense = 3;
            monster->attack = 7;
            monster->defense = 5;
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
        monster->maxHP = 25;
        monster->hp = 25;
        monster->magicDefense = 7;
        monster->attack = 9;
        monster->defense = 12;
        monster->speed = 8;
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
            monster->maxHP = 8;
            monster->hp = 8;
            monster->magicDefense = 8;
            monster->attack = 8;
            monster->defense = 8;
            monster->speed = 8;
            monster->level = 5;
            monster->goldYield = 5;
            monster->expYield = 40;
        }
        else if ((randomizeMonster == 1) || (randomizeMonster == 2)) {
            strcpy(monster->name, "CHICKPEE");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 6;
            monster->hp = 6;
            monster->magicDefense = 2;
            monster->attack = 8;
            monster->defense = 4;
            monster->speed = 20;
            monster->level = 5;
            monster->goldYield = 3;
            monster->expYield = 40;
        }
        else if (randomizeMonster == 3) {
            strcpy(monster->name, "WIZARD");
            monster->magicUser = true;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 15;
            monster->hp = 15;
            monster->maxMP = 21;
            monster->mp = 21;
            monster->magicDefense = 15;
            monster->attack = 5;
            monster->defense = 5;
            monster->speed = 12;
            monster->level = 5;
            monster->magic[0][0] = HEAL;
//            monster->magic[0][1] = 22;
            monster->magic[1][0] = FIRE;
            monster->magic[1][1] = 16;
            monster->goldYield = 10;
            monster->expYield = 55;
        }
        else if (randomizeMonster == 4) {
            strcpy(monster->name, "SNAKE");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 13;
            monster->magicDefense = 7;
            monster->hp = 13;
            monster->attack = 10;
            monster->defense = 8;
            monster->speed = 18;
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
        monster->maxHP = 35;
        monster->hp = 35;
        monster->magicDefense = 15;
        monster->attack = 15;
        monster->defense = 18;
        monster->speed = 25;
        monster->level = 10;
        monster->goldYield = 20;
        monster->expYield = 200;
    }
    else if ((event > 9) && (event < 14)) {
        strcpy(monster->name, "SUPER SLIME");
        monster->magicUser = false;
        monster->boss = false;
        monster->longDistance = false;
        monster->maxHP = 30;
        monster->hp = 30;
        monster->magicDefense = 22;
        monster->attack = 22;
        monster->defense = 22;
        monster->speed = 22;
        monster->level = 10;
        monster->goldYield = 12;
        monster->expYield = 30;
    }
    else if (event == 14) {
        strcpy(monster->name, "LORD SLIME");
        monster->magicUser = false;
        monster->boss = true;
        monster->longDistance = false;
        monster->maxHP = 50;
        monster->hp = 50;
        monster->magicDefense = 25;
        monster->attack = 25;
        monster->defense = 25;
        monster->speed = 25;
        monster->level = 15;
        monster->goldYield = 30;
        monster->expYield = 300;
    }
    else if ((event > 14) && (event < 19)) {
        if ((randomizeMonster == 0) || (randomizeMonster == 1) || (randomizeMonster == 2)) {
            strcpy(monster->name, "ORC");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = false;
            monster->maxHP = 30;
            monster->hp = 30;
            monster->magicDefense = 18;
            monster->attack = 22;
            monster->defense = 24;
            monster->speed = 26;
            monster->level = 15;
            monster->goldYield = 10;
            monster->expYield = 50;
        }
        else {
            strcpy(monster->name, "ARCHER");
            monster->magicUser = false;
            monster->boss = false;
            monster->longDistance = true;
            monster->maxHP = 25;
            monster->hp = 25;
            monster->magicDefense = 13;
            monster->attack = 25;
            monster->defense = 10;
            monster->speed = 35;
            monster->level = 15;
            monster->goldYield = 10;
            monster->expYield = 50;
        }
    }
    else if (event == 19) {
        strcpy(monster->name, "KING PORK");
        monster->magicUser = true;
        monster->boss = true;
        monster->longDistance = false;
        monster->maxHP = 75;
        monster->hp = 75;
        monster->maxMP = 50;
        monster->mp = 50;
        monster->magicDefense = 45;
        monster->attack = 35;
        monster->defense = 38;
        monster->speed = 41;
        monster->level = 20;
        monster->magic[0][0] = HEAL;
        monster->magic[0][1] = 41;
        monster->magic[1][0] = FIRE;
        monster->magic[1][1] = 35;
        monster->goldYield = 0;
        monster->expYield = 0;
    }
}
   
void monsterTurn(party *player, monster *monster, int turn) {
    
    if (strcmp(monster->name, "SLIME") == 0) {
        attack(player, monster, turn);
    }
    
    else if (strcmp(monster->name, "WIZARD") == 0) {
        wizard(player, monster, turn);
    }
    
    else if (strcmp(monster->name, "SNAKE") == 0) {
        attack(player, monster, turn);
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
        kingPork(player, monster, turn);
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

void kingPork(party *player, monster *monster, int turn) {
    
    int roll = (rand() % 10);
    
    if ((monster->hp <= (monster->maxHP / 4)) && (monster->mp >= 3)) {
        heal(player, monster, turn);
    }
    else if ((roll >= 1) && (monster->mp >= 5)) {
        fire(player, monster, turn);
    }
    else {
        attack(player, monster, turn);
    }
}
