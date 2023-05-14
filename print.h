#ifndef print_h
#define print_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "datatypes.h"
#include "magic.h"
#include "item.h"

void printPlayer(party player, companion companion);
void printStats(party player, companion companion);
void printBattle(party player, monster monster);
void printCompanionBattle(party player, companion companion);
void printBattle(party player, monster monster);
void printCompanionBattle(party player, companion companion);
void printBattle2(party player, monster monster, companion companion);
void printShop(party player);
void printDevil(party player, companion companion);
void printFishing(party player, companion companion);
void printRiddleMaster(party player);
int battleMenu(void);
void printDialogue(monster monster);
void printPlayerStats(party player, monster monster);
int magicMenu(party *player, monster *monster, int turn);
int itemsMenu(party *player, item **head, item **tail);
void printHouse(void);
void printChest(void);
void printVictory(void);
void printLose(void);

#endif /* print_h */
