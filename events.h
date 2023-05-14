#ifndef events_h
#define events_h

#include <stdio.h>
#include "player.h"
#include "monster.h"
#include "companion.h"
#include "battle.h"
#include "statTrade.h"
#include "fishing.h"
#include "riddles.h"
#include "shop.h"
#include "ending.h"

int events(party player, companion companion, monster monster, item *itemHead, item *itemTail, int eventNum);

#endif /* events_h */
