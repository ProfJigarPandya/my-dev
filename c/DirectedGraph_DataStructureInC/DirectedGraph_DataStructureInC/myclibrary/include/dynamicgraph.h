struct gnode;
struct edge
{
 struct gnode* dnptr;
 int weight;
 struct edge* nextedge;
};

struct gnode
{
 struct edge *edgelist;
 char nodeno[128];
 int visited;//0-not, 1-yes
 struct gnode *nextnode;
};

