#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    //int weight;
    struct node* next;
};
int main()
{ 
    struct node* arr[10]={NULL};
    while(1)
    { 
        int n;
        printf("enter 1 to add edge\n 0 to end the graph\n");
        scanf("%d",&n);
        if(n==1)
        {
    printf("enter first edge\n");
    int v;
    int e;
    scanf("%d",&v);
      printf("enter second edge and weight\n");
        scanf("%d",&e);
       // int w;
       // scanf("%d",&w);
     struct node*temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
      //  temp->weight=w;
        temp->next=NULL;
    if(arr[v]==NULL)
    {
        arr[v]=temp;
    }
    else {temp->next=arr[v];
        arr[v]=temp;
       }
        }
         else break;
    }
    
for(int i=0;i<10;i++)
{
    struct node* temp=arr[i];
    if(temp==NULL)
    continue;
    else{
    printf("edge through %d=",i);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
    
}
}
