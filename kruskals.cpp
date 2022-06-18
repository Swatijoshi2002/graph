

#include <bits/stdc++.h>
using namespace std;
struct node{
    int parent;
    int rank;
};
struct Edge{
    int u,v,wt;
};

vector<node> dsuf;
vector<Edge>mst;

int find(int v)
{
    if(dsuf[v].parent==-1)
    return v;
    return dsuf[v].parent=find(dsuf[v].parent);
}

void union_list(int f,int s)
{
    if(dsuf[f].rank>dsuf[s].rank)
    {
        dsuf[s].parent=f;
    }
    else if(dsuf[f].rank<dsuf[s].rank)
    {
        dsuf[f].parent=s;
    }
    else{
        dsuf[f].parent=s;
        dsuf[s].rank+=1;
        
    }
}

bool comparator(Edge a,Edge b)
{
    return a.wt<b.wt;
}
void kruskals(vector<Edge>&edge_list,int v ,int e)
{
    sort(edge_list.begin(),edge_list.end(),comparator);
    int i=0,j=0;
    while(i<(v-1) && j<e)
    {
        int f=find(edge_list[j].u);
        int s=find(edge_list[j].v);
        if(f==s)
        {
            j++;
            continue;
        }
        else
        union_list(f,s);
        mst.push_back(edge_list[j]);
        i++;
    }
    
}
int main()
{
    int v,e;
    cin>>v>>e;
    dsuf.resize(v);
    for(int i=0;i<v;i++)
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }
    vector<Edge>edge_list;
    
    for(int i=0;i<e;i++)
    {
        Edge temp;
        int x,y,w;
        cin>>x>>y>>w;
        temp.u=x;
        temp.v=y;
        temp.wt=w;
        edge_list.push_back(temp);
    }
    kruskals(edge_list,v,e);
    //print_mst(mst);
    for(int i=0;i<mst.size();i++)
    {
        cout<<mst[i].wt<<" ";
    }
}
