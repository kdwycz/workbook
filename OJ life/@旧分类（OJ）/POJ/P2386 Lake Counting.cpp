#include <iostream>
using namespace std;
const int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};
int i,j,n,m,map[110][110]={0},count=0;
string s;

void dfs(int x,int y){
	map[x][y]=0;
	for (int i=0;i<8;++i)
		if (map[x+dx[i]][y+dy[i]]==1 && x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m)
			dfs(x+dx[i],y+dy[i]);
}

int main(){
	cin>>n>>m;
	for (i=0;i<n;++i){
		cin>>s;
		for (j=0;j<m;++j)
			if (s[j]=='W') 
				map[i][j]=1; 
	}
	for (i=0;i<n;++i)
		for (j=0;j<m;++j)
			if (map[i][j]){
				count++;
				dfs(i,j);
			}
	cout<<count<<endl;
	return 0;
}
