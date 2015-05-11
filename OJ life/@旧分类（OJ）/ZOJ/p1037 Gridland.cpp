// ZOJ 1037  HDOJ 1046
#include<iostream>
using namespace std;
int main()
{
	int n,a,b,i;
	cin>>n;
	cout.setf(ios_base::showpoint);
	cout.setf(ios_base::fixed);
	cout.precision(2);
	for(i=1;i<=n;++i){
		cin>>a>>b;
		cout<<"Scenario #"<<i<<":"<<endl;
		if(a%2 && b%2)
			cout<<double(a*b+0.4142)<<endl;
		else
			cout<<double(a*b)<<endl; 
		cout<<endl;
	}
	return 0;
}