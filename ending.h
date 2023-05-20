#ifndef ending_h
#define ending_h

#include <stdio.h>
#include "player.h"
#include "companion.h"
#include "item.h"
#include "print.h"

void victory(party *player, companion *companion, item **head, int eventNum, bool hardMode);
void gameOver(party *player, companion *companion, item **head, int eventNum);
void credits(void);

#endif /* ending_h */
