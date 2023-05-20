#include "statusConditions.h"

void checkStatusConditions(party *player, monster *monster) {
    
    int damage;
    
    if (player->hp > 0) {
        if (strcmp(player->statusCondition, "NONE") != 0) {
            damage = player->maxHP / 16;
            if (damage < 1) {
                damage = 1;
            }
            printf("%s took %d damage from %s.\n", player->name, damage, player->statusCondition);
            player->hp -= damage;
            sleep(2);
        }
    }
    if (monster->hp > 0) {
        if (strcmp(monster->statusCondition, "NONE") != 0) {
            damage = monster->maxHP / 16;
            if (damage < 1) {
                damage = 1;
            }
            printf("%s took %d damage from %s.\n", monster->name, damage, monster->statusCondition);
            monster->hp -= damage;
            sleep(2);
        }
    }
    
    
}
