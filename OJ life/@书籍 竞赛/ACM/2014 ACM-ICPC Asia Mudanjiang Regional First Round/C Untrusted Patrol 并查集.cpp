#include <cstdio>
const int N = 100010;
const int M = 400020;
int head[N],point[N],set[N];
int link[M],next[M];
int i,j,t,n,m,k,l,u,v; bool flag;

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

int main()
{
    scanf("%d",&t);
    while (t--){
        flag=true; j=0;
        scanf("%d%d%d",&n,&m,&k);
        for (i=0;i<=n;++i){
            set[i]=i;
            point[i]=head[i]=0;
        }
        for (i=0;i<k;++i){
            scanf("%d",&u);
            point[u]=1;
        }
        for (i=0;i<m;++i){
            scanf("%d%d",&u,&v);
            if (!point[u] && !point[v])
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
        scanf("%d",&l);
        if (l<k) flag=false;
        scanf("%d",&v);
        point[v]=0;
        for (j=head[v];j!=0;j=next[j])
            if (point[link[j]]==0)
                Union(v,link[j]);
        for (i=2;i<=l;++i){
            u=v; scanf("%d",&v);
            if (flag){
                point[v]=0;
                for (j=head[v];j!=0;j=next[j])
                    if (point[link[j]]==0)
                        Union(v,link[j]);
                if (FindSet(u)!=FindSet(v)) flag=false;
            }
        }
        u=FindSet(1);
        for (int i=2;flag && i<=n;++i){
            v=FindSet(i);
            if (u != v) flag=false;
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
