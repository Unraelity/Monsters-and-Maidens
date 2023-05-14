#ifndef datatypes_h
#define datatypes_h

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define HEAL 0
#define FIRE 1
#define SHIELD 2
#define LOCKED 3
#define MAX_MAGIC 3
#define ENDGAME 20

typedef struct party_s {
    char name[50];
    int maxHP;
    int hp;
    int maxMP;
    int mp;
    int magic[MAX_MAGIC][2];    //Row will be magic name while Column will be power of magic
    int magicDefense;
    int attack;
    int defense;
    int speed;
    int gold;
    int maxEXP;
    int exp;
    int level;
    int numWins;
    int numLosses;
    struct party_s *pt;
} party;

typedef struct item_s {
    char name[20];
    int spot;
    struct item_s *pt;
} item;

typedef struct monster_s {
    char name[20];
    bool magicUser;
    bool boss;
    bool longDistance;
    int maxHP;
    int hp;
    int maxMP;
    int mp;
    int magic[MAX_MAGIC][2];
    int magicDefense;
    int attack;
    int defense;
    int speed;
    int level;
    int goldYield;
    int expYield;
} monster;

typedef struct companion_s {
    char name[50];
    int maxHP;
    int hp;
    int attack;
    int defense;
    int speed;
    int level;
    int maxEXP;
    int exp;
    bool tamed;
} companion;

#endif /* datatypes_h */
