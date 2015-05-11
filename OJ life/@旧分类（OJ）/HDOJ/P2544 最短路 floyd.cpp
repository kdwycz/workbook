#include <iostream>
#include <cstring>
using namespace std;
const int V=110;
const int MAXINT=0x3f3f3f3f;
int map[V][V],m,n,i,j,k,a,b;
int main()
{
	while (cin>>n>>m && (m || n)){
		memset(map,0x3f,sizeof(map));
		for (i=1;i<=m;++i){
			cin>>a>>b;
			cin>>map[a][b];
			map[b][a]=map[a][b];
		}
		for (k=1;k<=n;++k)
			for (i=1;i<=n;++i)
				for (j=1;j<=n;++j)
					if (i!=j && j!=k && k!=i && map[i][j]>map[i][k]+map[k][j])
						map[i][j]=map[i][k]+map[k][j];
		cout<<map[1][n]<<endl;
	}
	return 0;
}
