#include <iostream>
using namespace std;

int a[110][110],b[110],c[110],n,i,j,j1,k,l;
int main(int argc, char *argv[])
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n!=0){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(l=1;l<=(n*(n-1)/2);++l){
			cin>>i>>j>>k;
			a[i][j]=k; a[j][i]=k;
		}	
		for(i=1;i<=n;++i) b[i]=a[1][i];
		l=n-1; k=0; c[1]=1;
		while(l>0){
			j=-1;
			for(i=2;i<=n;++i)
				if((!c[i])&&((j<0)||(j>b[i]))){
					j=b[i]; j1=i;
				}
			k+=j; c[j1]=1;
			for(i=1;i<=n;++i)
		 		b[i]=a[j1][i]<b[i]?a[j1][i]:b[i];
	  		--l;
		}
		cout<<k<<endl;
		cin>>n;
	}
	return 0;
}