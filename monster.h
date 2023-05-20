#ifndef monster_h
#define monster_h

#include <stdio.h>
#include <string.h>
#include "datatypes.h"
#include "magic.h"
#include "battle.h"

void createMonster(monster *monster, int event, bool hardMode);
void monsterTurn(party *player, monster *monster, companion *companion, int turn);
void strike(party *player, monster *monster, int turn);
void wizard(party *player, monster *monster, int turn);
void bossIntimidation(party player, monster monster, stat statChanges[2]);
void kingPork(party *player, monster *monster, companion *companion, int turn);
void kingPorkFinalStand(party player, monster *monster, stat statChanges[2], int *turnAtHalfHP, int *turnAtQuarterHP);

#endif /* monster_h */
