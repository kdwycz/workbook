#include <iostream>
#include <cstring>
using namespace std;
int n,a[102][10002],minn,i,j,k,b,sum;
int main(int agrc,char *agrv[])
{
	cin>>n;
	minn=1000000;
	memset(a,0,sizeof(a));
	for (i=1;i<=n;++i){
		a[i][0]=1; sum=0;
		while((cin>>b)&&(b!=-1)){
			for (j=sum;j>=0;--j)
				if (a[i][j]) a[i][j+b]=1;
			sum+=b;
		}
		if (minn>sum) minn=sum;
	}
	
	for (j=minn;j;--j){
		i=1;
		while ((i<n)&&(a[i][j])) ++i;
		if (a[i][j]){
			cout<<j<<endl;
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}
