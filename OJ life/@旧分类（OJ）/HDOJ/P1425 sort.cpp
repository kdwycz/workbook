#include <iostream>
#include <cstring>
using namespace std;
int a[1000001],i,m,n,p;
int main()
{
	ios::sync_with_stdio(false); 
	while (cin>>n>>m){
		memset(a,0,sizeof(a));
		for (i=0;i<n;++i){
  			cin>>p;
 			a[p+500000]=1;
   		}
		for (i=1000000;(i>=0 && m);--i)
			if (a[i]){
				cout<<i-500000;
				m--;
				if (m)
			 	   cout<<' ';
				else
					cout<<endl;
			}
	}
	return 0;
}
