#include <iostream>
using namespace std;

const int dx[4]={ 1, 0,-1, 0};
const int dy[4]={ 0, 1, 0,-1};

string map[7];
int n,m,t,i,j,x1,y1,x2,y2;

int abs(int x){
	return x>0?x:-x;
} 

bool dfs(int x,int y,int i){
	int temp=t-i-abs(x2-x)-abs(y2-y);
	if (temp<0 || temp%2) return false;
	for (int j=0;j<4;++j){
		x+=dx[j]; y+=dy[j];
		if (x>=0 && x<n && y>=0 && y<m){
			if (i+1==t && map[x][y]=='D') return true;
			if (map[x][y]=='.'){
				map[x][y]='X';
				if (dfs(x,y,i+1)) return true;
				map[x][y]='.';
			}
		}
		x-=dx[j]; y-=dy[j];
	} 
	return false;
}
int main()
{
	while (cin>>n>>m>>t && n){
		for (i=0;i<n;++i){
			cin>>map[i];
			for (j=0;j<m;++j)
				if (map[i][j]=='S'){
					x1=i; y1=j;
				}
				else if (map[i][j]=='D'){
					x2=i; y2=j;
				}
		}
		if (dfs(x1,y1,0)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
