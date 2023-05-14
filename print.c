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
        printf("Player: \n");
    }
    printf("Level: %d \n", player.level);
    printf("EXP: %d/%d \n", player.exp, player.maxEXP);
    printf("HP: %d \n", player.maxHP);
    printf("MP: %d \n", player.maxMP);
    printf("Attack: %d \n", player.attack);
    printf("Defense: %d \n", player.defense);
    printf("Speed: %d \n", player.speed);
    printf("Magic Defense: %d \n", player.magicDefense);
    printf("Gold: %dG \n", player.gold);
    
    if (companion.tamed) {
        printf("\n");
        printf("Companion: \n");
        printf("Level: %d \n", companion.level);
        printf("EXP: %d/%d \n", companion.exp, companion.maxEXP);
        printf("HP: %d \n", companion.maxHP);
        printf("Attack: %d\n", companion.attack);
        printf("Speed: %d \n", companion.speed);
    }
    
    sleep(3);
    
}

void printShop(party player) {
    
    printf("  O        O \n");
    printf(" /|\\     /( )\\\n");
    printf(" / \\      / \\\n");
    printf(" %s   MERCHANT\n", player.name);
    
}

int battleMenu(void) {
    
    int playerChoice;
    
    printf("What will you do?\n");
    printf("1 ATTACK\n");
    printf("2 MAGIC\n");
    printf("3 ITEMS\n");
    printf("4 RUN AWAY\n");
    
    scanf("%d", &playerChoice);
    
    while ((playerChoice > 4) || (playerChoice < 1)) {
        printf("That's not an option\n");
        printf("What will you do?\n");
        scanf("%d", &playerChoice);
    }
    
    return playerChoice;
}

int magicMenu(party *player, monster *monster, int turn) {
    
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
    
    if ((playerInput == healPlacement) && (player->mp >= 2)) {
        return 1;
    }
    else if ((playerInput == firePlacement) && (player->mp >= 3)) {
        return 2;
    }
    else if ((playerInput == shieldPlacement) && (player->mp >= 1)) {
        shield(player, monster, turn);
        return 0;
    }
    else if ((playerInput == lock[0]) || (playerInput == lock[1]) || (playerInput == lock[2])) {
        printf("Can't you read? It's LOCKED!\n");
        return 0;
    }
    else if (playerInput == i+1) {
        return 0;
    }
    else {
        printf("You don't have enough MP!\n");
        return 0;
    }
    
    return true;
    
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
        printf("%s:%d/%d:%d/%d   %s:%d/%d:%d/%d\n", player.name, player.hp, player.maxHP, player.mp, player.maxMP, monster.name, monster.hp, monster.maxHP, monster.mp, monster.maxMP);
    }
    else {
        printf("%s:%d/%d:%d/%d   %s:%d/%d\n", player.name, player.hp, player.maxHP, player.mp, player.maxMP, monster.name, monster.hp, monster.maxHP);
    }
    
}


int itemsMenu(party *player, item **head, item **tail) {
    item *temp = *head, *userItem = NULL;
    int i = 1, playerInput;
    
    printf("What item will you use?\n");
        
    while (temp != NULL) {
        printf("%d %s ", i, temp->name);
        if (strcmp(temp->name, "POTION") == 0) {
            printf("(+50%% HP)\n");
        }
        else if (strcmp(temp->name, "ELIXIR") == 0) {
            printf("(+50%% MP)\n");
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
    else if (strcmp(userItem->name, "ELIXIR") == 0) {
        elixir(player);
        deleteItem(userItem, head, tail);
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
        printf("D   %s    %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "WIZARD") == 0) {
        printf("*    O           \\()/  \n");
        printf("    /|\\|--        /\\ \n");
        printf("    / \\           -- \n");
        printf("D   %s       %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "SNAKE") == 0) {
        printf("*    O            _  \n");
        printf("    /|\\|--         |\n");
        printf("    / \\            -----\n");
        printf("D   %s       %s\n", player.name, monster.name);
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
        printf("D   %s         %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "CHICKPEE") == 0) {
        printf("*    O             \n");
        printf("    /|\\|--      <o\n");
        printf("    / \\          0 \n");
        printf("D   %s         %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "MEGA CHICKEN") == 0) {
        printf("                <O______ \n");
        printf("*    O           /      \\ \n");
        printf("    /|\\|--       \\      / \n");
        printf("    / \\           ------ \n");
        printf("D   %s        %s\n", player.name, monster.name);
    }
    else if (strcmp(monster.name, "SUPER SLIME") == 0) {
        printf("*    O           \n");
        printf("    /|\\|--      \n");
        printf("    / \\         O\n");
        printf("D   %s       %s\n", player.name, monster.name);
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
        printf("D   %s        %s\n", player.name, monster.name);
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
        printf("D   %s        %s\n", player.name, monster.name);
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
        printf("D   %s        %s\n", player.name, monster.name);
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
        printf("D   %s               %s\n", player.name, monster.name);
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
    printf("Thanks for playing!\n");
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
