#include <iostream>
using namespace std;
bool dfs(int vertex,int**edges,int *visited,int parent,int v)
{
    visited[vertex]=true;
    for(int i=0;i<v;i++)
    {
        if(edges[vertex][i]==true)
        {
            if(!(visited[i]))
            {
                if(dfs(i,edges,visited,vertex,v))
                return true;
            }
            else if(parent!=i)
            return false;
        }
    }
    return false;
}
bool has_loop(int**edges,int v)
{
    int visited=new int[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<v;i++)
    {
        if(!(visited[i]))
        {
            if(dfs(i,edges,visited,-1,v))
            return true;
        }
    }
    return false;
}
int main()
{
  int n,e;
  cin>>n;
  int ** edges=new int*[n];
  for(int i=0;i<n;i++)
  {
      edges[i]=new int[n];
      for(int j=0;j<n;j++)
      {
          edges[i][j]=0;
      }
  }
  cout<<"enter edges"<<endl;
  for(int i=0;i<e;i++)
  {
      int f,s;
      cin>>f>>s;
      edges[f][s]=1;
      edges[s][f]=1;
  }
  bool detect=has_loop(edges,n);
  if(detect)
  cout<<"loop is detected";
  else cout<<"no loop is present";
}
