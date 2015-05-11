#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n,p;
int k[100],sg[10100];

int main()
{
	int i,j;
	while (cin>>m && m){
		for (i=0;i<m;++i)
			cin>>k[i];
		sort(k,k+i);
		k[m]=0x3f3f3f3f;
		memset(sg,0,sizeof(sg));
		for (i=1;i<=10100;++i){
			int f[101]={0}; //f[10100]={0}; TLE
			for (j=0;k[j]<=i;++j)
				f[sg[i-k[j]]]=1;
			for (j=0;f[j];++j);
			sg[i]=j;
		}
	
		cin>>m;
		while (m--){
			cin>>n; j=0;
			while (n--){
				cin>>i;
				j^=sg[i];
			}
			if (j) cout<<'W';
			else cout<<'L';
		}
		cout<<endl;
	}
	return 0;
}
