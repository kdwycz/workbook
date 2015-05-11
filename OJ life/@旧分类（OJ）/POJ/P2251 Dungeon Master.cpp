#include <iostream>
#include <string>
using namespace std;

const int maxn=31,maxm=30000;
string map[maxn][maxn];
int dx[6]={-1, 1, 0, 0, 0, 0};
int dy[6]={ 0, 0,-1, 1, 0, 0};
int dz[6]={ 0, 0, 0, 0,-1, 1};
int n,m,p,visit[maxn][maxn][maxn];

struct point{
	int x,y,z;
	int step;
}queue[maxm];

int check(int,int,int);
int bfs(int,int,int);
int main()
{
	int i,j,k,x,y,z;
	while(cin>>p>>m>>n && p!=0){
		for (i=0;i<p;++i)
			for (j=0;j<m;++j){
				cin>>map[i][j];
				for (k=0;k<n;++k){
					visit[i][j][k]=0;
					if(map[i][j][k]=='S'){
						z=i; x=k; y=j;
					}
				}
					
			}
	//	memset(queue,0,sizeof(queue));
		int ans=bfs(x,y,z);
		if (ans==-1) cout<<"Trapped!\n";
		else cout<<"Escaped in "<<ans<<" minute(s).\n";
	}
	return 0;
}

int check(int x,int y,int z){
	if (x>=0 && x<n && y>=0 && y<m && z>=0 && z<p
	&& !visit[z][y][x] && map[z][y][x] != '#') return 1;
	else return 0;
}

int bfs(int x,int y, int z){
	int i,fa=0,so=0; point temp;
	visit[z][y][x]=1; 
	queue[0].x=x; queue[0].y=y; 
	queue[0].z=z; queue[0].step=0;
	while (so>=fa && so<maxm){
		for (i=0;i<6;++i){
			temp.x=queue[fa].x+dx[i];
			temp.y=queue[fa].y+dy[i];
			temp.z=queue[fa].z+dz[i];
			if (check(temp.x,temp.y,temp.z))
				if (map[temp.z][temp.y][temp.x]=='E') 
					return queue[fa].step+1;
				else{
					visit[temp.z][temp.y][temp.x]=1;
					queue[++so]=temp;
					queue[so].step=queue[fa].step+1;
				}
		}
		fa++;
	} 
	return -1;
}

