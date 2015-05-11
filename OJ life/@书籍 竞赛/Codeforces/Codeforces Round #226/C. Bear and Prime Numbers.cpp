#include <iostream>
using namespace std;

const int MAXN=10000001;
int vis[MAXN]={0},sum[MAXN]={0},v[MAXN]={0},num,n,i,j,m,l,r;
 
int main()
{
	cin>>n;
	for (i=0;i<n;++i){
		cin>>num;
		vis[num]++;
	}
	for (i=2;i<MAXN;++i){
		if (!v[i])
		for (j=i;j<MAXN;j+=i){
			if (vis[j]) sum[i]+=vis[j];
			v[j]=1;
		}
	}
	for (i=2;i<MAXN;++i)
		sum[i]+=sum[i-1];
	cin>>m;
	for (i=0;i<m;++i){
		cin>>l>>r;
		if (r>=MAXN) r=MAXN-1;
		if (l>=MAXN) l=MAXN;;
		cout<<sum[r]-sum[l-1]<<endl;
	}
	return 0;
}
