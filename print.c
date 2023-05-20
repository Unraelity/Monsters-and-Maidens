#include "print.h"

void printPlayer(party player, companion companion) {
    
    if (companion.tamed == false) {
        printf(" O       \n");
        printf("/|\\|-- \n");
        printf("/ \\    \n");
        printf("%s\n", player.name);
    }
    else {
        printf(" O              \n");
        printf("/|\\|--  ____|_ \n");
        printf("/ \\      | |   \n");
        printf("%s     %s\n", player.name, companion.name);
    }
    
}

void printStats(party player, companion companion) {
    
    printPlayer(player, companion);
    if (companion.tamed) {
        printf("\n");
        printf("PLAYER: \n");
    }
    printf("LEVEL: %d \n", player.level);
    printf("EXP: %d/%d \n", player.exp, player.maxEXP);
    if (strcmp(player.statusCondition, "NONE") != 0) {
        printf("STATUS CONDITION: %s \n", player.statusCondition);
    }
    printf("HP: %d/%d \n", player.hp, player.maxHP);
    printf("MP: %d/%d \n", player.mp, player.maxMP);
    printf("ATTACK: %d \n", (int)player.attack);
    printf("DEFENSE: %d \n", (int)player.defense);
    printf("SPEED: %d \n", (int)player.speed);
    printf("HEAL POWER: %d \n", (int)player.magic[HEAL][1]);
    printf("FIRE POWER: %d \n", (int)player.magic[FIRE][1]);
    printf("MAGIC DEFENSE: %d \n", (int)player.magicDefense);
    printf("GOLD: %dG \n", player.gold);
    
    if (companion.tamed) {
        printf("\n");
        printf("COMPANION: \n");
        printf("LEVEL: %d \n", companion.level);
        printf("EXP: %d/%d \n", (int)companion.exp, companion.maxEXP);
        printf("ATTACK: %d\n", (int)companion.attack);
        printf("SPEED: %d \n", (int)companion.speed);
    }
    
    sleep(3);
    
}

void printShop(party player) {
    
    printf("  O        O \n");
    printf(" /|\\     /( )\\\n");
    printf(" / \\      / \\\n");
    printf(" %s   MERCHANT\n", player.name);
    
}

void printTipSign(void) {
    
    printf(" ___  \n");
    printf("||.|| \n");
    printf(" ---  \n");
    printf("  |   \n");
    printf("  |   \n");
    
}

int printTips(party player, companion companion, int timesTipped) {
    
    int randomizeTip = rand() % 8;
    printTipSign();
    
    if (timesTipped == 0) {
        sleep(1);
        printf("Hello there! I'm the Tip Sign!\n");
        sleep(1);
        printf("I can give you useful advice for the game.\n");
    }
    
    sleep(1);
    timesTipped++;
    
    printf("Here's your tip: ");
    sleep(1);
    
    if ((randomizeTip == 0) && (player.numLosses > 0)) {
        printf("Not continuing from where you left off can help you raise your level for Boss Battles.\n");
    }
    else if ((randomizeTip == 1) && (companion.tamed = false)) {
        printf("Maybe that BONE is a little more useful than it seems...\n");
    }
    else if (randomizeTip == 2) {
        printf("That RIDDLEMASTER sure is a SMART GUY, isn't he...\n");
    }
    else if (randomizeTip == 3) {
        printf("Remember next time your DEALING WITH THE DEVIL, you have a lot more HP and MP than any other stats.\n");
    }
    else if (randomizeTip == 4) {
        printf("POISON and BURN do NOT Heal outside a regular battle.\n");
        sleep(3);
        printf("Use ANTIDOTE or OINTMENT, respectively, to HEAL those STATUSES.\n");
    }
    else if ((randomizeTip == 5) && (player.numWins > 0)) {
        printf("HARD MODE may be difficult, but you can acquire much more G in that MODE.\n");
    }
    else if ((randomizeTip == 6) && (player.numWins > 0)) {
        printf("All STATS CHANGES are removed after a BATTLE.\n");
    }
    else {
        printf("Wizards have strong Magic Stats but low Physical Stats.\n");
    }
    
    sleep(4);
    return timesTipped;
}

