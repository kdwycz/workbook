#include<iostream>
using namespace std;
int main()
{
	double a,b,i;
	cin>>a;
	while(a!=0){
		i=2; b=0;
		while(a>b){
			b+=1/i;
			++i;
		}
		cout<<int(i-2)<<" card(s)"<<endl;
		cin>>a;
	}
	return 0;
}