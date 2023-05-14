#ifndef magic_h
#define magic_h

#include <stdio.h>
#include "datatypes.h"
#include "player.h"

void setMagic(party *player);
void heal(party *player, monster *monster, int turn);
void fire(party *player, monster *monster, int turn);
void shield(party *player, monster *monster, int turn);
int magicDamage(party player, monster monster, int turn);

#endif /* magic_h */