int battleMenu(void) {
    
    int playerChoice;
    
    printf("What will you do?\n");
    printf("1 ATTACK\n");
    printf("2 MAGIC\n");
    printf("3 ITEMS\n");
    printf("4 STATS\n");
    printf("5 RUN AWAY\n");
    
    scanf("%d", &playerChoice);
    
    while ((playerChoice > 5) || (playerChoice < 1)) {
        printf("That's not an option\n");
        printf("What will you do?\n");
        scanf("%d", &playerChoice);
    }
    
    return playerChoice;
}

void printBattleStats(party player, monster monster, companion companion) {
    
    char printStats = 'n';
    
    if (companion.tamed) {
        while (printStats != 'r') {
            printf("(Press p for %s, c for %s, m for %s or r to return)\n", player.name, companion.name, monster.name);
            scanf("%*c%c", &printStats);
            while ((printStats != 'p') && (printStats != 'c') && (printStats == 'm') && (printStats == 'r')) {
                printf("(Press p for %s, c for %s, m for %s or r to return)\n", player.name, companion.name, monster.name);
                scanf("%*c%c", &printStats);
            }
            
            if (printStats == 'r') {
                return;
            }
            else if (printStats == 'p') {
                
                printf("\n");
                printf("%s: \n", player.name);
                printf("LEVEL: %d \n", player.level);
                printf("EXP: %d/%d \n", player.exp, player.maxEXP);
                if (strcmp(player.statusCondition, "NONE") != 0) {
                    printf("STATUS CONDITION: %s \n", player.statusCondition);
                }
                printf("HP: %d/%d \n", player.hp, player.maxHP);
                printf("MP: %d/%d \n", player.mp, player.maxMP);
                printf("ATTACK: %d \n", (int)player.attack);
                printf("DEFENSE: %d \n", (int)player.defense);
                printf("SPEED: %d \n", (int)player.speed);
                printf("HEAL POWER: %d \n", (int)player.magic[HEAL][1]);
                printf("FIRE POWER: %d \n", (int)player.magic[FIRE][1]);
                printf("MAGIC DEFENSE: %d \n", (int)player.magicDefense);
            }
            
            else if (printStats == 'm') {
                
                printf("\n");
                printf("%s: \n", monster.name);
                printf("LEVEL: %d \n", monster.level);
                if (strcmp(monster.statusCondition, "NONE") != 0) {
                    printf("STATUS CONDITION: %s \n", monster.statusCondition);
                }
                printf("HP: %d/%d \n", (int)monster.hp, (int)monster.maxHP);
                if (monster.magicUser) {
                    printf("MP: %d/%d \n", (int)monster.mp, (int)monster.maxMP);
                }
                printf("ATTACK: %d \n", (int)monster.attack);
                printf("DEFENSE: %d \n", (int)monster.defense);
                printf("SPEED: %d \n", (int)monster.speed);
                if (monster.magicUser) {
                    printf("HEAL POWER: %d \n", (int)monster.magic[HEAL][1]);
                    printf("FIRE POWER: %d \n", (int)monster.magic[FIRE][1]);
                    printf("MAGIC DEFENSE: %d \n", (int)monster.magicDefense);
                }
            }
            
            else if (printStats == 'c') {
                
                if (companion.tamed) {
                    printf("\n");
                    printf("%s: \n", companion.name);
                    printf("LEVEL: %d \n", companion.level);
                    printf("EXP: %d/%d \n", (int)companion.exp, companion.maxEXP);
                    printf("ATTACK: %d\n", (int)companion.attack);
                    printf("SPEED: %d \n", (int)companion.speed);
                }
                
            }
            
            sleep(3);
            printf("\n");
        }
    }
    
    else {
        
        while (printStats != 'r') {
            printf("(Press p for %s, m for %s or r to RETURN)\n", player.name, monster.name);
            scanf("%*c%c", &printStats);
            while ((printStats != 'p') && (printStats == 'm') && (printStats == 'r')) {
                printf("(Press p for %s, m for %s or r to RETURN)\n", player.name, monster.name);
                scanf("%*c%c", &printStats);
            }
            
            if (printStats == 'r') {
                return;
            }
            else if (printStats == 'p') {
                
                printf("\n");
                printf("%s: \n", player.name);
                printf("LEVEL: %d \n", player.level);
                printf("EXP: %d/%d \n", player.exp, player.maxEXP);
                if (strcmp(player.statusCondition, "NONE") != 0) {
                    printf("STATUS CONDITION: %s \n", player.statusCondition);
                }
                printf("HP: %d/%d \n", player.hp, player.maxHP);
                printf("MP: %d/%d \n", player.mp, player.maxMP);
                printf("ATTACK: %d \n", (int)player.attack);
                printf("DEFENSE: %d \n", (int)player.defense);
                printf("SPEED: %d \n", (int)player.speed);
                printf("HEAL POWER: %d \n", (int)player.magic[HEAL][1]);
                printf("FIRE POWER: %d \n", (int)player.magic[FIRE][1]);
                printf("MAGIC DEFENSE: %d \n", (int)player.magicDefense);
            }
            
            else if (printStats == 'm') {
                
                printf("\n");
                printf("%s: \n", monster.name);
                printf("LEVEL: %d \n", monster.level);
                if (strcmp(monster.statusCondition, "NONE") != 0) {
                    printf("STATUS CONDITION: %s \n", monster.statusCondition);
                }
                printf("HP: %d/%d \n", (int)monster.hp, (int)monster.maxHP);
                if (monster.magicUser) {
                    printf("MP: %d/%d \n", (int)monster.mp, (int)monster.maxMP);
                }
                printf("ATTACK: %d \n", (int)monster.attack);
                printf("DEFENSE: %d \n", (int)monster.defense);
                printf("SPEED: %d \n", (int)monster.speed);
                if (monster.magicUser) {
                    printf("HEAL POWER: %d \n", (int)monster.magic[HEAL][1]);
                    printf("FIRE POWER: %d \n", (int)monster.magic[FIRE][1]);
                    printf("MAGIC DEFENSE: %d \n", (int)monster.magicDefense);
                }
            }
            
            sleep(3);
            printf("\n");
        }
    }
    
}

