#include "intro.h"

int startGame(party *player, companion *companion, item **itemHead, item **itemTail, bool *hardMode) {
    
    int eventNum = 0;
    
    char yesOrNo = 'n', continues = 'n', dialogue[150];
    
    printf("*\n");
    usleep(1);
    
    strcpy(dialogue, "Hello there! Welcome to WAIT STOP\nWhy is the dialogue like this?\nLet me fix that real quick.\n");
    
    for (int i = 0; i < strlen(dialogue); i++) {
        
        printf("%c", dialogue[i]);
        usleep(100000);
        
        if (i == 22) {
            printf("...");
            usleep(100000);
        }
        
    }
    
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf("\n");
    
    printf("That's better.\n");
    sleep(1);
    
    printf("ahem\n");
    sleep(1);
    printf("Hello there! Welcome to Monsters and Maidens!\n");
    sleep(2);
    printf("I'm your GUIDE and FRIENDLY HELPER, D!\n");
    sleep(2);
    printf("What? You don't see me?? I am the little asterix at the top of the text!!!\n");
    sleep(3);
    printf("[Type c if you C ME (GET IT??)]\n");
    scanf("%c", &continues);
    while (continues != 'c') {
        printf("(Type c if you C ME)\n");
        scanf("%*c%c", &continues);
    }
    
    printf("Cool! By the way, is this your first time playing? (y/n)\n");
    scanf("%*c%c", &yesOrNo);
    while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
        printf("Type (y/n)\n");
        scanf("%*c%c", &yesOrNo);
    }
    
    if (yesOrNo == 'y') {
        instructions();
        printf("Now let's get you set up.\n");
        sleep(1);
        playerInfo(player, itemHead, itemTail);
    }
    else {
        printf("Oh, an expert are you?\n");
        sleep(1);
        eventNum = getStats(player, companion, itemHead, itemTail, eventNum);
    }
    
    printPlayer(*player, *companion);
    
    printf("Sounds good hero %s from heroville prepare to embark on this heroic journey of heroism!\n", player->name);
    sleep(2);
    
    if (player->numWins > 0) {
        printf("Would you like to play in HARD MODE? (y\\n)\n");
        scanf("%*c%c", &yesOrNo);
        while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
            printf("Type (y/n)\n");
            scanf("%*c%c", &yesOrNo);
        }
    }
    if ((player->numWins > 0) && (yesOrNo == 'y')) {
        printf("A DARING CHALLENGER, aren't we?\n");
        sleep(2);
        printf("I'll set it to HARD MODE.\n");
        *hardMode = true;
    }
    else if ((player->numWins > 0) && (yesOrNo == 'n')) {
        printf("Alright no shame in that.\n");
        sleep(2);
        printf("We'll stick to NORMAL MODE.\n");
        *hardMode = false;
    }
    sleep(2);
    
    printf("Are you ready? (y\\n)\n");
    scanf("%*c%c", &yesOrNo);
    while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
        printf("Type (y/n)\n");
        scanf("%*c%c", &yesOrNo);
    }
    if (yesOrNo == 'y') {
        printf("Great! Let's go!\n");
        sleep(1);
    }
    else if (yesOrNo == 'n') {
        printf("Too bad we're going anyway!\n");
        sleep(1);
    }
    
    return eventNum;
}

void instructions(void) {
    
    char continues = 'n';
    
    printf("Ugh, another noob. I guess I'll explain it then.\n");
    sleep(1);
    printf("This is an RPG game got it? Stands for Random People Gather.\n");
    sleep(1);
    printf("(Type g if you got it)\n");
    scanf("%*c%c", &continues);
    while (continues != 'g') {
        printf("(Type g if you got it)\n");
        scanf("%*c%c", &continues);
    }
    continues = 'n';
    
    printf("Anyways, you play the role of hero meaning you have to slay the monsters and save the princess.\n");
    sleep(2);
    printf("You will encounter a series of random events when going through your adventures.\n");
    sleep(2);
    printf("All which you will need to complete.\n");
    sleep(1);
    
    printf("During a battle you will see this screen: \n");
    sleep(1);
    printf("Player:5:5     Monster:2:0\n");
    printf("What will you do?\n");
    printf("1 Attack\n");
    printf("2 Magic\n");
    printf("3 Items\n");
    printf("4 Run Away!\n");
    printf("(This is NOT an ACTUAL BATTLE so DON'T type anything!)\n");
    sleep(4);
    
    printf("The top line tells your name with the health power (HP) and magic power (MP) you have left.\n");
    sleep(2);
    printf("It also shows the monster's name along with the HP and MP it has left.\n");
    sleep(2);
    printf("To perform an action you type the number at the front of the action you want.\n");
    sleep(2);
    printf("1 will cause you to perform a basic attack.\n");
    sleep(2);
    printf("2 will give you the option of performing a magic attack.\n");
    sleep(2);
    printf("3 will allow you to choose an item to use that you picked up during your adventure.\n");
    sleep(2);
    printf("4 will cause you to runaway giving you no experience points.\n");
    sleep(2);
    printf("[Type u if u understand (I'm SO FUNNY)]\n");
    scanf("%*c%c", &continues);
    while (continues != 'u') {
        printf("(Type u if u understand)\n");
        scanf("%*c%c", &continues);
    }
    
    printf("Anyway I'm bored with explaining. You'll learn as you go along.\n");
    sleep(2);
    
}
