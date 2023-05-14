#ifndef companion_h
#define companion_h

#include <stdio.h>
#include <string.h>
#include "datatypes.h"
#include "magic.h"
#include "item.h"
#include "battle.h"
#include "print.h"

void createCompanion(companion *companion);
void getCompanion(party player, companion *companion);
int companionBattle(party *player, companion *companion, item **head, item **tail);
void untamedAttack(party *player, companion *companion, int turn);
int untamedAttackDamage(party player, companion companion, int turn);
void saveCompanion(party player, companion companion);

#endif /* companion_h */
