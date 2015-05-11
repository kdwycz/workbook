#include <iostream>
using namespace std;
int main()
{
	int n,i,a,ans;
	while (cin>>n){
		ans=0;
		for (i=1;i<=n;++i){
			cin>>a;
			ans^=a;
		}
		if (ans)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
