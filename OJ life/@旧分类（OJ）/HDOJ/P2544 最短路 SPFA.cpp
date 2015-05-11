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
		memset(vis,false,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		vis[1]=true; dis[1]=0;
		
		queue<int> q; q.push(1);
		while (!q.empty()){
			i=head[q.front()];
			while (i){
				if (dis[link[i]]>dis[q.front()]+data[i]){
					dis[link[i]]=dis[q.front()]+data[i];
					if (!vis[link[i]]){
						q.push(link[i]);
						vis[link[i]]=true;
					}
				}
				i=next[i];
			}
			vis[q.front()]=false;
			q.pop();
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}
