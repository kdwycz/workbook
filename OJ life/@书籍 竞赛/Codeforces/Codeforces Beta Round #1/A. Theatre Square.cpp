#include <iostream>
using namespace std;
int main()
{
	long long a,b,c,d,e;
	cin>>a>>b>>c;
	a=a%c?a/c+1:a/c;
	b=b%c?b/c+1:b/c;
	cout<<a*b<<endl;
	return 0;
} 
