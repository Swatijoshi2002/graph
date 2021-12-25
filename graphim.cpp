#include<stdio.h>
#include<stdlib.h>
struct node{
	int vertex;
	struct node* next;
};
struct graph{
	int num;
	struct node** adjlist;
};
struct node* createlist(int v)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->vertex=v;
	newnode->next=NULL;
	return newnode;
}
struct graph* create_graph(int vertex)
{
   struct graph *	Graph=(struct graph*)malloc(sizeof(struct graph));
  Graph->num=vertex;
  Graph->adjlist=(struct node**)malloc(vertex * sizeof(struct node**));
  for(int i=0;i<Graph->num;i++)
  {
  	Graph->adjlist[i]=NULL;
  }
  return Graph;
}
void add_edge(struct graph* graph,int s,int d)
{
	struct node* newnode=createlist(d);
	newnode->next=graph->adjlist[s];
	graph->adjlist[s]=newnode;
    newnode=createlist(s);
	newnode->next=graph->adjlist[d];

		graph->adjlist[d]=newnode;	
}
void print(struct graph * graph)
{
	for(int i=0;i<graph->num;i++)
	{
	struct node* temp=graph->adjlist[i];
	printf("%d =",i);
	while(temp)
	{
		printf("%d ",temp->vertex);
		temp=temp->next;
		}
		printf("\n");	
	}
}
int main()
{
	int vertex;
	printf("enter no of vertex\n");
	scanf("%d",&vertex);
   struct graph* Graph=create_graph(vertex);
     while(1)
     {
     	int n;
     	scanf("%d",&n);
     	if(n==1)
     	{
     	printf("enter edges\n");
     	int v,e;
     	scanf("%d%d",&v,&e);
     	add_edge(Graph,v,e);
        }  
     else break;
	 }
	 print(Graph);
}
