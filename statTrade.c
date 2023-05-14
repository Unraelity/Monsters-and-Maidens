#include "statTrade.h"

int dealWithDevil(party *player, companion companion, int *timesTraded) {

    printDevil(*player, companion);
    int tradeNum = 0, statNum1 = 0, statNum2 = 0;
    bool successfulOffer = false;
    char yesOrNo = 'c';
    
    sleep(1);
    if (*timesTraded == 0) {
        printf("DEVIL: Pleased to meet you. Hope you guess MY NAME.\n");
    }
    else {
        printf("DEVIL: YOU again? It seems you just can't STAY AWAY.\n");
    }
    sleep(1);
    printf("DEVIL: How would like to trade ");
    
    (*timesTraded)++;
    
    while (successfulOffer != true) {
        
        tradeNum = rand() % 30;
        statNum1 = (rand() % 3) + 1;
        statNum2 = (rand() % 3) + 1;
        
        switch(tradeNum) {
            case 0:
                if ((player->defense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d ATTACK for -%d DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 1:
                if ((player->magicDefense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d ATTACK for +%d MAGIC DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 2:
                if ((player->speed - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d ATTACK for -%d SPEED?\n", statNum1, statNum2);
                }
                break;
            case 3:
                if ((player->maxHP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d ATTACK for -%d MAX HP?\n", statNum1, statNum2);
                }
                break;
            case 4:
                if ((player->maxMP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d ATTACK for -%d MAX MP?\n", statNum1, statNum2);
                }
                break;
            case 5:
                if ((player->attack - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d DEFENSE for -%d ATTACK?\n", statNum1, statNum2);
                }
                break;
            case 6:
                if ((player->magicDefense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d DEFENSE for +%d MAGIC DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 7:
                if ((player->speed - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d DEFNSE for -%d SPEED?\n", statNum1, statNum2);
                }
                break;
            case 8:
                if ((player->maxHP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d DEFNSE for -%d MAX HP?\n", statNum1, statNum2);
                }
                break;
            case 9:
                if ((player->maxMP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d DEFENSE for -%d MAX MP?\n", statNum1, statNum2);
                }
                break;
            case 10:
                if ((player->attack - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAGIC DEFNSE for -%d ATTACK?\n", statNum1, statNum2);
                }
                break;
            case 11:
                if ((player->defense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAGIC DEFENSE for -%d DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 12:
                if ((player->speed - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAGIC DEFENSE for -%d SPEED?\n", statNum1, statNum2);
                }
                break;
            case 13:
                if ((player->maxHP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAGIC DEFENSE for -%d MAX HP?\n", statNum1, statNum2);
                }
                break;
            case 14:
                if ((player->maxMP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAGIC DEFENSE for -%d MAX MP?\n", statNum1, statNum2);
                }
                break;
            case 15:
                if ((player->attack - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d SPEED for -%d ATTACK?\n", statNum1, statNum2);
                }
                break;
            case 16:
                if ((player->defense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d SPEED for -%d DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 17:
                if ((player->magicDefense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d SPEED for -%d MAGIC DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 18:
                if ((player->maxHP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d SPEED for -%d MAX HP?\n", statNum1, statNum2);
                }
                break;
            case 19:
                if ((player->maxMP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d SPEED for -%d MAX MP?\n", statNum1, statNum2);
                }
                break;
            case 20:
                if ((player->attack - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX HP for -%d ATTACK?\n", statNum1, statNum2);
                }
                break;
            case 21:
                if ((player->defense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX HP for -%d DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 22:
                if ((player->magicDefense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX HP for -%d MAGIC DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 23:
                if ((player->speed - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX HP for -%d SPEED?\n", statNum1, statNum2);
                }
                break;
            case 24:
                if ((player->maxMP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX HP for -%d MAX MP?\n", statNum1, statNum2);
                }
                break;
            case 25:
                if ((player->attack - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX MP for -%d ATTACK?\n", statNum1, statNum2);
                }
                break;
            case 26:
                if ((player->defense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX MP for -%d DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 27:
                if ((player->magicDefense - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX MP for -%d MAGIC DEFENSE?\n", statNum1, statNum2);
                }
                break;
            case 28:
                if ((player->speed - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX MP for -%d SPEED?\n", statNum1, statNum2);
                }
                break;
            case 29:
                if ((player->maxHP - statNum2) >= 0) {
                    successfulOffer = true;
                    printf("+%d MAX MP for -%d MAX HP?\n", statNum1, statNum2);
                }
                break;
            default:
                successfulOffer = false;
        }
    }
    
    usleep(100000);
    printf("(Type y\\n)\n");
    
    while ((yesOrNo != 'y') && (yesOrNo != 'n')) {
        scanf("%*c%c", &yesOrNo);
    }
    
    if (yesOrNo == 'n') {
        printf("DEVIL: Fine. I would never need your weakling stats anyway.\n");
        sleep(1);
        return 1;
    }
    
    sleep(1);
    printf("DEVIL: Thank you for your business, hehe.\n");
    usleep(100000);
    
    switch(tradeNum) {
        case 0:
            player->attack += statNum1;
            printf("You GAINED %d ATTACK!\n", statNum1);
            player->defense -= statNum2;
            usleep(100000);
            printf("You LOST %d DEFENSE!\n", statNum2);
            break;
        case 1:
            player->attack += statNum1;
            printf("You GAINED %d ATTACK!\n", statNum1);
            player->magicDefense -= statNum2;
            usleep(100000);
            printf("You LOST %d MAGIC DEFENSE!\n", statNum2);
            break;
        case 2:
            player->attack += statNum1;
            printf("You GAINED %d ATTACK!\n", statNum1);
            player->speed -= statNum2;
            usleep(100000);
            printf("You LOST %d SPEED!\n", statNum2);
            break;
        case 3:
            player->attack += statNum1;
            printf("You GAINED %d ATTACK!\n", statNum1);
            player->maxHP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX HP!\n", statNum2);
            break;
        case 4:
            player->attack += statNum1;
            printf("You GAINED %d ATTACK!\n", statNum1);
            player->maxMP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX MP!\n", statNum2);
            break;
        case 5:
            player->defense += statNum1;
            printf("You GAINED %d DEFENSE!\n", statNum1);
            player->attack -= statNum2;
            usleep(100000);
            printf("You LOST %d ATTACK!\n", statNum2);
            break;
        case 6:
            player->defense += statNum1;
            printf("You GAINED %d DEFENSE!\n", statNum1);
            player->magicDefense -= statNum2;
            usleep(100000);
            printf("You LOST %d MAGIC DEFENSE!\n", statNum2);
            break;
        case 7:
            player->defense += statNum1;
            printf("You GAINED %d DEFENSE!\n", statNum1);
            player->speed -= statNum2;
            usleep(100000);
            printf("You LOST %d SPEED!\n", statNum2);
            break;
        case 8:
            player->defense += statNum1;
            printf("You GAINED %d DEFENSE!\n", statNum1);
            player->maxHP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX HP!\n", statNum2);
            break;
        case 9:
            player->defense += statNum1;
            printf("You GAINED %d DEFENSE!\n", statNum1);
            player->maxMP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX MP!\n", statNum2);
            break;
        case 10:
            player->magicDefense += statNum1;
            printf("You GAINED %d MAGIC DEFENSE!\n", statNum1);
            player->attack -= statNum2;
            usleep(100000);
            printf("You LOST %d ATTACK!\n", statNum2);
            break;
        case 11:
            player->magicDefense += statNum1;
            printf("You GAINED %d MAGIC DEFENSE!\n", statNum1);
            player->defense -= statNum2;
            usleep(100000);
            printf("You LOST %d DEFENSE!\n", statNum2);
            break;
        case 12:
            player->magicDefense += statNum1;
            printf("You GAINED %d MAGIC DEFENSE!\n", statNum1);
            player->speed -= statNum2;
            usleep(100000);
            printf("You LOST %d SPEED!\n", statNum2);
            break;
        case 13:
            player->magicDefense += statNum1;
            printf("You GAINED %d MAGIC DEFENSE!\n", statNum1);
            player->maxHP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX HP!\n", statNum2);
            break;
        case 14:
            player->magicDefense += statNum1;
            printf("You GAINED %d MAGIC DEFENSE!\n", statNum1);
            player->maxMP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX MP!\n", statNum2);
            break;
        case 15:
            player->speed += statNum1;
            printf("You GAINED %d SPEED!\n", statNum1);
            player->attack -= statNum2;
            usleep(100000);
            printf("You LOST %d ATTACK!\n", statNum2);
            break;
        case 16:
            player->speed += statNum1;
            printf("You GAINED %d SPEED!\n", statNum1);
            player->defense -= statNum2;
            usleep(100000);
            printf("You LOST %d DEFENSE!\n", statNum2);
            break;
        case 17:
            player->speed += statNum1;
            printf("You GAINED %d SPEED!\n", statNum1);
            player->magicDefense -= statNum2;
            usleep(100000);
            printf("You LOST %d MAGIC DEFENSE!\n", statNum2);
            break;
        case 18:
            player->speed += statNum1;
            printf("You GAINED %d SPEED!\n", statNum1);
            player->maxHP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX HP!\n", statNum2);
            break;
        case 19:
            player->speed += statNum1;
            printf("You GAINED %d SPEED!\n", statNum1);
            player->maxMP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX MP!\n", statNum2);
            break;
        case 20:
            player->maxHP += statNum1;
            printf("You GAINED %d MAX HP!\n", statNum1);
            player->attack -= statNum2;
            usleep(100000);
            printf("You LOST %d ATTACK!\n", statNum2);
            break;
        case 21:
            player->maxHP += statNum1;
            printf("You GAINED %d MAX HP!\n", statNum1);
            player->defense -= statNum2;
            usleep(100000);
            printf("You LOST %d DEFENSE!\n", statNum2);
            break;
        case 22:
            player->maxHP += statNum1;
            printf("You GAINED %d MAX HP!\n", statNum1);
            player->magicDefense -= statNum2;
            usleep(100000);
            printf("You LOST %d MAGIC DEFENSE!\n", statNum2);
            break;
        case 23:
            player->maxHP += statNum1;
            printf("You GAINED %d MAX HP!\n", statNum1);
            player->speed -= statNum2;
            usleep(100000);
            printf("You LOST %d SPEED!\n", statNum2);
            break;
        case 24:
            player->maxHP += statNum1;
            printf("You GAINED %d MAX HP!\n", statNum1);
            player->maxMP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX MP!\n", statNum2);
            break;
        case 25:
            player->maxMP += statNum1;
            printf("You GAINED %d MAX MP!\n", statNum1);
            player->attack -= statNum2;
            usleep(100000);
            printf("You LOST %d ATTACK!\n", statNum2);
            break;
        case 26:
            player->maxMP += statNum1;
            printf("You GAINED %d MAX MP!\n", statNum1);
            player->defense -= statNum2;
            usleep(100000);
            printf("You LOST %d DEFENSE!\n", statNum2);
            break;
        case 27:
            player->maxMP += statNum1;
            printf("You GAINED %d MAX MP!\n", statNum1);
            player->magicDefense -= statNum2;
            usleep(100000);
            printf("You LOST %d MAGIC DEFENSE!\n", statNum2);
            break;
        case 28:
            player->maxMP += statNum1;
            printf("You GAINED %d MAX MP!\n", statNum1);
            player->speed -= statNum2;
            usleep(100000);
            printf("You LOST %d SPEED!\n", statNum2);
            break;
        case 29:
            player->maxMP += statNum1;
            printf("You GAINED %d MAX MP!\n", statNum1);
            player->maxHP -= statNum2;
            usleep(100000);
            printf("You LOST %d MAX HP!\n", statNum2);
            break;
        default:
            printf("No STATS were changed.\n");
    }
    
    sleep(1);
    return 1;
    
}
