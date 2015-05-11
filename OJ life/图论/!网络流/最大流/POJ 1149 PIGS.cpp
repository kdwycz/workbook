#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
const int M = 110;
const int INF = 0x3f3f3f3f;

int map[M][M];
bool visit[M];
int Layer[M],n,m; 

void init(){
	memset(map,0,sizeof(map));
	cin>>m>>n; n+=2;
	int pigs[M*10],per[M][M*10]={0},a,b;
	for (int i=1;i<=m;++i) cin>>pigs[i];
	for (int i=2;i<n;++i){
		cin>>a;
		while (a--){
			cin>>b;
			per[i][b]=1;
			if(pigs[b]){
				map[1][i]+=pigs[b];
				pigs[b]=0;
			}
		}
		cin>>b;
		map[i][n]=b;
	}
	for (int i=n-1;i>1;i--)
		for (int j=1;j<=m;++j)
			if (per[i][j])
				for (int k=2;k<i;++k)
					if (per[k][j])
						map[k][i]=INF;
}

bool Count(){
	int layer=0; deque<int>q;
	memset(Layer,-1,sizeof(Layer));
	Layer[1]=0; q.push_back(1);
	while (!q.empty()){
		int v=q.front();
		q.pop_front();
		for (int j=1;j<=n;++j){
			if (map[v][j]>0 && Layer[j]==-1){
				Layer[j]=Layer[v]+1;
				if (j==n)
					return true;
				else
					q.push_back(j);
			}
		}
	}
	return false;
}

int Dinic(){
	int i; int s;
	int nMaxFlow=0;
	deque<int>q;
	while (Count()){
		q.push_back(1);
		memset(visit,0,sizeof(visit));
		visit[1]=1;
		while (!q.empty()){
			int nd=q.back();
			if (nd==n){
				int nMinC=INF;
				int nMinC_vs;
				for (i=1;i<q.size();++i){
					int vs=q[i-1];
					int ve=q[i];
					if (map[vs][ve]>0)
						if (nMinC>map[vs][ve]){
							nMinC=map[vs][ve];
							nMinC_vs=vs;
						}
				}
				nMaxFlow+=nMinC;
				for (i=1;i<q.size();++i){
					int vs=q[i-1];
					int ve=q[i];
					map[vs][ve]-=nMinC;
					map[ve][vs]+=nMinC;
				}
				while (!q.empty() && q.back()!=nMinC_vs){
					visit[q.back()]=0;
					q.pop_back();
				}
			}
			else{
				for (i=1;i<=n;++i){
					if (map[nd][i]>0 && Layer[i]==Layer[nd]+1 && !visit[i]){
						visit[i]=1;
						q.push_back(i);
						break;
					}
				}
				if (i>n)
					q.pop_back();
			}
		}
	}
	return nMaxFlow;
}

int main()
{
	init();
	cout<<Dinic()<<endl;
	return 0;
} 
