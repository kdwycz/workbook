#include <iostream>
#include <cstring>
using namespace std;
const int maxm=1100;
const int maxn=110;
int a[maxn],w[maxn],p[maxn],i,j,t,m;
int main(int argc, char *argv[])
{
	cin>>t>>m;
	memset(a,0,sizeof(a));
	for (i=1;i<=m;++i){
		cin>>w[i]>>p[i];
	}
	for (i=1;i<=m;++i)
		for (j=t;j>=w[i];--j)
			a[j]=a[j]>a[j-w[i]]+p[i]?a[j]:a[j-w[i]]+p[i];
	cout<<a[t]<<endl;		
	return 0;
}

