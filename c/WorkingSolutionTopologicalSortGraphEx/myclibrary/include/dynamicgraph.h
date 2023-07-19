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
 int discovered;//when v is first discovered
 int finished;//when the search finishes examining v's adjacency list
};

