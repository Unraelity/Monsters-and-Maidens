#ifndef stats_h
#define stats_h

#include <stdio.h>
#include "datatypes.h"

void setStatBoosts(stat character[2]);
void saveRealStats(stat character[2], party player, monster monster);
void implementStatChanges(stat character[2], party *player, monster *monster);
void fixMaxStats(float *statChange, party *player, monster *monster);
void resetStats(stat character[2], party *player);

#endif /* stats_h */