int magicMenu(party *player, monster *monster) {
    
    int i, healPlacement = 0, firePlacement = 0, shieldPlacement = 0, lock[MAX_MAGIC], playerInput;
    
    printf("What magic will you use?\n");
    
    for (i = 0; i < MAX_MAGIC; i++) {
        
        if (player->magic[i][0] == HEAL) {
            printf("%d HEAL (-3 MP)\n", i+1);
            healPlacement = i+1;
        }
        else if (player->magic[i][0] == FIRE) {
            printf("%d FIRE (-5 MP)\n", i+1);
            firePlacement = i+1;
        }
        else if (player->magic[i][0] == SHIELD) {
            printf("%d SHIELD (-2 MP)\n", i+1);
            shieldPlacement = i+1;
        }
        else if (player->magic[i][0] == LOCKED) {
            printf("LOCKED\n");
            lock[i] = i+1;
        }
    }
    
    printf("%d NEVERMIND\n", i+1);
    
    scanf("%d", &playerInput);
    
    if ((playerInput == healPlacement) && (player->mp >= 3)) {
        return 1;
    }
    else if ((playerInput == firePlacement) && (player->mp >= 5)) {
        return 2;
    }
    else if ((playerInput == shieldPlacement) && (player->mp >= 2)) {
        shield(player, monster);
        return 0;
    }
    else if ((playerInput == lock[HEAL]) || (playerInput == lock[FIRE]) || (playerInput == lock[SHIELD])) {
        printf("Can't you read? It's LOCKED!\n");
        return -1;
    }
    else if (playerInput == i+1) {
        return -1;
    }
    else {
        printf("You don't have enough MP!\n");
        return -1;
    }
    
    return -1;
    
}

