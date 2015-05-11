#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int a[20],b[20],m,n,i,ave,sum;
int cmp(int a,int b){return a>b;}
bool dfs(int bs,int p,int i);
int main()
{
	cin>>m;
	while (m--){
		cin>>n;
		sum=0;
		memset(b,0,sizeof(b));
		for(i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		ave=sum/4;
		if (n<4 || sum%4 || ave<a[0]){
			cout<<"no\n";
			continue;
		}
		if (dfs(0,0,0)) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}

bool dfs(int bs,int p,int i){
	if (bs==3) return true;
	for (int j=i;j<n;++j)
		if (!b[j]){
			b[j]=true;
			if (a[j]+p<ave)
				if (dfs(bs,p+a[j],j+1)) return true;
			if (a[j]+p==ave)
				if (dfs(bs+1,0,0)) return true;
			b[j]=false;
		}
	return false;
}
