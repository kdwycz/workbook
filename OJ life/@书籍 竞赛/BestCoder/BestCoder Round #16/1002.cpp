#include <iostream>
using namespace std;
int a[1001],b[1001],n,i,j,maxn,t,flag,flag0,flag1; 
int main()
{
	cin>>t;
	while (t--){
		cin>>n; flag=false; maxn=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			b[i]=0;
		}	
		for (i=n-1;i;--i){
			flag1=false;
			for (j=i+1;j<=n;++j){
				if (a[i]==a[j])
					flag1=true;
				if ((a[i]<a[j])&&(b[j]>=b[i])){
					b[i]=b[j]+1;
					if (flag1) flag=true;
				}
			}
			if (flag1 && b[i]==0) flag=true; 
		}
			
		for (i=1;i<=n;++i)
			maxn=maxn<b[i]?b[i]:maxn;
		if (flag) ++maxn;
		cout<<maxn<<endl;
	}
	return 0;
}
