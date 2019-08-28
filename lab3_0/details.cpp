#include "details.h"

Detail* read_details(FILE *f)
{
	Detail *head, *temp;
	char str[30];
	head = (Detail*)malloc(sizeof(Detail));
	head->id = INT_MIN;
	head->flag = 0;
	head->maxPath = -1;
	head->ptrNext = NULL;
	temp = head;
	while (!feof(f))
	{
		temp->ptrNext = (Detail*)malloc(sizeof(Detail));
		temp = temp->ptrNext;
		str[0] = '\0';
		fgets(str, 30, f);
		break_Line(str, temp->name, &temp->id, &temp->time);
		temp->flag = 0;
		temp->maxPath = -1;
		temp->ptrNext = NULL;
	}
	temp->ptrNext = (Detail*)malloc(sizeof(Detail));
	temp = temp->ptrNext;
	temp->id = INT_MAX;
	temp->maxPath = 0;
	temp->flag = 1;
	temp->ptrNext = NULL;
	return(head);
}
Detail* find_detail(Detail *head, int id)
{
	while (head)
	{
		if (head->id == id)
		{
			return head;
		}
		head = head->ptrNext;
	}
	return NULL;
}
void break_Line(char *str, char *name, int *id, int *time)
{
	char *s, *ss;
	const char *ct = " ";
	s = strtok_s(str, ct, &ss);
	*id = atoi(s);
	s = strtok_s(NULL, ct, &ss);
	strcpy_s(name, 20, s);
	s = strtok_s(NULL, ct, &ss);
	*time = atoi(s);
}
void print_details(Detail *head, FILE *f)
{
	fprintf_s(f, "№   название станка      нач кон\n");
	head = head->ptrNext;
	while (head->ptrNext)
	{	
		fprintf_s(f, "%03d %-20s %3d %3d\n", head->id, head->name, head->begin, head->end);	
		head = head->ptrNext;	
	}
}