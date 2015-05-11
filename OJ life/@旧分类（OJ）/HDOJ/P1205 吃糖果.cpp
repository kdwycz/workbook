#include <iostream>
using namespace std;

long n,m,i,j,k,maxn;
long long sum;
int main(int argc, char *argv[])
{
	//std::ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>m; maxn=0; sum=0;
		for(j=1;j<=m;++j){
			cin>>k;
			maxn=maxn<k?k:maxn;
			sum+=k;
		}
		if((sum+1)/2<maxn) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
	}
	return 0;
}