#include <iostream>
#include <cstring>
using namespace std;
int a[3000],b[30000];
int m,n,k,l,i;
int main()
{
	while (cin>>m>>n){
		memset(b,-1,sizeof(b));
		cout<<m<<'/'<<n<<" = "<<m/n<<'.';
		for (i=0,l=1;l;++i){
			k=m/n; l=m%n;
			if (b[m]!=-1) break;
			a[i]=k;
			b[m]=i;
			m=l*10;
		}
		int flag=0,re=0;
		re=i-b[m];
		if (i>51){
			flag=1;
			i=51;
		}
		if (l==0){
			for (int j=1;j<i;++j)
				cout<<a[j];
			cout<<"(0)\n";
		}
		else{
			for (int j=1;j<b[m];++j)
				cout<<a[j];
			cout<<'(';
			for (int j=b[m];j<i;++j)
				cout<<a[j];
			if (flag) cout<<"...";
			cout<<")\n";
		}
		cout<<"   "<<re<<" = number of digits in repeating cycle\n\n";
	}
	return 0;
}
