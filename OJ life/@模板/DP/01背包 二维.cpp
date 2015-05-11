#include <iostream>
#include <cstring>
using namespace std;
const int maxm=1100;
const int maxn=110;
int a[maxn][maxm],w[maxn],p[maxn],i,j,t,m;
int main(int argc, char *argv[])\
{
	cin>>t>>m;
	memset(a,0,sizeof(a));
	for (i=1;i<=m;++i){
		cin>>w[i]>>p[i];
	}
	for (i=1;i<=m;++i)
		for (j=w[i];j<=t;++j)
			a[i][j]=a[i-1][j]>(a[i-1][j-w[i]]+p[i])?a[i-1][j]:a[i-1][j-w[i]]+p[i];
	cout<<a[m][t]<<endl;		
	return 0;
}

