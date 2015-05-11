#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct mouse{
	int weight,speed,ii;
}; 
int cmp(mouse,mouse); 
mouse a[1100];
int n,i,j,maxn,maxm,k,b[1100],c[1000];
int main(int argc, char *argv[])
{
	memset(c,0,sizeof(c)); i=1;
	while (cin>>a[i].weight>>a[i].speed){
		a[i].ii=i;
		++i;
		b[i]=1;
	} 
	n=i-1;
	sort(a+1,a+i,cmp);
//for (i=1;i<=n;++i)cout<<a[i].weight<<" "<<a[i].speed<<" "<<a[i].ii<<endl;
	for (i=n-1;i;--i)
		for (j=i+1;j<=n;++j)
			if ((a[j].speed<a[i].speed)&&(b[i]<b[j]+1)&&(a[i].weight!=a[j].weight)){
				b[i]=b[j]+1; c[i]=j;
			} 			
	for (i=1;i<=n;++i)
		if (maxn<b[i]){
			maxn=b[i];
			maxm=i;
		} 
	cout<<maxn<<endl<<a[maxm].ii<<endl;
	while (c[maxm]){
		cout<<a[c[maxm]].ii<<endl;
		maxm=c[maxm];
	}
	return 0;
}

int cmp(mouse a,mouse b){
	return a.weight<b.weight;
}
