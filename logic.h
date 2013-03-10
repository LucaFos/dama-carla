/*
 * In this file are container the game logic structure such as boards,
 * as well as function prototypes of "logic.c"
 */
#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>


//data board values:
//	0	: empty
//	1   : white checker (pedina)
//	3   : black checker (pedina)
//	2   : white dama
//	4   : black dama
struct board{
	int data[8][8];
};

int nextMove( struct board * b, int i, int j, int k, int l, int m );
void prepareBoard( struct board * b );
void printBoard( struct board * b );
void setAllBoardEmpty( struct board * b );
int canMove ( struct board * b, int m);
int canWhiteMove( struct board * b, int i, int j );
int canWhiteCapt( struct board * b, int i, int j );
int canBlackMove( struct board * b, int i, int j );
int canBlackCapt( struct board * b, int i, int j );
int canWkingMove( struct board * b, int i, int j );
int canWkingCapt( struct board * b, int i, int j );
int canBkingMove( struct board * b, int i, int j );
int canBkingCapt( struct board * b, int i, int j );
int move( struct board *b, int i, int j, int k, int l);
int capture( struct board *b, int i, int j, int k, int l);
void changeBoard( struct board * b, int i, int j,int c);



#endif
