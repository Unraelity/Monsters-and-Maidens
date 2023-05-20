#ifndef battle_h
#define battle_h

#include <stdio.h>
#include <stdbool.h>
#include "datatypes.h"
#include "companion.h"
#include "stats.h"
#include "magic.h"
#include "monster.h"
#include "statusConditions.h"
#include "spoils.h"
#include "print.h"

int battleTime(party *player, monster *monster, item **head, item **tail, int i, bool hardMode);
int determineTurn(party player, monster monster);
void attack(party *player, monster *monster, int turn);
int attackDamage(party player, monster monster, int turn);
int battleTime2(party *player, monster *monster, companion *companion, item **head, item **tail, int i, bool hardMode);
int determineTurn2(party player, monster monster, companion companion);
void attack2(party *player, monster *monster, companion *companion, int turn);
int attackDamage2(party player, monster monster, companion companion, int turn);
#endif /* battle_h */
