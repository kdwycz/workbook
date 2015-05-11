#include <iostream>
#include <cstring>
using namespace std;

int map[30][30],start[3],i,j,k,m,n,point; 
int der[4][2]={0,1, 0,-1, 1,0, -1,0};

int findy(int,int,int);
void dfs(int,int,int);

int main(int argc, char *argv[])
{
	while (cin>>n>>m && n){
		memset(map,0,sizeof(map));
		for (i=1;i<=m;++i)
			for (j=1;j<=n;++j){
				cin>>k;
				map[i][j]=k;
				if (2==k){
					start[1]=i;
					start[2]=j;
				}
			}
		point=12;
		dfs(1,start[1],start[2]);
		if (point>10) point=-1;
		cout<<point<<endl;
	}
	return 0;
}

int findy(int i,int dy,int dx){
	int x=0;
	while(map[dy+der[i][0]][dx+der[i][1]]!=1 && map[dy][dx]!=3){
		if (dy+der[i][0]==0 || dy+der[i][0]>m || dx+der[i][1]==0 || dx+der[i][1]>n) return 0;
		dy+=der[i][0]; dx+=der[i][1]; x++;		 
	}
	return x;
} 

void dfs(int ii,int dy,int dx){
	int x; 
	for (int i=0;i<4;++i){
		x=findy(i,dy,dx);
		if (x){
			if (3==map[dy+x*der[i][0]][dx+x*der[i][1]]) point=point>ii?ii:point;
			else if (ii<10){
				map[dy+(x+1)*der[i][0]][dx+(x+1)*der[i][1]]=0;
				dfs(ii+1,dy+x*der[i][0],dx+x*der[i][1]);
				map[dy+(x+1)*der[i][0]][dx+(x+1)*der[i][1]]=1;		
			}
		}
	}
	return;
}
