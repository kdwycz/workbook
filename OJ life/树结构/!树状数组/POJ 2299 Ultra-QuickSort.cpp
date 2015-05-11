#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define Lowbit(x) (x&(-x))
const int M = 500010;

struct node{
	int n,x;
}arr[M];

int a[M],c[M],n;

bool cmp(node x,node y){
	return x.x<y.x;
}

void Update(int t,int v){
	for (int i=t;i<=n;i+=Lowbit(i))
		c[i]+=v;
}

int Getsum(int x){
	int temp=0;
	for (int i=x;i>=1;i-=Lowbit(i))
		temp+=c[i];
	return temp;
}

int main()
{
	while (cin>>n && n){
		for (int i=1;i<=n;++i){
			cin>>arr[i].x;
			arr[i].n=i;
		}
		sort(arr+1,arr+n+1,cmp);
		for (int i=1;i<=n;++i)
			a[arr[i].n]=i;
		long long ans=0;
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;++i){
			Update(a[i],1);
			ans+=i-Getsum(a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
