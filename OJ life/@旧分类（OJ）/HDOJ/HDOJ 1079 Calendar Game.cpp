#include <iostream>
using namespace std;
int main()
{
	int n,m,d;
	cin>>n;
	while (n--){
		cin>>m>>m>>d;
		if ((m+d)%2==0 || ((d==30)&&(m==9 || m==11)))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
} 