void printDialogue(monster monster) {
    
    if (strcmp(monster.name, "GIANT") == 0) {
        printf("Giant: WAHAHAHAHAHA look how tiny you are! I could squash you with my little toe!\n");
        sleep(2);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        printf("MEGA Chicken: BAK BAKBAK BAK (I MAY BE THE CHICKEN BUT YOU WILL BE THE ONE SQAUWKING!)\n");
        sleep(2);
    }
    else if (strcmp(monster.name, "LORD SLIME") == 0) {
        printf("LORD SLIME: BLUB BLUB BLUB (I am LORD SLIME and I'm gonna eat you like JELLO!)\n");
        sleep(2);
        printf("D: Yah that transalation was a little fabricated I admit it.\n");
        sleep(2);
    }
    else if (strcmp(monster.name, "KING PORK") == 0) {
        printf("KING PORK: Awww look at our little hero.. How PATHETIC!\n");
        sleep(2);
        printf("KING PORK: YOU think you can come into MY DOMAIN and defeat me and save your little Princess??\n");
        sleep(2);
        printf("KING PORK: No, I think not.. I will squash you like the SLIME that you are!!!\n");
        sleep(2);
        printf("D: It's FINAL BOSS time. Use the SKILLS you have and you can beat HIM!\n");
        sleep(2);
    }
    
}

void printPlayerStats(party player, monster monster) {
    
    if (monster.magicUser) {
        printf("%s:%d/%d:%d/%d   %s:%d/%d:%d/%d\n", player.name, (int)player.hp, (int)player.maxHP, (int)player.mp, (int)player.maxMP, monster.name, monster.hp, monster.maxHP, monster.mp, monster.maxMP);
    }
    else {
        printf("%s:%d/%d:%d/%d   %s:%d/%d\n", player.name, (int)player.hp, (int)player.maxHP, (int)player.mp, (int)player.maxMP, monster.name, monster.hp, monster.maxHP);
    }
    
}


