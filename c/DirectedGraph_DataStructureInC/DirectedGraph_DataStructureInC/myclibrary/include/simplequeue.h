#include "linearslinkedlist.h"
struct squeue
{
	struct 	snode *front, *rear;
};

void initSQueue(struct squeue *ptrq);
int insertSQueue(struct squeue *ptrq, int data);
int deleteSQueue(struct squeue *ptrq, int *pdata);
