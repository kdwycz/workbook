#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int V=110;
const int E=V*V;
int head[V],dis[V],link[E],data[E],next[E];
bool vis[V];
int n,m,i,a,b,c;

int main()
{
	while (cin>>n>>m && (m || n)){
		memset(head,0,sizeof(head));
		for (i=1;i<=m*2;++i){
			cin>>a>>b>>c;
			data[i]=c; link[i]=b;
			next[i]=head[a]; head[a]=i;
			i++;
			data[i]=c; link[i]=a;
			next[i]=head[b]; head[b]=i;
		}
		priority_queue <pair<int, int> > q;
		memset(vis,false,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		dis[1]=0; q.push(make_pair(0,1));
		while (!q.empty()){
			int cur=q.top().second;
			q.pop();
			if (!vis[cur]){
				vis[cur]=true;
				for (i=head[cur];i;i=next[i]){
					int v=link[i];
					if(!vis[v] && dis[v]>dis[cur]+data[i]){
						dis[v]=dis[cur]+data[i];
						q.push(make_pair(-dis[v],v));
					}
				}
			}
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}