int itemsMenu(party *player, item **head, item **tail, stat *statBoosts) {
    item *temp = *head, *userItem = NULL;
    int i = 1, playerInput;
    
    printf("What item will you use?\n");
        
    while (temp != NULL) {
        printf("%d %s ", i, temp->name);
        if (strcmp(temp->name, "POTION") == 0) {
            printf("(+50%% HP)\n");
        }
        else if (strcmp(temp->name, "ANTIDOTE") == 0) {
            printf("(-POISON STATUS CONDITION)\n");
        }
        else if (strcmp(temp->name, "OINTMENT") == 0) {
            printf("(-BURN STATUS CONDITION)\n");
        }
        else if (strcmp(temp->name, "ELIXIR") == 0) {
            printf("(+50%% MP)\n");
        }
        else if (strcmp(temp->name, "X-ATTACK") == 0) {
            printf("(x1.5 ATTACK)\n");
        }
        else if (strcmp(temp->name, "X-DEFENSE") == 0) {
            printf("(x1.5 DEFENSE)\n");
        }
        else if (strcmp(temp->name, "X-SPEED") == 0) {
            printf("(x1.5 SPEED)\n");
        }
        else if (strcmp(temp->name, "X-MAGIC") == 0) {
            printf("(x1.5 MAGIC)\n");
        }
        else if (strcmp(temp->name, "X-MAGIC-DEFENSE") == 0) {
            printf("(x1.5 MAGIC DEFENSE)\n");
        }
        else if (strcmp(temp->name, "BONE") == 0) {
            printf("(Probably useful somehow. At least that's what the MERCHANT said...)\n");
        }
        else if (strcmp(temp->name, "SHARK") == 0) {
            printf("(It's a BIG FISH. How are you carrying that in your bag?)\n");
        }
        else if (strcmp(temp->name, "WALLEYE") == 0) {
            printf("(It's got a lot of MEAT on it. What, no! Of course I don't want to EAT IT!)\n");
        }
        else if (strcmp(temp->name, "MINNOW") == 0) {
            printf("(What a PATHETIC LITTLE FISH. You should probably just sell it.)\n");
        }
        else {
            printf("\n");
        }
        temp->spot = i;
        temp = temp->pt;
        i++;
    }
        
    printf("%d NEVERMIND\n", i);
        
    scanf("%d", &playerInput);
        
    if (playerInput == i) {
        return -1;
    }
        
    userItem = searchItem(*head, playerInput);
        
    if (strcmp(userItem->name, "POTION") == 0) {
        potion(player);
        deleteItem(userItem, head, tail);
    }
    else if (strcmp(userItem->name, "ANTIDOTE") == 0) {
        antidote(player);
        deleteItem(userItem, head, tail);
    }
    else if (strcmp(userItem->name, "OINTMENT") == 0) {
        ointment(player);
        deleteItem(userItem, head, tail);
    }
    else if (strcmp(userItem->name, "ELIXIR") == 0) {
        elixir(player);
        deleteItem(userItem, head, tail);
    }
    else if (strcmp(userItem->name, "X-ATTACK") == 0) {
        if (statBoosts->attackChange != 0) {
            statBoosts->attackChange *= 1.5;
            printf("%s's ATTACK ROSE!\n", player->name);
            sleep(1);
            deleteItem(userItem, head, tail);
            return 3;
        }
        else {
            printf("You can't use an X-ITEMS OUTSIDE of BATTLE!\n");
            return -1;
        }
    }
    else if (strcmp(userItem->name, "X-DEFENSE") == 0) {
        if (statBoosts->defenseChange != 0) {
            statBoosts->defenseChange *= 1.5;
            printf("%s's DEFENSE ROSE!\n", player->name);
            sleep(1);
            deleteItem(userItem, head, tail);
            return 3;
        }
        else {
            printf("You can't use an X-ITEMS OUTSIDE of BATTLE!\n");
            return -1;
        }
    }
    else if (strcmp(userItem->name, "X-SPEED") == 0) {
        if (statBoosts->speedChange != 0) {
            statBoosts->speedChange *= 1.5;
            printf("%s's SPEED ROSE!\n", player->name);
            sleep(1);
            deleteItem(userItem, head, tail);
            return 3;
        }
        else {
            printf("You can't use an X-ITEMS OUTSIDE of BATTLE!\n");
            return -1;
        }
    }
    else if (strcmp(userItem->name, "X-MAGIC") == 0) {
        if (statBoosts->magicChange != 0) {
            statBoosts->magicChange *= 1.5;
            printf("%s's MAGIC ROSE!\n", player->name);
            sleep(1);
            deleteItem(userItem, head, tail);
            return 3;
        }
        else {
            printf("You can't use an X-ITEMS OUTSIDE of BATTLE!\n");
            return -1;
        }
    }
    else if (strcmp(userItem->name, "X-MAGIC-DEFENSE") == 0) {
        if (statBoosts->magicDefenseChange != 0) {
            statBoosts->magicDefenseChange *= 1.5;
            printf("%s's MAGIC DEFENSE ROSE!\n", player->name);
            sleep(1);
            deleteItem(userItem, head, tail);
            return 3;
        }
        else {
            printf("You can't use an X-ITEMS OUTSIDE of BATTLE!\n");
            return -1;
        }
    }
    else if (strcmp(userItem->name, "BONE") == 0) {
        deleteItem(userItem, head, tail);
        return 1;
    }
    else if ((strcmp(userItem->name, "SHARK") == 0) || (strcmp(userItem->name, "WALLEYE") == 0) || (strcmp(userItem->name, "MINNOW") == 0)) {
        deleteItem(userItem, head, tail);
        return 2;
    }
    else {
        printf("You don't have any ITEMS!\n");
        sleep(1);
        return -1;
    }
        
    return 0;
    
}

