#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int nn,n,m,s,ii,i,j,k;
	cin>>nn;
	for (i=1;i<=nn;++i){
		ii=0;
		while (cin>>n>>m && n){
			s=0; ++ii;
			for (j=1;j<n-1;++j)
				for (k=j+1;k<n;++k)
					if ((j*j+k*k+m)%(j*k)==0) ++s;
			cout<<"Case "<<ii<<": "<<s<<endl; 
		}	
	if (i!=nn) cout<<endl;				
	}
	return 0;
}
