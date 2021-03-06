#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "structs.h"

struct llist * createList(void);
void appendUserNode(struct llist * l, struct user * u1);
struct lnode * getLastNode(struct llist * l, struct lnode * n);
struct user * getUserFromKey(struct llist * l, char * key);
struct user * getUserFromKeyEngine(char * key, struct lnode * n);
void deleteUserNode(struct llist * l, char * key);
void deleteUserNodeEngine(char * key, struct lnode * n, struct lnode * previous, struct llist * list);
void appendGameNode(struct llist * l, struct game * g1);
struct game * getGameFromKey(struct llist * l, char * key);
struct game * getGameFromKeyEngine(char * key, struct lnode * n);
void deleteGameNode(struct llist * l, char * key);
void deleteGameNodeEngine(char * key, struct lnode * n, struct lnode * previous, struct llist * list);
struct game * getGameFromPlayer(struct llist * l, char * key);
struct game * getGameFromPlayerEngine(char * key, struct lnode * n);


#endif