void printHouse(void) {
        
    printf("        /\\   \n");
    printf("       /  \\   \n");
    printf("      /____\\   \n");
    printf(" O    |    |   \n");
    printf("/|\\   | || |   \n");
    printf("/ \\   |_||_|   \n");
    printf("You encountered a house!\n");
    sleep(1);
    
}

void printBattle(party player, monster monster) {
    
    if (strcmp(monster.name, "SLIME") == 0) {
        printf("*    O           \n");
        printf("    /|\\|--      \n");
        printf("    / \\         O\n");
        printf("D   %s       %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "WIZARD") == 0) {
        printf("*    O           \\()/  \n");
        printf("    /|\\|--        /\\ \n");
        printf("    / \\           -- \n");
        printf("D   %s          %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "SNAKE") == 0) {
        printf("*    O            _  \n");
        printf("    /|\\|--         |\n");
        printf("    / \\            -----\n");
        printf("D   %s          %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "GIANT") == 0) {
        printf("                   _______\n");
        printf("                   |     |\n");
        printf("                   |     |\n");
        printf("                   -------\n");
        printf("                      |\n");
        printf("                     /|\\\n");
        printf("                    / | \\\n");
        printf("                   /  |  \\\n");
        printf("                     / \\\n");
        printf("                    /   \\\n");
        printf("*    O             /     \\\n");
        printf("    /|\\|--        /       \\\n");
        printf("    / \\          /         \\\n");
        printf("D   %s            %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "CHICKPEE") == 0) {
        printf("*    O             \n");
        printf("    /|\\|--      <o\n");
        printf("    / \\          0 \n");
        printf("D   %s            %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        printf("                <O______ \n");
        printf("*    O           /      \\ \n");
        printf("    /|\\|--       \\      / \n");
        printf("    / \\           ------ \n");
        printf("D   %s           %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "SUPER SLIME") == 0) {
        printf("*    O           \n");
        printf("    /|\\|--      \n");
        printf("    / \\         O\n");
        printf("D   %s          %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "LORD SLIME") == 0) {
        printf("                   ______________ \n");
        printf("                  /              \\ \n");
        printf("                 |                | \n");
        printf("                 |   O        O   | \n");
        printf("                 |                | \n");
        printf("*    O           |      ____      | \n");
        printf("    /|\\|--        \\              / \n");
        printf("    / \\            --------------  \n");
        printf("D   %s              %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "ORC") == 0) {
        printf("                       ____\n");
        printf("                      |\\  /|\n");
        printf("                      | oo |\n");
        printf("                       ---- \n");
        printf("                       |  | \n");
        printf("*    O                /|__|\\ \n");
        printf("    /|\\|--        Q__/ /  \\ \\ \n");
        printf("    / \\               /    \\ \n");
        printf("D   %s             %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "ARCHER") == 0) {
        printf("                               ____\n");
        printf("                              |\\  /|\n");
        printf("                              | oo |\n");
        printf("                               ---- \n");
        printf("                           /|--|  | \n");
        printf("*    O                     \\|--|__| \n");
        printf("    /|\\|--                     /  \\ \n");
        printf("    / \\                       /    \\ \n");
        printf("D   %s                    %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "KING PORK") == 0) {
        printf("                            |\\/\\/| \n");
        printf("                          __|____|__ \n");
        printf("                         |  \\    /  | \n");
        printf("                         | ()    () | \n");
        printf("                        /|    oo    |\\ \n");
        printf("                       / |  \\____/  | \\\n");
        printf("                      /   -----------  \\\n");
        printf("                     /  |            |  \\\n");
        printf("                     |   \\          /   |\n");
        printf("                     | \\  \\        /  / |\n");
        printf("                   --    W          W    --\n");
        printf("*    O             \\  \\__            __/  /\n");
        printf("    /|\\|--          \\  \\ \\__________/ /  /\n");
        printf("    / \\            -----              -----  \n");
        printf("D   %s                  %s\n", player.name, monster.name);
    }
}

void printCompanionBattle(party player, companion companion) {
    
    printf("*    O           \n");
    printf("    /|\\|--      _|____\n");
    printf("    / \\           | | \n");
    printf("D   %s       %s\n", player.name, companion.name);
}

void printBattle2(party player, monster monster, companion companion) {
    
    if (strcmp(monster.name, "SLIME") == 0) {
        printf("*    O                       \n");
        printf("    /|\\|--  ____|_          \n");
        printf("    / \\      | |           O\n");
        printf("D   %s   %s       %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "WIZARD") == 0) {
        printf("     O                     \\()/  \n");
        printf("    /|\\|--  ____|_          /\\ \n");
        printf("    / \\      | |            -- \n");
        printf("D   %s   %s         %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "SNAKE") == 0) {
        printf("*    O                       _  \n");
        printf("    /|\\|--  ____|_            |\n");
        printf("    / \\      | |              -----\n");
        printf("D   %s   %s         %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "GIANT") == 0) {
        printf("                              _______\n");
        printf("                              |     |\n");
        printf("                              |     |\n");
        printf("                              -------\n");
        printf("                                 |\n");
        printf("                                /|\\\n");
        printf("                               / | \\\n");
        printf("                              /  |  \\\n");
        printf("                                / \\\n");
        printf("                               /   \\\n");
        printf("*    O                        /     \\\n");
        printf("    /|\\|--  ____|_           /       \\\n");
        printf("    / \\      | |            /         \\\n");
        printf("D   %s   %s            %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "CHICKPEE") == 0) {
        printf("*    O                       \n");
        printf("    /|\\|--  ____|_         <o\n");
        printf("    / \\      | |            0 \n");
        printf("D   %s   %s         %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        printf("                             <O______ \n");
        printf("*    O                        /      \\ \n");
        printf("    /|\\|--  ____|_            \\      / \n");
        printf("    / \\      | |               ------ \n");
        printf("D   %s   %s            %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "SUPER SLIME") == 0) {
        printf("*    O                       \n");
        printf("    /|\\|--  ____|_          \n");
        printf("    / \\      | |           O\n");
        printf("D   %s   %s         %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "LORD SLIME") == 0) {
        printf("                               ______________ \n");
        printf("                              /              \\ \n");
        printf("                             |                | \n");
        printf("                             |   O        O   | \n");
        printf("                             |                | \n");
        printf("*    O                       |      ____      | \n");
        printf("    /|\\|--  ____|_            \\              / \n");
        printf("    / \\      | |               --------------  \n");
        printf("D   %s   %s            %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "ORC") == 0) {
        printf("                                ____\n");
        printf("                               |\\  /|\n");
        printf("                               | oo |\n");
        printf("                                ---- \n");
        printf("                                |  | \n");
        printf("*    O                         /|__|\\ \n");
        printf("    /|\\|--  ____|_         Q__/ /  \\ \\ \n");
        printf("    / \\      | |               /    \\ \n");
        printf("D   %s   %s            %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "ARCHER") == 0) {
        printf("                                     ____\n");
        printf("                                    |\\  /|\n");
        printf("                                    | oo |\n");
        printf("                                     ---- \n");
        printf("                                 /|--|  | \n");
        printf("*    O                           \\|--|__| \n");
        printf("    /|\\|--  ____|_                   /  \\ \n");
        printf("    / \\      | |                    /    \\ \n");
        printf("D   %s   %s            %s\n", player.name, companion.name, monster.name);
    }
    else if (strcmp(monster.name, "KING PORK") == 0) {
        printf("                                         |\\/\\/| \n");
        printf("                                       __|____|__ \n");
        printf("                                      |  \\    /  | \n");
        printf("                                      | ()    () | \n");
        printf("                                     /|    oo    |\\ \n");
        printf("                                    / |  \\____/  | \\\n");
        printf("                                   /   -----------  \\\n");
        printf("                                  /  |            |  \\\n");
        printf("                                  |   \\          /   |\n");
        printf("                                  | \\  \\        /  / |\n");
        printf("                                --    W          W    --\n");
        printf("*    O                          \\  \\__            __/  /\n");
        printf("    /|\\|--  ____|_               \\  \\ \\__________/ /  /\n");
        printf("    / \\      | |                -----              -----  \n");
        printf("D   %s   %s                     %s\n", player.name, companion.name, monster.name);
    }
    
}

void printDevil(party player, companion companion) {
    
    if (companion.tamed) {
        printf("                             \\_/\n");
        printf("                             /O\\\n");
        printf("*    O                      \\/ \\/ \n");
        printf("    /|\\|--  ____|_          /   \\ \n");
        printf("    / \\      | |            -----  \n");
        printf("D   %s   %s           DEVIL\n", player.name, companion.name);
    }
    else {
        printf("                  \\_/\n");
        printf("                  /O\\\n");
        printf("*    O           \\/ \\/ \n");
        printf("    /|\\|--       /   \\ \n");
        printf("    / \\          -----  \n");
        printf("D   %s   %s           DEVIL\n", player.name, companion.name);
    }
    
}

void printFishing(party player, companion companion) {
    
    if (companion.tamed) {
        printf("\n");
        printf("        *   O |\\              \n");
        printf(" ____|_     |// \\             \n");
        printf("  | |      / \\   \\           \n");
        printf("----------------- \\           \n");
        printf("                |^^^^^^^^^^^^^   \n");
        printf(" %s D   %s\n", companion.name, player.name);
    }
    else {
        printf("\n");
        printf("*   O |\\              \n");
        printf("    |// \\             \n");
        printf("   / \\   \\           \n");
        printf("--------- \\           \n");
        printf("        |^^^^^^^^^^^^^   \n");
        printf("D  %s\n", player.name);
    }
    
}

void printRiddleMaster(party player) {
    
    printf("            ___ \n");
    printf("*   O       |?| \n");
    printf("   /|\\      /U\\\n");
    printf("   / \\      / \\\n");
    printf("D  %s  RIDDLEMASTER\n", player.name);
    
}

void printChest(void) {
    
    printf("  O     ___  \n");
    printf(" /|\\   | _ | \n");
    printf(" / \\   |___| \n");
    
}

void printVictory(void) {
    
    printf("  ___     ___\n");
    printf(" /   \\   /   \\\n");
    printf("/     \\ /     \\\n");
    printf("\\      V      /\n");
    printf(" \\           /\n");
    printf("  \\         /\n");
    printf("   \\       /\n");
    printf("    \\     /\n");
    printf("     \\   /\n");
    printf("      \\ /\n");
    printf("       V\n");
    printf("         _\n");
    printf("    O   |O|  \n");
    printf("   /|\\  /|\\ \n");
    printf("   / \\  / \\ \n");
    sleep(1);
    printf("You saved the princess!\n");
    sleep(1);
    
}

void printLose(void) {
    
    printf("GAME OVER!\n");
    printf("   ______\n");
    printf(" /        \\\n");
    printf("|  \\    /  |\n");
    printf("| ()    () |\n");
    printf("|    oo    |\n");
    printf("|  \\____/  |\n");
    printf(" \\________/\n");
    sleep(1);
    printf("KING PORK: SLEEP TIGHT LITTLE PIGGY!\n");
    sleep(1);
    
}
