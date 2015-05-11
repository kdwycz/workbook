#include <iostream>
#include <cstring>
using namespace std;
int n,p[1010],dp[1010],m,maxi,maxp,i,j;
int main()
{
	std::ios::sync_with_stdio(false);
	while (cin>>n && n){
		maxp=0;
		memset(dp,0,sizeof(dp));
		for (i=1;i<=n;++i){
			cin>>p[i];
			if (p[i]>maxp){
				maxp=p[i];
				maxi=i;
			}
		}
		cin>>m;
		if (m<5){
			cout<<m<<endl;
			continue;
		}
		m-=5;
		p[maxi]=0; dp[0]=1;
		for (i=1;i<=n;++i)
			for (j=m;j>=p[i];--j)
				if (dp[j-p[i]]) dp[j]=1;
		i=m;
		while (!dp[i]) i--;
		cout<<m-i+5-maxp<<endl;
	}
	return 0;
}
