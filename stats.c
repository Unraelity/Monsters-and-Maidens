#include "stats.h"

void setStatBoosts(stat character[2]) {
    
    character[PLAYER_STATS].magicChange = 1;
    character[PLAYER_STATS].magicDefenseChange = 1;
    character[PLAYER_STATS].attackChange = 1;
    character[PLAYER_STATS].defenseChange = 1;
    character[PLAYER_STATS].speedChange = 1;
    
    character[MONSTER_STATS].magicChange = 1;
    character[MONSTER_STATS].magicDefenseChange = 1;
    character[MONSTER_STATS].attackChange = 1;
    character[MONSTER_STATS].defenseChange = 1;
    character[MONSTER_STATS].speedChange = 1;
    
}

void saveRealStats(stat character[2], party player, monster monster) {
    
    character[PLAYER_STATS].realMagic[HEAL] = player.magic[HEAL][1];
    character[PLAYER_STATS].realMagic[FIRE] = player.magic[FIRE][1];
    character[PLAYER_STATS].realMagicDefense = player.magicDefense;
    character[PLAYER_STATS].realAttack = player.attack;
    character[PLAYER_STATS].realDefense = player.defense;
    character[PLAYER_STATS].realSpeed = player.speed;
    
    character[MONSTER_STATS].realMagic[HEAL] = monster.magic[HEAL][1];
    character[MONSTER_STATS].realMagic[FIRE] = monster.magic[FIRE][1];
    character[MONSTER_STATS].realMagicDefense = monster.magicDefense;
    character[MONSTER_STATS].realAttack = monster.attack;
    character[MONSTER_STATS].realDefense = monster.defense;
    character[MONSTER_STATS].realSpeed = monster.speed;
    
}

void implementStatChanges(stat character[2], party *player, monster *monster) {
    
    fixMaxStats(&character[PLAYER_STATS].magicChange, player, monster);
    player->magic[HEAL][1] = character[PLAYER_STATS].realMagic[HEAL] * character[PLAYER_STATS].magicChange;
    player->magic[FIRE][1] = character[PLAYER_STATS].realMagic[FIRE] * character[PLAYER_STATS].magicChange;
    fixMaxStats(&character[PLAYER_STATS].magicDefenseChange, player, monster);
    player->magicDefense = character[PLAYER_STATS].realMagicDefense * character[PLAYER_STATS].magicDefenseChange;
    fixMaxStats(&character[PLAYER_STATS].attackChange, player, monster);
    player->attack = character[PLAYER_STATS].realAttack * character[PLAYER_STATS].attackChange;
    fixMaxStats(&character[PLAYER_STATS].defenseChange, player, monster);
    player->defense = character[PLAYER_STATS].realDefense * character[PLAYER_STATS].defenseChange;
    fixMaxStats(&character[PLAYER_STATS].speedChange, player, monster);
    player->speed = character[PLAYER_STATS].realSpeed * character[PLAYER_STATS].speedChange;
    
    fixMaxStats(&character[MONSTER_STATS].magicChange, player, monster);
    monster->magic[HEAL][1] = character[MONSTER_STATS].realMagic[HEAL] * character[MONSTER_STATS].magicChange;
    monster->magic[FIRE][1] = character[MONSTER_STATS].realMagic[FIRE] * character[MONSTER_STATS].magicChange;
    fixMaxStats(&character[MONSTER_STATS].magicDefenseChange, player, monster);
    monster->magicDefense = character[MONSTER_STATS].realMagicDefense * character[MONSTER_STATS].magicDefenseChange;
    fixMaxStats(&character[MONSTER_STATS].attackChange, player, monster);
    monster->attack = character[MONSTER_STATS].realAttack * character[MONSTER_STATS].attackChange;
    fixMaxStats(&character[MONSTER_STATS].defenseChange, player, monster);
    monster->defense = character[MONSTER_STATS].realDefense * character[MONSTER_STATS].defenseChange;
    fixMaxStats(&character[MONSTER_STATS].speedChange, player, monster);
    monster->speed = character[MONSTER_STATS].realSpeed * character[MONSTER_STATS].speedChange;
    
}

void fixMaxStats(float *statChange, party *player, monster *monster) {
    
    if (*statChange > 3.375) {
        printf("%s's STATS CANNOT GO ANY HIGHER!", player->name);
        *statChange = 3.375;
        sleep(2);
    }
    else if (*statChange < 0.2962963) {
        printf("%s's STATS CANNOT GO ANY LOWER!", player->name);
        *statChange = 0.2962963;
        sleep(2);
    }
}

void resetStats(stat character[2], party *player) {
    
    player->magic[HEAL][1] = character[PLAYER_STATS].realMagic[HEAL];
    player->magic[FIRE][1] = character[PLAYER_STATS].realMagic[FIRE];
    player->magicDefense = character[PLAYER_STATS].realMagicDefense;
    player->attack = character[PLAYER_STATS].realAttack;
    player->defense = character[PLAYER_STATS].realDefense;
    player->speed = character[PLAYER_STATS].realSpeed;
    
}
