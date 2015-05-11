#include <iostream>
#include <cstdio>
using namespace std;

const int M = 25;
int n,k,m,a[M];

int go(int p,int d,int t){
	while (t--){
		do{
			p=(p+d+n-1)%n+1;
		}while(a[p]==0);
	}
	return p;
}

int main()
{
	while (cin>>n>>k>>m && n){
		for (int i=1;i<=n;++i)
			a[i]=i;
		int left=n;
		int p1=n,p2=1;
		while (left){
			p1=go(p1,1,k);
			p2=go(p2,-1,m);
			printf("%3d",p1);
			left--;
			if (p2!=p1){
				printf("%3d",p2);
				left--;
			}
			a[p1]=a[p2]=0;
			if (left)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}
