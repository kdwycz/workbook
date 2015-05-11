#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=730;
const int N[8]={0,1,3,9,27,81,243,729};
int n,i,j,map[MAXN][MAXN];
void set(int n,int x,int y);
int main()
{
	while (cin>>n && n!=-1){
		memset(map,0,sizeof(map));
		set(n,1,1);
		for (i=1;i<=N[n];++i){
			for(j=1;j<=N[n];++j)
				if (map[i][j]) cout<<'X';
					else cout<<' ';
			cout<<endl;
		}
		cout<<"-\n";
	}
	return 0;
}

void set(int n,int x,int y){
	if (n==1){
		map[x][y]=1;
		return;
	}
	set(n-1,x,y);
	set(n-1,x+2*N[n-1],y);
	set(n-1,x+N[n-1],y+N[n-1]);
	set(n-1,x,y+2*N[n-1]);
	set(n-1,x+2*N[n-1],y+2*N[n-1]);
	return;
}
