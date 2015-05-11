#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n,p;
int k[100],sg[10100];

int mex(int n){
	int i;
	bool g[101]={0};
	for (i=0;n-k[i]>=0;++i){
		if (sg[n-k[i]]==-1)
			sg[n-k[i]]=mex(n-k[i]);
		g[sg[n-k[i]]]=1;
	}
	for (i=0;g[i];++i);
	return i;
}

int main()
{
	int i,j;
	while (cin>>m && m){
		for (i=0;i<m;++i)
			cin>>k[i];
		sort(k,k+i);
		k[m]=0x3f3f3f3f;
		memset(sg,-1,sizeof(sg));
		cin>>m;
		while (m--){
			cin>>n; j=0;
			while (n--){
				cin>>i;
				if (sg[i]==-1) 
					sg[i]=mex(i);
				j^=sg[i];
			}
			if (j) cout<<'W';
			else cout<<'L';
		}
		cout<<endl;
	}
	return 0;
}
