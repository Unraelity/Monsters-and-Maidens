//Add comments to the code
//Make spell that some monster can use that temporarily turn your companion against you
//Use shield in magic to temporarily boost defense
//Add status conditions (confusion, sleep, poison, burn, slowness, frozen)
//Add buffs (temporary stat enhancing items, magic that temporarily boost stats)
//Add debuffs (magic that temporarily lowering opponents stats)
//Add more character options (mage/warrior)
//Hard mode
#include <stdio.h>
#include <time.h>
#include "datatypes.h"
#include "intro.h"
#include "events.h"

int main(void) {
    
    party player;
    monster monster;
    
    companion companion;
    
    item *itemHead = NULL, *itemTail = NULL;

    srand((int)time(NULL));
    
    int eventNum = startGame(&player, &companion, &itemHead, &itemTail);
    strcpy(monster.name, "EMPTY");
    
    return events(player, companion, monster, itemHead, itemTail, eventNum);
}
