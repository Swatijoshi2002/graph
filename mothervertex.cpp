#include <bits/stdc++.h>
using namespace std;
 stack<int>s;
 int c=0;
 void dfs(int ** graph,bool visited2[],int src,int v)
 {
     visited2[src]=true;
     c++;
     for(int i=0;i<v;i++)
     {
         if(graph[src][i]==1)
         {
             if(visited2[i]==false)
             {
                 dfs(graph,visited2,i,v);
             }
         }
     }
 }
 void random_dfs(int **graph,bool visited[],int src,int v)
 {
     visited[src]=true;
     for(int i=0;i<v;i++)
     {
         if(graph[src][i]==1)
         {
             if(visited[i]==false)
             {
                 random_dfs(graph,visited,i,v);
             }
         }
     }
     cout<<src<<" ";
     s.push(src);
 }
int mother_vertex(int**graph,bool visited[],int v)
{
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            random_dfs(graph,visited,i,v);
        }
    }
    int res=s.top();
    bool visited2[v];
    for(int i=0;i<v;i++)
    {
        visited2[i]=false;
    }
    dfs(graph,visited2,res,v);
    if(c==v)
    return res;
    else return -1;
}
int main()
{
    int v,e;
    cout<<"enter no of vertices and edges";
    cin>>v>>e;
    int **graph=new int*[v];
    for(int i=0;i<v;i++)
    {
        graph[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            graph[i][j]=0;
        }
    }
    cout<<"enter edges"<<endl;
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
    }
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    int ans=mother_vertex(graph,visited,v);
    if(ans==-1)
    cout<<"no mother vertex"<<endl;
    else cout<<"mother vertex of given graph is "<<ans<<endl;
}
