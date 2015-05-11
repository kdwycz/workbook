#include <iostream>
#include <algorithm>
using namespace std;
int a[6],t;
int main()
{
	cin>>t;
	while (t--){
		for (int i=0;i<6;++i)
			cin>>a[i];
		sort(a,a+6);
		if (a[4]+a[5]>a[1]+a[2]+a[3])
			cout<<"Grandpa Shawn is the Winner!\n";
		else
			cout<<"What a sad story!\n";
	}
	return 0;
}
