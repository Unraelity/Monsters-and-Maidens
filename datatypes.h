#ifndef datatypes_h
#define datatypes_h

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define PLAYER_STATS 0
#define MONSTER_STATS 1
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
    float magic[MAX_MAGIC][2];    //Row will be magic name while Column will be power of magic
    float magicDefense;
    float attack;
    float defense;
    float speed;
    char statusCondition[10];
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
    float magic[MAX_MAGIC][2];
    int magicDefense;
    int attack;
    int defense;
    int speed;
    char statusCondition[10];
    int level;
    int goldYield;
    int expYield;
} monster;

typedef struct companion_s {
    char name[50];
    float maxHP;
    float hp;
    float attack;
    float defense;
    float speed;
    int level;
    int maxEXP;
    int exp;
    bool tamed;
} companion;

typedef struct stat_s {
    float magicChange;
    float magicDefenseChange;
    float attackChange;
    float defenseChange;
    float speedChange;
    int realMagic[2];
    int realMagicDefense;
    int realAttack;
    int realDefense;
    int realSpeed;
} stat;

#endif /* datatypes_h */
