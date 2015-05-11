#include <iostream>
#include <cstring>
using namespace std;
const int V=110;
const int MAXINT=0x3f3f3f3f;

struct edge{
	int a,b,s;
}map[V*V/2];
int dis[V];
int m,n,i,j,a,b; bool flag;
int main()
{
	while (cin>>n>>m && (m || n)){
		memset(dis,0x3f,sizeof(dis));
		for (i=1;i<=m;++i){
			cin>>map[i].a>>map[i].b>>map[i].s;
			map[i+m].a=map[i].b;
			map[i+m].b=map[i].a;
			map[i+m].s=map[i].s;
  		}
		flag=true; dis[1]=0;
		for (i=1;i<=n && flag;++i){
			flag=false;
			for (j=1;j<=m*2;++j)
				if (dis[map[j].a]+map[j].s<dis[map[j].b]){
					dis[map[j].b]=dis[map[j].a]+map[j].s;
					flag=true;
				}
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}
