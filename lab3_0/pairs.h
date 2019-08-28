#ifndef PAIRS_H_
#define PAIRS_H_
#include "stdafx.h"
#include "details.h"

typedef struct pair
{
	int first;
	int second;
	pair *ptrNext;
} Pair;

Pair* read_pairs(FILE *, Detail *);
int check_detail(int, Pair *);
Pair * del_pair(int, Pair *);

#endif