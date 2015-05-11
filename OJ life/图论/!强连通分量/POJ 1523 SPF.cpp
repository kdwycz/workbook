#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1001;
int edge[N][N];
int vis[N];
int dfn[N],low[N];
int nodes,dindex,son;
int subnets[N];

void init(){
    low[1]=dfn[1]=1;
    dindex=1; son=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    memset(subnets,0,sizeof(subnets));
}

void dfs(int u){
    for (int v=1;v<=nodes;++v){
        if (edge[u][v]){
            if (!vis[v]){
                vis[v]=1;
                dfn[v]=low[v]=++dindex;
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v]>=dfn[u]){
                    if (u!=1) subnets[u]++;
                    if (u==1) son++;
                }
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    int i,u,v,find,num=1;
    while(1){
        cin>>u;
        if (u==0) break;
        memset(edge,0,sizeof(edge));
        nodes=0;
        cin>>v;
        while (1){
            if (u>nodes) nodes=u;
            if (v>nodes) nodes=v;
            edge[u][v]=edge[v][u]=1;
            cin>>u;
            if (u==0) break;
            cin>>v;
        }
        if (num>1) cout<<endl;
        cout<<"NetWork #"<<num++<<'\n';
        init();
        dfs(1);
        if (son>1) subnets[1]=son-1;
        find=0;
        for (i=1;i<=nodes;++i)
            if(subnets[i]){
                find=1;
                cout<<"  SPF node "<<i<<" leaves "<<subnets[i]+1<<" subnets\n";
            }
        if (!find) cout<<"  No SPF nodes\n";
    }
    return 0;
}
