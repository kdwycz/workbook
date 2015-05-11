#include <iostream>
using namespace std;
int n,a[50000],i,j,l,r,ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (i=0;i<n;++i) cin>>a[i];
	for (i=0;i<n;++i){
		l=r=a[i]; ans++;
		for (j=i+1;j<n;++j){
			l=a[j]<l?a[j]:l;
			r=a[j]>r?a[j]:r;
			if (r-l==j-i) ans++;
		}
	} 
	cout<<ans<<endl;
	return 0;
}
