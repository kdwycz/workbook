#include <cstdio>
#include <cstring>
const int N = 100010;
const int M = 400020;
int head[N],vis1[N],vis2[N];
int link[M],next[M];
int i,j,t,n,m,k,l,u,v; bool flag;

void dfs1(int i){
    for (int j=head[i];j;j=next[j])
        if (!vis1[link[j]]){
            vis1[link[j]]=1;
            dfs1(link[j]);
        }
}

void dfs2(int i){
    for (int j=head[i];j;j=next[j])
        if (vis2[link[j]]==0){
            vis2[link[j]]=1;
            dfs2(link[j]);
        }
        else if (vis2[link[j]]==2)
            vis2[link[j]]=3;
}

int main()
{
    scanf("%d",&t);
    while (t--){
        flag=true; j=0;
        scanf("%d%d%d",&n,&m,&k);

        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(head,0,sizeof(head));

        for (i=1;i<=k;++i){
            scanf("%d",&u);
            vis2[u]=2;
        }
        for (i=1;i<=m;++i){
            scanf("%d%d",&u,&v);
            ++j;
            link[j]=v;
            next[j]=head[u];
            head[u]=j;
            ++j;
            link[j]=u;
            next[j]=head[v];
            head[v]=j;
        }

        dfs1(1);
        for(int i=1;flag && i<=n;++i)
            if (!vis1[i]) flag=false;

        scanf("%d",&l);
        if (l<k) flag=false;

        scanf("%d",&u);
        vis2[u]=3; dfs2(u);

        for (int i=2;i<=l;++i){
            scanf("%d",&u);
            if (flag)
                if (vis2[u]==2) flag=false;
                else dfs2(u);
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
