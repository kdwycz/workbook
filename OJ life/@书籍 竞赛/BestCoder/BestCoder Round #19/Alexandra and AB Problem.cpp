#include <cstdio>

struct node{
    int t,v;
}hack[1010][1010][20];
char map[1010];
int list[1010][1010]={0};
int n,m,q,i,j,k,x,y,d,ans,l,r,times=0;

int main()
{
    while (~scanf("%d%d%d",&n,&m,&q)){
        times++;
        for (i=1;i<=n;++i){
            scanf("%s",map);
            for (j=0;j<m;++j)
                if (map[j]=='X')
                    list[i][j+1]=list[i][j]+1;
                else
                    list[i][j+1]=list[i][j];
        }
        for (i=1;i<=q;++i){
            scanf("%d%d%d",&x,&y,&d);

            if (d<=20 && hack[x][y][d-1].t==times){
                printf("%d\n",hack[x][y][d-1].v);
                continue;
            }

            ans=0;
            for (j=0;;j+=d){
                if (x-j<=0) break;
                l=y-j-1; r=y+j;
                if (l<=0) l=0;
                if (r>m) r=m;
                ans+=list[x-j][r]-list[x-j][l];
            }
            printf("%d\n",ans);
            hack[x][y][d-1].t=times;
            hack[x][y][d-1].v=ans;
        }
    }
    return 0;
}
