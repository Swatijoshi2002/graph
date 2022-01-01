#include<stdio.h>
#include<stdlib.h>
struct node{
	int v2;
	int w;
	struct node* next;
	struct vertex* ori;
};
typedef struct vertex{
	int v1;
   struct node *head;
}v;
typedef struct graph{
	int v;
	struct vertex* ajlist;
}graph;
graph* create_graph()
 {
 	graph *G=(graph*)malloc(sizeof(graph));
 	printf("enter no of vertex\n");
 	scanf("%d",&G->v);
 	G->ajlist=(v*)malloc(G->v*sizeof(v));
 	for(int i=0;i<G->v;i++)
 	{
 		printf("enter data for %d verex \n",i+1);
 		scanf("%d",&G->ajlist[i].v1);
 		G->ajlist[i].head=NULL;   
 	}
 	return G;
 }
 graph* add_connection(graph* G,int s,int d,int w){
 	
 	struct node *newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->v2=G->ajlist[d-1].v1;
 	newnode->w=w;
 	newnode->ori=&(G->ajlist[d-1]);
 	newnode->next=G->ajlist[s-1].head;
 	G->ajlist[s-1].head=newnode;
 	return G;
 }
void print(graph* G)
{
	for(int i=0;i<G->v;i++)
	{
		struct node*temp=G->ajlist[i].head;
		printf("connetions of %d=",G->ajlist[i].v1);
		while(temp)
		{
			printf("%d ",temp->v2);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()
{
	graph *G;
	G=create_graph();
	while(1)
	{
		int n;
		printf("enter 1 to add connection and 0 to end graph\n");
		scanf("%d",&n);
		if(n==0)
		break;
		else
		{
			printf("enter edges and weight\n");
			int s,d,w;
			scanf("%d%d%d",&s,&d,&w);
			G=add_connection(G,s,d,w);
		}
	}
	//make_list(G);
	print(G);
}
