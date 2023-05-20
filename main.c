//Add comments to the code
#include <stdio.h>
#include <time.h>
#include "datatypes.h"
#include "intro.h"
#include "events.h"

int main(void) {
    
    party player;
    monster monster;
    companion companion;
    bool hardMode;
    
    item *itemHead = NULL, *itemTail = NULL;

    srand((int)time(NULL));
    
    int eventNum = startGame(&player, &companion, &itemHead, &itemTail, &hardMode);
    strcpy(monster.name, "EMPTY");
    
    return events(player, companion, monster, itemHead, itemTail, eventNum, hardMode);
}
