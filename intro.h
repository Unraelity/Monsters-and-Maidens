#ifndef intro_h
#define intro_h

#include <stdio.h>
#include "datatypes.h"
#include "player.h"
#include "print.h"

int startGame(party *player, companion *companion, item **itemHead, item **itemTail);
void instructions(void);

#endif /* begin_h */
