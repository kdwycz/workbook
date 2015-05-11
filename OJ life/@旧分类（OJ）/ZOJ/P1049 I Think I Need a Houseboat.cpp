#include<iostream>
using namespace std;
int main()
{
	const double pi=3.1415926;
	int n,i;
	double a,b,s;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a>>b;
		s=(a*a+b*b)*pi/100.00;
		cout<<"Property "<<i<<": This property will begin eroding in year "<<(int)s+1<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}