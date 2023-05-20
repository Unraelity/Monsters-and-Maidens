#ifndef player_h
#define player_h

#include <stdio.h>
#include <string.h>
#include "datatypes.h"
#include "companion.h"
#include "magic.h"
#include "item.h"

void playerInfo(party *player, item **itemHead, item **itemTail);
int getStats(party *player, companion *companion, item **itemHead, item **itemTail, int eventNum);
void saveCharacter(party player, int eventNum);

#endif /* player_h */
