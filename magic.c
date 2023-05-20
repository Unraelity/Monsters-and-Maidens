#include "magic.h"

void setMagic(party *player) {
    
    player->maxMP = 12;
    player->mp = 12;
    player->magic[HEAL][0] = LOCKED;
    player->magic[HEAL][1] = 7;
    player->magic[FIRE][0] = LOCKED;
    player->magic[FIRE][1] = 7;
    player->magic[SHIELD][0] = LOCKED;
    player->magic[SHIELD][1] = 0;
    player->magicDefense = 6;
    
}

void heal(party *player, monster *monster, int turn) {
    
    int healAmount;
    
    if (turn == 1) {
        
        printf("%s used a HEAL spell!\n", player->name);
        usleep(100000);
        healAmount = magicDamage(*player, *monster, 2);
        printf("You got healed %d HP!\n", healAmount);
        sleep(1);
        player->hp = player->hp + healAmount;
        
        if (player->hp > player->maxHP) {
            player->hp = player->maxHP;
        }
        player->mp = player->mp - 3;
    }
    
    else if (turn == -1) {
       
        printf("%s used a HEAL spell!\n", monster->name);
        usleep(100000);
        healAmount = magicDamage(*player, *monster, -2);
        printf("The %s got healed %d HP!\n", monster->name, healAmount);
        sleep(1);
        monster->hp = monster->hp + healAmount;
        
        if (monster->hp > monster->maxHP) {
            monster->hp = monster->maxHP;
        }
        monster->mp = monster->mp - 3;
    }
}

void fire(party *player, monster *monster, int turn) {
    
    int roll = (rand() % 10), burnRoll = rand() % 3, damage;
    
    if (turn == 1) {
        printf("%s used FIRE!\n", player->name);
        usleep(100000);
        if (roll == 0) {
            printf("WHAT!!! The fire blew away!\n");
            sleep(1);
        }
        else {
            damage = magicDamage(*player, *monster, turn);
            printf("BURN BABY BURN! You %d damage!\n", damage);
            sleep(1);
            monster->hp = monster->hp - damage;
        }
        player->mp = player->mp - 5;
        
        if ((burnRoll == 1) && (strcmp(monster->statusCondition, "NONE") == 0))  {
            printf("AWESOME! %s was BURNED!\n", monster->name);
            strcpy(monster->statusCondition, "BURN");
            sleep(2);
        }
    }
    
    if (turn == -1) {
        
        printf("%s used FIRE!\n", monster->name);
        usleep(100000);
        if (roll == 0) {
            printf("What a weak flame.\n");
            sleep(1);
        }
        else {
            damage = magicDamage(*player, *monster, turn);
            printf("The %s did %d damage!\n", monster->name, damage);
            sleep(1);
            player->hp = player->hp - damage;
        }
        monster->mp = monster->mp - 5;
        
        if ((burnRoll == 1) && (strcmp(player->statusCondition, "NONE") == 0)) {
            printf("SCORCHING! %s got BURNED!\n", player->name);
            strcpy(player->statusCondition, "BURN");
            sleep(2);
        }
    }
    
}

void shield(party *player, monster *monster) {
    
    printf("%s used a SHIELD!\n", player->name);
    usleep(100000);
    printf("It blocked the %s's attack!\n", monster->name);
    sleep(1);
    player->mp = player->mp - 2;
    sleep(1);
    
}

int magicDamage(party player, monster monster, int turn) {
    
    float damage, crit;
    int critRoll = (rand() % 10);
    
    if (turn == 1) {
      
        if (critRoll == 9) {
            crit = 1.5;
            printf("That was BLUE FIRE! ");
        }
        else {
            crit = 1;
        }
        
        damage = ((2 * (player.level)) + 10) / 5;
        damage *= player.magic[FIRE][1];
        damage /=  monster.magicDefense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    else if (turn == -1) {
        
        if (critRoll == 9) {
            crit = 1.5;
            printf("HOT HOT HOT! The BLUE FIRE burns! ");
        }
        else {
            crit = 1;
            printf("That burns! ");
        }
        
        damage = ((2 * (monster.level)) + 10) / 5;
        damage *= monster.magic[FIRE][1];
        damage /=  player.magicDefense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    else if (turn == 2) {
      
        if (critRoll == 9) {
            crit = 1.5;
            printf("Lucky! ");
        }
        else {
            crit = 1;
        }
        
        damage = ((2 * (player.level)) + 10) / 5;
        damage *= player.magic[HEAL][1];
        damage /= monster.magicDefense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    else if (turn == -2) {
        
        if (critRoll == 9) {
            crit = 1.5;
            printf("How lucky can it get? ");
        }
        else {
            crit = 1;
        }
        
        damage = ((2 * (monster.level)) + 10) / 5;
        damage *= monster.magic[HEAL][1];
        damage /= player.magicDefense;
        if (damage < 1) {
            damage = 1;
        }
        damage *= crit;
        return (int)damage;
        
    }
    
    return 0;
}
