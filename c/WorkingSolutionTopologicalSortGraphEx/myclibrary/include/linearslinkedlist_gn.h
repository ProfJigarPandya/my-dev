struct snode_gn
{
	struct gnode* data;
	struct snode_gn *next;
};

int insertLinearSLLFront_gn(struct snode_gn **phead, struct gnode* data);
int removeLinearSLLFront_gn(struct snode_gn **phead);
int insertLinearSLLRear_gn(struct snode_gn **phead, struct gnode* data);
int removeLinearSLLRear_gn(struct snode_gn **phead);
int traverseSLL_gn(struct snode_gn *head);
