
#include <stdio.h>
struct node{
    int data;
    int weight;
    int next;
};
int main()
{ 
    struct node* arr[10]=NULL;
    while(1)
    { 
        int n;
        scanf("%d",&n);
        printf("enter 1 to add edge\n 0 to end the graph\n");
        scanf("%d",&n);
        if(n==1)
        {
    printf("enter first edge\n");
    int v;
    int e;
    scanf("%d",&v);
    if(arr[v]==NULL)
    {
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        printf("enter second edge and weight\n");
        scanf("%d",&e);
        int w;
        scanf("%d",&w);
        temp->data=e;
        temp->weight=w;
        temp->next=NULL;
    }
        }
        else break;
    
}

