#ifndef spoils_h
#define spoils_h

#include <stdio.h>
#include <string.h>
#include "datatypes.h"
#include "item.h"
#include "print.h"

void gainGold(party *player, monster monster);
void gainEXP(party *player, monster monster);
void companionEXP(companion *companion, monster monster);
void levelUp(party *player);
void companionLevelUp(companion *companion);
void treasure(party *player, item **head, item **tail);

#endif /* spoils_h */
