#include "pairs.h"

Pair* read_pairs(FILE *f, Detail *headD)
{
	Pair *head, *temp;
	head = (Pair*)malloc(sizeof(Pair));
	fscanf_s(f, "%d %d", &head->first, &head->second);
	head->ptrNext = NULL;
	temp = head;
	while (!feof(f))
	{
		temp->ptrNext = (Pair*)malloc(sizeof(Pair));
		temp = temp->ptrNext;
		fscanf_s(f, "%d %d", &temp->first, &temp->second);
		temp->ptrNext = NULL;
	}
	Pair *tail = temp;
	temp = head;
	headD = headD->ptrNext;
	while (headD->ptrNext)
	{
		temp = head;
		int begin = 1;
		int end = 1;
		while (temp)
		{
			if (headD->id == temp->second)
			{
				begin = 0;
			}
			if (headD->id == temp->first)
			{
				end = 0;
			}
			temp = temp->ptrNext;
		}
		if (begin == 1)
		{
			temp = (Pair*)malloc(sizeof(Pair));
			temp->first = INT_MIN;
			temp->second = headD->id;
			temp->ptrNext = head;
			head = temp;
		}
		if (end == 1)
		{
			temp = (Pair*)malloc(sizeof(Pair));
			temp->first = headD->id;
			temp->second = INT_MAX;
			temp->ptrNext = NULL;
			tail->ptrNext = temp;
			tail = temp;
		}
		headD = headD->ptrNext;
	}
	return(head);
}
int check_detail(int id, Pair *headP)
{
	while (headP)
	{
		if (headP->second == id)
		{
			return 0;
		}
		headP = headP->ptrNext;
	}
	return 1;
}
Pair * del_pair(int id, Pair *headP)
{
	Pair *temp1 = headP;
	Pair *temp2 = headP->ptrNext;
	Pair *temp;
	while (temp2)
	{
		if (temp2->first == id)
		{
			temp = temp2;
			temp2 = temp2->ptrNext;
			temp1->ptrNext = temp2;
			free(temp);

		}
		else
		{
			temp1 = temp2;
			temp2 = temp2->ptrNext;
		}
	}
	if (headP->first == id)
	{
		if (headP->ptrNext == NULL)
		{
			free(headP);
			return NULL;
		}
		temp = headP->ptrNext;
		free(headP);
		return temp;
	}
	return headP;
}