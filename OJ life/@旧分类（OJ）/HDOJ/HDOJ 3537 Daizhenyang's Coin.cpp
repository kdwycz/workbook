//http://blog.csdn.net/jayye1994/article/details/14005575
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=101;
int a[maxn],n;

int main()
{
	while (cin>>n){
		for (int i=0;i<n;++i)
			cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for (int i=0;i<n;++i)
			if (i==0 || a[i]!=a[i-1]){
				int x=a[i]*2,cnt=0;
				while (x){
					if (x&1) cnt++;
					x>>=1;
				}
				if (cnt&1) ans^=a[i]*2;
				else ans^=a[i]*2+1;
			}
			if (ans) cout<<"No\n";
			else cout<<"Yes\n";
	}
	return 0;
}
