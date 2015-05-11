#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long T,n,a,b,ans; 
	cin>>T;
	while (T--){
		cin>>n; ans=0;
		for (int i=1;i<=n;i++){
			cin>>a;
			b=((n-i+1)*i)%1000000007;
			b=(b*a)%1000000007;
			ans=(ans+b)%1000000007;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
