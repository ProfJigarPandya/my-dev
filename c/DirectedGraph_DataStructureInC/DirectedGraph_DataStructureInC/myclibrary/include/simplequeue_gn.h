struct squeue_gn
{
	struct 	snode_gn *front, *rear;
};

void initSQueue_gn(struct squeue_gn *ptrq);
int insertSQueue_gn(struct squeue_gn *ptrq, struct gnode* data);
int deleteSQueue_gn(struct squeue_gn *ptrq, struct gnode* *pdata);
int isEmptySQueue_gn(struct squeue_gn *ptrq);
