#include "comput.h"

void find_maxPath(Detail *headD, Pair *headP)
{
	bool flag = TRUE;
	while (flag)
	{
		flag = FALSE;
		Detail *tempD = headD;
		while (tempD)
		{
			if (tempD->flag)
			{
				flag = TRUE;
				Pair *tempP = headP;
				while (tempP)
				{
					if (tempP->second == tempD->id)
					{
						Detail *tempDet = find_detail(headD, tempP->first);
						if (tempDet->maxPath==-1)
						{
							tempDet->maxPath = tempD->maxPath + tempDet->time;
							tempDet->flag = 1;
						}
						else
						{
							tempDet->maxPath = max(tempDet->maxPath, tempD->maxPath + tempDet->time);
						}
						
					}
					tempP = tempP->ptrNext;
				}
				tempD->flag = 0;
			}
			tempD = tempD->ptrNext;
		}
	}
}
void work(Detail *headD, Pair *headP, Machine *headM)
{
	Detail *tempD;
	Machine *tempM;
	int time = 0;
	headD->flag = 3;
	headP = del_pair(headD->id, headP);
	while (headP!=NULL)
	{
		tempD = headD;
		while (tempD != NULL)
		{
			if (tempD->flag == 0)
			{
				tempD->flag = check_detail(tempD->id, headP);
			}
			if (tempD->flag == 1)
			{
				tempM = find_freeMachine(headM, tempD->name);
				if (tempM != NULL)
				{
					if ((tempM->detail == NULL) || (tempM->detail->maxPath < tempD->maxPath))
					{
						tempM->detail = tempD;
					}					
				}
			}
			tempD = tempD->ptrNext;
		}
		tempM = headM;
		int minTime = INT_MAX;
		while (tempM != NULL)
		{
			if (tempM->flag==TRUE) 
			{
				if (tempM->detail != NULL)
				{
					tempM->flag = FALSE;
					tempM->detail->flag = 2;
					tempM->detail->begin = time;
					tempM->detail->end = time + tempM->detail->time;
					tempM->list = add_detail(tempM->list, tempM->detail);
				}
			}
			if (tempM->flag != TRUE)
			{
				if (tempM->detail->end < minTime)
				{
					minTime = tempM->detail->end;
				}
			}
			tempM = tempM->ptrNext;
		}
		time = minTime;
		tempM = headM;
		while (tempM != NULL)
		{
			if (tempM->flag != TRUE)
			{
				if (tempM->detail->end <= time)
				{
					tempM->flag = TRUE;
					tempM->detail->flag = 3;
					headP = del_pair(tempM->detail->id, headP);
					tempM->detail = NULL;
				}
			}
			tempM = tempM->ptrNext;
		}		
	}
}
