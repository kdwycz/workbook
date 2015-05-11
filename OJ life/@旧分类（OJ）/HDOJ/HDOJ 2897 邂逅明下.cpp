#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a,m,n;
	while (cin>>a>>m>>n){
		a=a%(m+n);
		if (a==0 || a>m)
			cout<<"WIN\n";
		else
			cout<<"LOST\n";
	}
	return 0;
} 
