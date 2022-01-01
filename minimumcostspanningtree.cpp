#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

struct n{
    int s;
    int d;
    int w;
    struct n* next;
};
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
struct n* head=NULL;
struct n* tail=NULL;

struct n* sort(int v1,int v2,int w)
{
    struct n* new=(struct n*)malloc(sizeof(struct n));
    new->s=v1;
    new->d=v2;
    new->w=w;
    new->next=NULL;
    if(head==NULL)
    {
       head=new;
       return head;
    }

    if(w<head->w)
    {
         new->next=head;
         tail=new;
         head=new;
    }
    else if(w>tail->w)
    {
        int flag=0;
        struct n* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->w<w && temp->w>w)
            {
                struct n* ptr=temp->next;
                temp->next=new;
                new->next=ptr;
                flag =1;
                break;
            }
            temp=temp->next;
        }
        if(!flag)
        temp->next=new;
    }
    return head;
}
void print_list(struct n* temp)
{
    while(temp)
    {
        printf("%d ",temp->w);
        temp=temp->next;
    }
}
int count=0;
int cost=0;
int find(int parent[],int i)
{
    if(parent[i]==-1)
    return i;
    else find(parent,parent[i]);
}
void print_cost(struct n* temp,graph *G)
{
    while(temp!=NULL && count<=G->v)
    {
        cost+=temp->w;
        count++;
        temp=temp->next;
    }
    printf("minimum cost of spanning tree==%d\n",cost);
}
void make_list(graph* G)
{
    int *parent=(int*)malloc(sizeof(int));
    memset(parent,-1,sizeof(int)*G->v);
    
    for(int i=0;i<G->v;i++)
    {
        struct node* temp=G->ajlist[i].head;
        if(temp){
        while(temp)
        {
           int check1=find(parent,i);
           int check2=find(parent,temp->v2-1);
           if(check1!=check2)
           {
               head=sort(i+1,temp->v2,temp->w);
               parent[temp->v2-1]=i;
           }
           temp=temp->next;
        }
            
        }
        else continue;
    }
    print_list(head);
    print_cost(head,G);
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
	print(G);
   make_list(G);
}
