#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string a[9];
int n,k,i,ii,xx[10];

void dfs(int,int);

int main()
{
	while ( cin>>n>>k && n != -1 ){
		ii=0;
		memset(xx,0,sizeof(xx));
		for (i=0;i<n;++i) cin>>a[i];
		dfs(0,0);
		cout<<ii<<endl;
	}
	return 0;
}

void dfs(int x,int point){
	int i;
	if (x<n){
		for (i=0;i<n;++i)
			if (!xx[i] && '#'==a[x][i])
				if(point+1==k) ++ii;
				else{
					xx[i]=1; a[x][i]='&';
					dfs(x+1,point+1);
					xx[i]=0; a[x][i]='#';
				}
		if (n>k) dfs(x+1,point);
	}
	return;
}
