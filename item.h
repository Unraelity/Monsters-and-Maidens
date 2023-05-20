#ifndef item_h
#define item_h

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "datatypes.h"

void setItems(item **head, item **tail);
void getItems(party *player, item **head, item **tail);
int countItems(item *head);
item *searchItem(item *head, int itemNum);
bool findItem(item *head, char itemName[]);
void potion(party *player);
void antidote(party *player);
void ointment(party *player);
void elixir(party *player);
void addItem(party *player, item *addItem, item **head, item **tail);
void deleteItem(item *deleteItem, item **head, item **tail);
void saveItems(party player, item **head);

#endif
