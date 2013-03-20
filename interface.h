#ifndef INTERFACE_H
#define INTERFACE_H
//ncurses lib inclusion
#include <ncurses.h>
#include <form.h>
#include <string.h>
#include <stdlib.h>

struct logininfo{
	char * username;
	char * password;
};

void setInterface(void);
struct logininfo * showLoginForm(void);
void unsetInterface(void);

#endif
