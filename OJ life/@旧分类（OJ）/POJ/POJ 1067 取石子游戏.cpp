#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m,n,p,k;
	while (cin>>m>>n){
		if (m>n) swap(m,n);
		p=0; k=1;
		k=n-m;
		p=(k*(1+sqrt(5))/2);
		if (p==m)
			cout<<"0\n";
		else
			cout<<"1\n";
	}
	return 0;
} 
