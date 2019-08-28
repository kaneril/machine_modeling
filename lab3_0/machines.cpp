#include "machines.h"

Machine * init_machine(Detail *headD)
{
	Machine *head, *temp, *temp1;
	headD = headD->ptrNext;
	head = (Machine*)malloc(sizeof(Machine));
	head->name = headD->name;
	head->flag = TRUE;
	head->detail = NULL;
	head->list = NULL;
	head->ptrNext = NULL;
	temp = head;
	while (headD->ptrNext->ptrNext)
	{
		headD = headD->ptrNext;
		temp1 = find_machine(head, headD->name);
		if (temp1 == NULL)
		{
			temp->ptrNext = (Machine*)malloc(sizeof(Machine));
			temp = temp->ptrNext;
			temp->name = headD->name;
			temp->flag = TRUE;
			temp->detail = NULL;
			temp->list = NULL;
			temp->ptrNext = NULL;
		}
	}
	return(head);
}
Machine * find_machine(Machine *head, char *name)
{
	while (head)
	{
		if (strcmp(head->name, name) == 0)
		{
			return head;
		}
		head = head->ptrNext;
	}
	return NULL;
}
Machine * find_freeMachine(Machine *head, char *name)
{
	while (head)
	{
		if (strcmp(head->name, name) == 0)
		{
			if (head->flag == TRUE)
			{
				return head;
			}
			else
			{
				return NULL;
			}
		}
		head = head->ptrNext;
	}
	return NULL;
}
MachineList * add_detail(MachineList *head, Detail *detail)
{
	if (detail == NULL)
	{
		head = (MachineList*)malloc(sizeof(MachineList));
		head->detail = detail;
		head->ptrNext = NULL;
		return head;
	}
	else
	{
		MachineList * temp = (MachineList*)malloc(sizeof(MachineList));
		temp->detail = detail;
		temp->ptrNext = head;
		return temp;
	}	
}
void print_machine(Machine *head, FILE *f)
{
	fprintf_s(f, "название станка      нач кон №\n");
	while (head)
	{
		fprintf_s(f, "---------------------------------\n");
		print_machineList(head->list, f);
		head = head->ptrNext;
	}
}
void print_machineList(MachineList *head, FILE *f)
{
	if (head->ptrNext == NULL)
	{
		fprintf_s(f, "%-20s %3d %3d %03d\n", head->detail->name, head->detail->begin, head->detail->end, head->detail->id);
	}
	else
	{
		print_machineList(head->ptrNext, f);
		fprintf_s(f, "%24d %3d %03d\n", head->detail->begin, head->detail->end, head->detail->id);
	}
}