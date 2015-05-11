#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int x,y;
}po[21];
int vis[110][110],n,ans;

bool cmp(node a,node b){
    if (a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

void dfs(int pos,int val){
	ans=max(ans,val);
	if(pos>=n) return;
	int y=po[pos].y,x=po[pos].x;
	if (vis[y][x]>0)
		for (int i=pos+1;i<n;++i){
			int ty=po[i].y,tx=po[i].x;
			if (ty!=y) break;
			int dis=tx-x;
			if (dis==0) continue;
			if (vis[y][tx]>0 && vis[y+dis][x]>0 && vis[y+dis][tx]>0){
				vis[y][x]--; vis[y][tx]--;
				vis[y+dis][x]--; vis[y+dis][tx]--;
				dfs(pos+1,val+4);
				vis[y][x]++; vis[y][tx]++;
				vis[y+dis][x]++; vis[y+dis][tx]++;
			}
		}
	dfs(pos+1,val); 
}

int main()
{
    while (cin>>n && n!=-1){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i){
            cin>>po[i].y>>po[i].x;
            vis[po[i].y][po[i].x]++;
        }
        sort(po,po+n,cmp);
        ans=0; dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
