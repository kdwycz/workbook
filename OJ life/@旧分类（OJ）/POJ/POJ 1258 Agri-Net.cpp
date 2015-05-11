#include <iostream>
#include <cstring>
using namespace std;

const int V=110;
const int MAXINT=0x3f3f3f3f;

int map[V][V],dist[V],vist[V];
int n,i,j,m,minn,ans;

int main()
{
	while (cin>>n){
		ans=0;
		memset(vist,0,sizeof(vist));
		for (i=1;i<=n;++i)
			for (j=1;j<=n;++j)
				cin>>map[i][j];
		for (i=1;i<=n;++i)
			dist[i]=map[1][i];
		vist[1]=1;
	
		for (i=1;i<n;++i){
			minn=MAXINT;
			for (j=1;j<=n;++j)
				if (!vist[j] && dist[j]<minn){
					minn=dist[j]; m=j;
				}
			ans+=minn;
			for (j=1;j<=n;++j)
				dist[j]=dist[j]>map[m][j]?map[m][j]:dist[j];
			vist[m]=1;
		}
		cout<<ans<<endl;
	}
		return 0;
}
