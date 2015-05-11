#include <iostream>
#include <cstring>
using namespace std;
const int M = 210;

int map[M][M];

struct node{
	int pre,n;
}queue[M*2];

int n,m;
long long ans;

long long bfs(){
	int fa=0,so=0;
	int vis[M][M]={0};
	queue[0].n=1; queue[0].pre=0; int flag=0;
	while (fa<=so){
		for (int i=1;i<=n;++i)
			if (map[queue[fa].n][i] && !vis[queue[fa].n][i]){
				queue[++so].n=i; queue[so].pre=fa; vis[queue[fa].n][i]=1;
				if (i==n){
					flag=1; break;
				}
			}
		if (flag) break;
		fa++;
	}
	if (!flag) return 0;
	long long t=10000000;
	fa=so;
	while (fa){
		int temp=queue[fa].pre;
		t=t>map[queue[temp].n][queue[fa].n]?map[queue[temp].n][queue[fa].n]:t;
		fa=temp;
	}
	fa=so;
	while (fa){
		int temp=queue[fa].pre;
		map[queue[temp].n][queue[fa].n]-=t;
		map[queue[fa].n][queue[temp].n]+=t;
		fa=temp;
	}
	return t;
}

int main()
{
	while (cin>>m>>n){
		memset(map,0,sizeof(map));
		ans=0; int a,b,c;
		for (int i=0;i<m;++i){
			cin>>a>>b>>c;
			map[a][b]+=c;
		}
		long long d;
		while (d=bfs())
			ans+=d;
		cout<<ans<<endl;
	}
	return 0;
} 
