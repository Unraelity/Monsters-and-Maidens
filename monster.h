#ifndef monster_h
#define monster_h

#include <stdio.h>
#include <string.h>
#include "datatypes.h"
#include "magic.h"
#include "battle.h"

void createMonster(monster *monster, int event);
void monsterTurn(party *player, monster *monster, int turn);
void wizard(party *player, monster *monster, int turn);
void kingPork(party *player, monster *monster, int turn);

#endif /* monster_h */
