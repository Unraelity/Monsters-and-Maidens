#include "fishing.h"

int goneFishing(party *player, companion companion, item **head, item **tail) {
    
    char fishingRod = 'n';
    int fishingTime = (rand() % 7) + 1;
    
    printFishing(*player, companion);
    
    printf("What a peaceful place to fish.\n");
    sleep(1);
    
    while (fishingRod != 'c') {
        printf("(Press c to recast)\n");
        scanf("%*c%c", &fishingRod);
    }
    
    printf(".");
    
    for (int i = 1; i <= fishingTime; i++) {
        
        sleep(1);
        printf(".");
        
    }
    
    sleep(1);
    
    if (fishingTime == 7) {
        
        printf("\n");
        printf("Aw, looks like there is no bites today.\n");
        return 1;
        
    }
    
    printf("!\n");
    
    printf("Press r to reel!\n");
    scanf("%*c%c", &fishingRod);
    
    if (fishingRod == 'r') {
        
        item fish;
        printf("You caught a ");
        
        fishingTime = rand() % 5;
        
        if (fishingTime == 4) {
            printf("SHARK!\n");
            strcpy(fish.name, "SHARK");
            addItem(player, &fish, head, tail);
        }
        else if (fishingTime == 0) {
            printf("WALLEYE!\n");
            strcpy(fish.name, "WALLEYE");
            addItem(player, &fish, head, tail);
        }
        else {
            printf("MINNOW!\n");
            strcpy(fish.name, "MINNOW");
            addItem(player, &fish, head, tail);
        }
    }
    else {
        printf("It got AWAY!\n");
    }
    
    sleep(1);
    printf("Well, that was fun. Let's head back.\n");
    sleep(1);
    
    return 1;
    
}
