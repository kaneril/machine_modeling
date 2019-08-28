#ifndef DETAILS_H_
#define DETAILS_H_
#include "stdafx.h"

typedef struct detail
{
	int id;
	char name[20];
	int time;
	int flag; //0-����������, 1-��������, 2-�����������, 3-������ 
	int maxPath;
	int begin;
	int end;
	detail *ptrNext;
} Detail;

Detail* find_detail(Detail *, int);
Detail* read_details(FILE *);
void break_Line(char *, char *, int *, int *);
void print_details(Detail *, FILE *);

#endif