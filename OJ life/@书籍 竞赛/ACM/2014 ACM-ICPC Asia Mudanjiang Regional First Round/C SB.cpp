c

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
const int M = 200010;

int head[N],point[N],set[N],queue[N],vis[N];
int link[M],next[M];

int FindSet(int x){
    if (set[x]!=x)
        set[x]=FindSet(set[x]);
    return set[x];
}

void Union(int x,int y){
    x=FindSet(x);
    y=FindSet(y);
    set[x]=y;
}

bool bfs(int u,int v){
    int fa=0,so=0,i;
    memset(vis,0,sizeof(vis));
    vis[u]=1; queue[fa]=u;
    while (fa<=so){
        for (i=head[queue[fa]];i;i=next[i]){
            if (vis[link[i]]==0 && point[link[i]]==0){
                if (link[i]==v) return true;
                vis[link[i]]=1; queue[++so]=link[i];
            }
        }
        ++fa;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int i,t,n,m,k,k1,temp,u,v;
    cin>>t;
    while (t--){
        cin>>n>>m>>k;
        int flag=false;
        for (i=0;i<=n;++i){
            set[i]=i;
            point[i]=head[i]=0;
        }
        for (i=0;i<k;++i){
            cin>>temp;
            point[temp]=1;
        }
        int j=0;
        for (i=0;i<m;++i){
            cin>>u>>v;
            Union(u,v);
            ++j;
            link[j]=v;
            next[j]=head[u];
            head[u]=j;
            ++j;
            link[j]=u;
            next[j]=head[v];
            head[v]=j;
        }

        int root=FindSet(1);
        for (int i=2;i<=n;++i){
            int t=FindSet(i);
            if (t != root){
                flag=true;
                break;
            }
        }

        cin>>k1;
        if (k1<k){
            flag=true;
        }
        cin>>v; --k1;
        point[v]=0;
        while(k1--){
            u=v;
            cin>>v;
            point[v]=0;
            if (!flag && !bfs(u,v))
                flag=true;
        }
        if (flag)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }

    return 0;
}
