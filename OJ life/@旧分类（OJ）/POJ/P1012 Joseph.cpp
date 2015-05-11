#include <iostream>
using namespace std;
int ans[15]={0},x,n,f[15]={0};

int joseph(int x){
	int m=x,i;
	while (m++){
		for (i=1;i<=x;++i){
			f[i]=(f[i-1]+m-1)%(n-i+1);
			if (f[i]<x) break;
		}
		if (i>x){
			ans[x]=m;
			return m;
		} 	
	}
}

int main()
{
	while (cin>>x && x){
		if (ans[x]) cout<<ans[x]<<endl;
		else{
			n=x*2;
			cout<<joseph(x)<<endl;
		}
	}
	return 0;
}
