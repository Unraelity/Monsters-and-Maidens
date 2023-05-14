#ifndef shop_h
#define shop_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "datatypes.h"
#include "item.h"
#include "print.h"

int shop(party *player, companion companion, item **head, item **tail, int timeShopped);

#endif /* shop_h */
