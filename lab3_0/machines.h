#ifndef MACHINES_H_
#define MACHINES_H_
#include "stdafx.h"
#include "details.h"

typedef struct machineList
{
	Detail *detail;
	machineList *ptrNext;
} MachineList;

typedef struct machine
{
	char *name;
	bool flag;
	machine *ptrNext;
	Detail *detail;
	MachineList *list;
} Machine;

Machine * init_machine(Detail *);
Machine * find_machine(Machine *, char *);
Machine * find_freeMachine(Machine *, char *);
MachineList * add_detail(MachineList *, Detail *);
void print_machine(Machine *, FILE *);
void print_machineList(MachineList *, FILE *);

#endif
