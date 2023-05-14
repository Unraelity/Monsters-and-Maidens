#include "item.h"

void setItems(item **head, item **tail) {
    
    item *temp = (item *)malloc(sizeof(item));
    strcpy(temp->name, "POTION");
        
    if (*head == NULL) {
        *head = temp;
    }
    else {
        (*tail)->pt = temp;
    }
    *tail = temp;
    (*tail)->pt = NULL;
}

void getItems(party *player, item **head, item **tail) {
    
    item *temp = NULL;
    char fileName[50];
    int count = 0;
    FILE *inp;
    
    strcpy(fileName, player->name);
    strcat(fileName, "'s_Items.txt\0");
    inp = fopen(fileName, "r");
    
    if (inp != NULL) {
        
        while(!feof(inp)) {
            
            temp = (item *)malloc(sizeof(item));
            fscanf(inp, "%s ", temp->name);
            
            if ((strcmp(temp->name, "POTION") == 0) || (strcmp(temp->name, "ELIXIR") == 0) || (strcmp(temp->name, "BONE") == 0)) {
                if (*head == NULL) {
                    *head = temp;
                }
                else {
                    (*tail)->pt = temp;
                }
                *tail = temp;
                (*tail)->pt = NULL;
                count++;
            }
        }
        
        if (count == 0) {
            
            printf("Looks like you didn't have any items.\n");
            sleep(1);
            
        }
        
        else {
            printf("Found your items too!\n");
            sleep(1);
        }
        
        fclose(inp);
    }
    
    else {
        printf("My bad, I couldn't find your items.\n");
        sleep(1);
        setItems(head, tail);
    }
    
}

int countItems(item *head) {
    
    int count = 0;
    item *temp = head;
    
    while((temp != NULL)) {
        count++;
        temp = temp->pt;
    }
    
    return count;
}

item *searchItem(item *head, int itemNum) {
    
    item *temp = head;
    
    while((temp->spot != itemNum) && (temp != NULL)) {
        temp = temp->pt;
    }
    
    return temp;
}

bool findItem(item *head, char itemName[]) {
    
    item *temp = head;
    
    if (temp == NULL) {
            return false;
    }
    
    while((strcmp(temp->name, itemName) != 0) && (temp != NULL)) {
        temp = temp->pt;
        
        if (temp == NULL) {
            break;
        }
        if (strcmp(temp->name, itemName) == 0) {
            return true;
        }
    }
    
    if (temp != NULL) {
        if (strcmp(temp->name, itemName) == 0) {
            return true;
        }
    }
    
    return false;
    
}

void potion(party *player) {
    
    printf("%s used a POTION.\n", player->name);
    usleep(100000);
    printf("You regained a %d HP.\n", (player-> maxHP / 2));
    sleep(1);
    player->hp = player->hp + (player->maxHP / 2);
    
    if (player->hp > player->maxHP) {
        player->hp = player->maxHP;
    }
}

void elixir(party *player) {
    
    printf("%s used an ELIXIR.\n", player->name);
    usleep(100000);
    printf("You regained a %d MP.\n", (player-> maxMP / 2));
    sleep(1);
    player->mp = player->mp + (player->maxMP / 2);
    
    if (player->mp > player->maxMP) {
        player->mp = player->maxMP;
    }
}

void addItem(party *player, item *addItem, item **head, item **tail) {
    
    item *temp = NULL;
    temp = (item *)malloc(sizeof(item));
    
    strcpy(temp->name, addItem->name);
    
    if (*head == NULL) {
        *head = temp;
    }
        
    else {
       (*tail)->pt = temp;
    }
    *tail = temp;
    temp->pt =NULL;
}

void deleteItem(item *deleteItem, item **head, item **tail) {
    
    item **temp = head;
    
    while ((*temp) != deleteItem){
        temp = &(*temp)->pt;
    }
    if (deleteItem == *head) {
        *head = deleteItem->pt;
    }
    if (deleteItem == *tail) { //
        *tail = *temp;
    }
    *temp = deleteItem->pt;
    free(deleteItem);
}

void saveItems(party player, item **head) {
    
    item *temp = *head;
    int i = 1;
    char fileName[50];
    FILE *outp;
    
    strcpy(fileName, player.name);
    strcat(fileName, "'s_Items.txt\0");
    outp = fopen(fileName, "w");
    
    while (temp != NULL) {
        fprintf(outp, "%s ", temp->name);
        temp->spot = i;
        temp = temp->pt;
        i++;
    }
    
    fclose(outp);
    printf("Items saved!\n");
    usleep(100000);
    
}
