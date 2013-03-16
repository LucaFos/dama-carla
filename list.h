#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "auth.h"

/*
#define llist(t) struct lnode_t { \
	t * value; \
	lnode_t * next; \
};
*/

union data{
	struct user * u;
	struct game * g; //TODO: define
};

struct lnode {
	union data * d;
	struct lnode * next;
};

struct llist{
	struct lnode * first;
};

struct llist * createList(void);
void appendUserNode(struct llist * l, struct user * u1);
struct lnode * getLastNode(struct llist * l, struct lnode * n);
struct user * getUserFromKey(struct llist * l, char * key);
struct user * getUserFromKeyEngine(char * key, struct lnode * n);


#endif
