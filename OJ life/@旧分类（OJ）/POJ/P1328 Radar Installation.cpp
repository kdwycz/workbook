#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct cd{
	double l,r;
}arr[1010];
int n,i,ans=1,m=0;
double d,a,b;

bool cmp(cd a,cd b){
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n>>d && (n||d)){
		if (d<=0) d=0;
		for (i=0;i<n;++i){
			cin>>a>>b;
			if (d*d-b*b<0){
				ans=-1;
				continue;
			}
			arr[i].l=a-sqrt(d*d-b*b);
			arr[i].r=a+sqrt(d*d-b*b);
		}
		if (ans>0){
			sort(arr,arr+n,cmp);
			b=arr[0].r;
			for (i=1;i<n;++i)
				if (arr[i].l>b){
					b=arr[i].r;
					ans++;
				}
				else if (arr[i].r<b)
					b=arr[i].r;
		}
		cout<<"Case "<<++m<<": "<<ans<<endl;
		ans=1;
	}
	return 0;
}
