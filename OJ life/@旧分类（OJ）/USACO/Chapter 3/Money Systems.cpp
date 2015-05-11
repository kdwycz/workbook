#include <iostream>
using namespace std;
long long a[10010]={0},v,n,i,j,k;
int main()
{
	cin>>n>>v; a[0]=1;
	for (i=1;i<=n;++i){
		cin>>k;
		for (j=k;j<=v;++j)
		a[j]+=a[j-k];
	}
	cout<<a[v]<<endl;
	return 0;
} 
