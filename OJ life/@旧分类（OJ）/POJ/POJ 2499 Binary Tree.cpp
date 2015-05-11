#include <iostream>
using namespace std;

int n,i,a,b,right1,left1,up;

int main()
{
	cin>>n;
	for (i=1;i<=n;++i){
		cin>>a>>b;
		left1=right1=0;
		while (a>1 || b>1)
			if (a>b){
				up=(a-1)/b;
				left1+=up;
				a-=up*b;
			}
			else{
				up=(b-1)/a;
				right1+=up;
				b-=up*a;
			}
		cout<<"Scenario #"<<i<<":"<<endl<<left1<<" "<<right1<<endl<<endl;
	}
	return 0;
}
