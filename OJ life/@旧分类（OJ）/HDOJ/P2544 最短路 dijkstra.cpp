#include <iostream>
#include <cstring>
using namespace std;
const int V=110;
const int MAXINT=0x3f3f3f3f;
int map[V][V],vis[V],dis[V],path[V];
int m,n,i,j,a,b;
int main()
{
	while (cin>>n>>m && (m || n)){
		memset(map,0x3f,sizeof(map));
		memset(vis,0,sizeof(vis));
		for (i=1;i<=m;++i){
			cin>>a>>b;
			cin>>map[a][b];
			map[b][a]=map[a][b];
		}
		vis[1]=1;
		for (i=1;i<=n;++i){
			dis[i]=map[1][i];
			path[i]=1;
		}
		dis[1]=0; path[1]=-1;
		int pre=1;
		for (i=1;i<n;++i){
			for (j=1;j<=n;++j)
				if (vis[j]==0 && dis[pre]+map[pre][j]<dis[j]){
					dis[j]=dis[pre]+map[pre][j];
					path[j]=pre;
				}
			int min=MAXINT;
			for(j=1;j<=n;++j)
				if (vis[j]==0 && dis[j]<min){
					min=dis[j]; pre=j;
				}
			vis[pre]=1;
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}
