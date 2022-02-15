
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter no of vertices"<<endl;
    int n;
    cin>>n;
    cout<<"enter no of stages"<<endl;
    int stages;
    cin>>stages;
    int t[n+1][n+1];
    int cost[n+1],d[n+1],path[stages+1];
    memset(t,0,sizeof(t));
    for(int i=1;i<n;i++)
    {
        cout<<"enter no of edges from "<<i<<endl;
        int temp;
        cin>>temp;
        int j=1;
        while(temp--)
        {
            cout<<"enter "<<j<<" edge from "<<i<<endl;
            int k;
            cin>>k;
            cout<<"cost of edge "<<i<<" and "<<k<<endl;
            cin>>t[i][k];
            j++;
        }
    }
        cost[n]=0; //cause it is the last edge so its cost is 0
        for(int i=n-1;i>=1;i--)
        {
            int min=INT_MAX;
            for(int k=i+1;k<=n;k++)
            {
                if(t[i][k]!=0 && t[i][k]+cost[k]<min)
                {
                    min=t[i][k]+cost[k];
                    d[i]=k;
                }
            }
            cost[i]=min;
        }
    for(int i=1;i<=n;i++)
    {
        cout<<cost[i]<<" "; //contains edges with minimum cost with this we need to select edges equal to stages
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<d[i]<<" "; //contains edges with minimum cost with this we need to select edges equal to stages
    }
   path[stages]=n;//destination
   path[1]=1;//starting point they will always be same we only need to select path in between of them 
   for(int i=2;i<stages;i++)
   {
       path[i]=d[path[i-1]];
   }
   cout<<endl<<"path with minimum cost in a multi stage graph is:-"<<endl;
   for(int i=1;i<=stages;i++)
   {
       cout<<path[i]<<" ";
   }
    return 0;
}
