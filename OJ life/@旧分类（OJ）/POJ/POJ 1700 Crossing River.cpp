#include <iostream>
#include <algorithm>
using namespace std;

int a[1010],n,i,nn,ans;
int main()
{
	cin>>n;
	while (cin>>n){
		ans=0;
		for (i=1;i<=n;++i)
			cin>>a[i];
		if (n>1){
			sort(a+1,a+n+1);
			for (nn=n;nn>3;nn-=2)
				ans+=a[1]+a[nn-1]<2*a[2]?2*a[1]+a[nn-1]+a[nn]:a[1]+2*a[2]+a[nn];
			if (nn==2) ans+=a[2];
			else ans+=a[1]+a[2]+a[3];
			cout<<ans<<endl;
		}
		if (n==1)
			cout<<a[1]<<endl;
	}		
	return 0;
}
