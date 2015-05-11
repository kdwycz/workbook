#include <iostream>
using namespace std;
int a[1001],b[1001],n,i,j,maxn; 
int main(int argc, char *argv[])
{
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
		b[i]=1;
	}	
	for (i=2;i<=n;++i)
		for (j=1;j<=i;++j)
			if ((a[i]<a[j])&&(b[j]+1>b[i])) b[i]=b[j]+1;
	maxn=0;
	for (i=1;i<=n;++i) maxn=maxn<b[i]?b[i]:maxn;
	cout<<maxn<<endl;
	return 0;
}
