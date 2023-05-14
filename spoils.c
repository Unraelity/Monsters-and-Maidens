#include "spoils.h"

void gainGold(party *player, monster monster) {
    
    if (strcmp(monster.name, "SLIME") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "WIZARD") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "SNAKE") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "GIANT") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "CHICKPEE") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "SUPER SLIME") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "KING SLIME") == 0) {
        player->gold += monster.goldYield;
        printf("%s received %d G.\n", player->name, monster.goldYield);
        usleep(100000);
    }

}

void gainEXP(party *player, monster monster) {
    
    if (strcmp(monster.name, "SLIME") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "WIZARD") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "SNAKE") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "GIANT") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "CHICKPEE") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "SUPER SLIME") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "KING SLIME") == 0) {
        player->exp += monster.expYield;
        printf("%s gained %d EXP.\n", player->name, monster.expYield);
        usleep(100000);
    }
    
    while (player->exp >= player->maxEXP) {
        player->exp -= player->maxEXP;
        levelUp(player);
    }
    
}

void companionEXP(companion *companion, monster monster) {
    
    if (strcmp(monster.name, "SLIME") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "WIZARD") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "SNAKE") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    
    else if (strcmp(monster.name, "GIANT") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "CHICKPEE") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "SUPER SLIME") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    else if (strcmp(monster.name, "KING SLIME") == 0) {
        companion->exp += monster.expYield;
        printf("%s gained %d EXP.\n", companion->name, monster.expYield);
        usleep(100000);
    }
    
    while (companion->exp >= companion->maxEXP) {
        companion->exp -= companion->maxEXP;
        companionLevelUp(companion);
    }
    
}

void levelUp(party *player) {
    
    player->attack += + 1;
    player->defense += + 1;
    player->speed += + 1;
    player->hp += 2;
    player->maxHP += 2;
    player->mp += 1;
    player->maxMP += + 1;
    player->level += + 1;
    player->maxEXP += + 13;
    player->magic[HEAL][1] += 1;
    player->magic[FIRE][1] += 1;
    player->magic[SHIELD][1] += 1;
    player->magicDefense += + 1;
    
    printf("%s LEVELED UP!\n", player->name);
    sleep(1);
    printf("You are now LEVEL %d!\n", player->level);
    sleep(1);
    
    if (player->level == 5) {
        printf("You unlocked the HEAL SPELL!\n");
        sleep(1);
        printf("Now you can HEAL yourself from those brutal beatdowns... I mean minor scraps.\n");
        sleep(2);
        printf("Check it out in the MAGIC menu!\n");
        sleep(1);
        player->magic[HEAL][0] = HEAL;
    }
    if (player->level == 10) {
        printf("You unlocked the FIRE SPELL!\n");
        sleep(1);
        printf("Let's burn them all you pyromaniac!\n");
        sleep(1);
        printf("Check it out in the MAGIC menu!\n");
        sleep(1);
        player->magic[FIRE][0] = FIRE;
    }
    if (player->level == 15) {
        printf("You unlocked the SHIELD SPELL!\n");
        sleep(1);
        printf("It pretty much just blocks attacks... *yawn*.\n");
        sleep(1);
        printf("Anyways, you can it out in the MAGIC menu if you feel so inclined.\n");
        sleep(2);
        player->magic[SHIELD][0] = SHIELD;
    }
    
}

void companionLevelUp(companion *companion) {
    
    companion->attack += 1;
    companion->speed += 1;
    companion->level += 1;
    companion->maxEXP += 15;
    
    printf("%s LEVELED UP!\n", companion->name);
    sleep(1);
    printf("It is now LEVEL %d!\n", companion->level);
    sleep(1);
    
}

void treasure(party *player, item **head, item **tail) {
    
    char open = 'n';
    
    printf("There's a CHEST too!\n");
    printChest();
    sleep(1);
    
    printf("(Type o open it)\n");
    while (open != 'o') {
        scanf("%*c%c", &open);
    }
    
    int treasureNum = rand() % 3;
    item newItem;
    
    if (treasureNum == 0) {
        
        int gold = rand() % 50;
        player->gold = player->gold + gold + 10;
        printf("You found %d G in the CHEST!\n", gold + 10);
        sleep(1);
        
    }
    else if (treasureNum == 1) {
        
        strcpy(newItem.name, "POTION");
        addItem(player, &newItem, head, tail);
        printf("You found a POTION in the CHEST!\n");
        sleep(1);
        
    }
    else if (treasureNum == 2) {
        
        strcpy(newItem.name, "ELIXIR");
        addItem(player, &newItem, head, tail);
        printf("You found a ELIXIR in the CHEST!\n");
        sleep(1);
        
    }
}
