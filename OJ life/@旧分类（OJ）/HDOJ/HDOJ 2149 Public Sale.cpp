#include <iostream>
using namespace std;
int main()
{
 	int m,n;
 	while (cin>>m>>n){
 		if (m<=n){
 			for (int i=m;i<=n;++i){
 				cout<<i;
 				if (i<n) cout<<' ';
 			}
 		}
 		else  
 			if (m%(n+1)!=0)
 				cout<<m%(n+1);
 			else
 				cout<<"none";
 		cout<<endl;
 	}
	return 0;
}

