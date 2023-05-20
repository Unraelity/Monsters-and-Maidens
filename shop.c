#include "shop.h"

int shop(party *player, companion companion, item **head, item **tail, int timesShopped) {
    
    int itemChosen, i = 1, playerInput, price;
    char yesOrNo = 'c', boneName[] = "BONE", buyOrSell = 'n';
    item storeItem, *userItem, *temp;
    bool boughtBone = findItem(*head, boneName);
    
    printShop(*player);
    
    if (timesShopped == 0) {
        printf("Hello there! I am the TRAVELING MERCHANT. Why was that in all caps?\n");
        sleep(2);
        printf("Anyways, buy or sell whatever your hearts desire.\n");
        sleep(1);
    }
    else {
        printf("Welcome back great %s. Buy or sell what you like, can't get stuff anywhere else... besides chest.\n", player->name);
        sleep(2);
    }
    
    timesShopped++;
    
    while (yesOrNo != 'n') {
        
        itemChosen = 0;
        playerInput = 0;
        
        printf("(Press b for BUY or s for SELL or l to LEAVE)\n");
        scanf("%*c%c", &buyOrSell);
        
        while ((buyOrSell != 'b') && (buyOrSell != 's') && (buyOrSell != 'l')) {
            printf("(Press b for BUY or s for SELL or l to LEAVE)\n");
            scanf("%*c%c", &buyOrSell);
        }
        
        if (buyOrSell == 'l') {
            printf("Come back soon...PLEASE!!!\n");
            sleep(1);
            return timesShopped;
        }
        else if (buyOrSell == 'b') {
            while (itemChosen != 11) {
                
                printf("%s has %dG.\n", player->name, player->gold);
                printf("BUY BUY BUY!\n");
                printf("1 POTION (50 G)\n");
                printf("2 ANTIDOTE (15 G)\n");
                printf("3 OINTMENT (20 G)\n");
                printf("4 ELIXIR (30 G)\n");
                printf("5 X-ATTACK (25 G)\n");
                printf("6 X-DEFENSE (25 G)\n");
                printf("7 X-MAGIC (35 G)\n");
                printf("8 X-MAGIC-DEFENSE (25 G)\n");
                printf("9 X-SPEED (25 G)\n");
                if ((boughtBone != true) && (companion.tamed != true)) {
                    printf("10 BONE (100 G)\n");
                }
                else {
                    printf("10 BONE (SOLD OUT)\n");
                }
                printf("11 NEVERMIND\n");
                scanf("%d", &itemChosen);
                
                switch (itemChosen) {
                    case 1:
                        printf("That is my WORLD FAMOUS POTION. You can use that to restore 50%% of your HP!\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 50)) {
                            player->gold -= 50;
                            strcpy(storeItem.name, "POTION");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("POTION has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 50)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 2:
                        printf("An ANTIDOTE of my own making. Use that to heal POISON inflicted from that DARN SNAKE ENEMY.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 15)) {
                            player->gold -= 15;
                            strcpy(storeItem.name, "ANTIDOTE");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("ANTIDOTE has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 15)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 3:
                        printf("So my OINTMENT catches your eye? You can use that to heal BURN inflicted from FIRE ATTACKS.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 20)) {
                            player->gold -= 20;
                            strcpy(storeItem.name, "OINTMENT");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("OINTMENT has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 20)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 4:
                        printf("Ah I knew you had a good eye! That's an ELIXIR. Use it to restore 50%% of your MP!\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 30)) {
                            player->gold -= 30;
                            strcpy(storeItem.name, "ELIXIR");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("ELIXIR has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 30)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 5:
                        printf("An X-ITEM huh? It seems you are not a CASUAL at all!\n");
                        sleep(2);
                        printf("This X-ITEM is for ATTACK, and boosts it by x1.5.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 25)) {
                            player->gold -= 30;
                            strcpy(storeItem.name, "X-ATTACK");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("X-ATTACK has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 25)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 6:
                        printf("An X-ITEM huh? It seems you are not a CASUAL at all!\n");
                        sleep(2);
                        printf("This X-ITEM is for DEFENSE, and boosts it by x1.5.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 25)) {
                            player->gold -= 30;
                            strcpy(storeItem.name, "X-DEFENSE");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("X-DEFENSE has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 25)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 7:
                        printf("An X-ITEM huh? It seems you are not a CASUAL at all!\n");
                        sleep(2);
                        printf("This X-ITEM is for MAGIC, and boosts it by x1.5.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 25)) {
                            player->gold -= 30;
                            strcpy(storeItem.name, "X-MAGIC");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("X-MAGIC has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 25)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 8:
                        printf("An X-ITEM huh? It seems you are not a CASUAL at all!\n");
                        sleep(2);
                        printf("This X-ITEM is for MAGIC-DEFENSE, and boosts it by x1.5.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 25)) {
                            player->gold -= 30;
                            strcpy(storeItem.name, "X-MAGIC-DEFENSE");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("X-MAGIC-DEFENSE has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 25)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 9:
                        printf("An X-ITEM huh? It seems you are not a CASUAL at all!\n");
                        sleep(2);
                        printf("This X-ITEM is for SPEED, and boosts it by x1.5.\n");
                        sleep(2);
                        if (timesShopped > 1) {
                            printf("But you already knew that.\n");
                            sleep(1);
                        }
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 25)) {
                            player->gold -= 30;
                            strcpy(storeItem.name, "X-SPEED");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("X-SPEED has been added to your items.\n");
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 25)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 10:
                        printf("Uhhh that's a BONE. It's got to have some use right? Hehe\n");
                        sleep(2);
                        printf("Would you like to BUY?\n");
                        printf("(Type y/n)\n");
                        scanf("%*c%c", &yesOrNo);
                        if ((yesOrNo == 'y') && (player->gold >= 100) && (boughtBone != true) && (companion.tamed != true)) {
                            player->gold -= 100;
                            strcpy(storeItem.name, "BONE");
                            addItem(player, &storeItem, head, tail);
                            printf("The DEAL IS DONE!\n");
                            printf("BONE has been added to your items.\n");
                        }
                        else if ((boughtBone) || (companion.tamed)) {
                            printf("You already bought that!\n");
                            sleep(1);
                        }
                        else if ((yesOrNo == 'y') && (player->gold < 30)) {
                            printf("You can't afford that CHEAPO!\n");
                            sleep(1);
                        }
                        else {
                            printf("Oh! Why not try something else then?\n");
                            sleep(1);
                        }
                        break;
                    case 11:
                        break;
                    default:
                        printf("That's not an option!\n");
                        sleep(1);
                }
            }
        }
        
        else if (buyOrSell == 's') {
            
            while (playerInput != i) {
                temp = *head;
                i = 1;
                
                printf("What would you like to SELL?\n");
                
                while (temp != NULL) {
                    printf("%d %s\n", i, temp->name);
                    temp->spot = i;
                    temp = temp->pt;
                    i++;
                }
                
                printf("%d NEVERMIND\n", i);
                
                scanf("%d", &playerInput);
                
                if (playerInput == i) {
                    break;
                }
                
                userItem = searchItem(*head, playerInput);
                
                if (strcmp(userItem->name, "POTION") == 0) {
                    printf("What a delicious POTION. Is it one of mine?\n");
                    sleep(1);
                    price = 25;
                }
                else if (strcmp(userItem->name, "ELIXIR") == 0) {
                    printf("That's a nice ELIXIR you got there. Would be a shame if someone bought it.\n");
                    sleep(2);
                    price = 15;
                }
                else if (strcmp(userItem->name, "ANTIDOTE") == 0) {
                    printf("An ANTIDOTE? I'm not likely to get POISONED anytime soon... but I'll buy it anyway.\n");
                    sleep(2);
                    price = 12;
                }
                else if (strcmp(userItem->name, "OINTMENT") == 0) {
                    printf("OINTMENT? Great I've been needing some for... I mean if you insist.\n");
                    sleep(2);
                    price = 10;
                }
                else if (strcmp(userItem->name, "X-ATTACK") == 0) {
                    printf("Perfect, an X-ITEM. Just what every SHOP OWNER who never adventures needs.\n");
                    sleep(2);
                    price = 12;
                }
                else if (strcmp(userItem->name, "X-DEFENSE") == 0) {
                    printf("Perfect, an X-ITEM. Just what every SHOP OWNER who never adventures needs.\n");
                    sleep(2);
                    price = 12;
                }
                else if (strcmp(userItem->name, "X-MAGIC") == 0) {
                    printf("Perfect, an X-ITEM. Just what every SHOP OWNER who never adventures needs.\n");
                    sleep(2);
                    price = 17;
                }
                else if (strcmp(userItem->name, "X-MAGIC-DEFENSE") == 0) {
                    printf("Perfect, an X-ITEM. Just what every SHOP OWNER who never adventures needs.\n");
                    sleep(2);
                    price = 12;
                }
                else if (strcmp(userItem->name, "X-SPEED") == 0) {
                    printf("Perfect, an X-ITEM. Just what every SHOP OWNER who never adventures needs.\n");
                    sleep(2);
                    price = 12;
                }
                else if (strcmp(userItem->name, "BONE") == 0) {
                    printf("A BONE? Really?\n");
                    sleep(1);
                    price = 1;
                }
                else if (strcmp(userItem->name, "SHARK") == 0) {
                    printf("Is THAT A SHARK??? Why would you bring that in HERE?\n");
                    sleep(1);
                    printf("I'll BUY IT just stop putting it IN MY FACE LIKE THAT!\n");
                    sleep(1);
                    
                    price = 50;
                }
                else if (strcmp(userItem->name, "WALLEYE") == 0) {
                    printf("What a MAGNIFICENT WALLEYE you have!\n");
                    sleep(1);
                    price = 30;
                }
                else if (strcmp(userItem->name, "MINNOW") == 0) {
                    printf("Is that a fish or Plankton?\n");
                    sleep(1);
                    price = 10;
                }
                else {
                    break;
                }
                
                if (price != 0) {
                    printf("I'll take it off your hands for %d G.\n", price);
                    sleep(1);
                    
                    printf("Do we have a DEAL?\n");
                    printf("(Type y/n)\n");
                    scanf("%*c%c", &yesOrNo);
                    
                    if (yesOrNo == 'y') {
                        deleteItem(userItem, head, tail);
                        printf("You gave the TRAVELING MERCHANT your ITEM.\n");
                        sleep(1);
                        printf("You received %d G in exchange.\n", price);
                        player->gold += price;
                        sleep(1);
                    }
                    else {
                        printf("Oh alright, maybe next time then.\n");
                        sleep(1);
                    }
                    
                }
                
            }
        }
        
        printf("Is there anything else I can help you with? (Press y/n)\n");
        scanf("%*c%c", &yesOrNo);
        while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
            printf("(Press y/n)\n");
            scanf("%*c%c", &yesOrNo);
        }
        
        if (yesOrNo == 'n') {
            printf("Come back soon...PLEASE!!!\n");
            sleep(1);
        }
        
        
    }
    
    return timesShopped;
}
