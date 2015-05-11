#include <iostream>
using namespace std;
int a[101],maxn=0,n,c,i,j;
int main()
{
	cin>>n>>c; cin>>a[0];
	for (i=1;i<n;++i){
		cin>>a[i];
		j=a[i-1]-a[i];
		maxn=j>maxn?j:maxn;
	}
	if (maxn-c>0) cout<<maxn-c<<endl;
	else cout<<"0\n";
	return 0;
} 
