#include <iostream>
using namespace std;

int lowbit(int x){
	return x & -x;
} 

int main()
{
	int n,x;
	cin>>n;
	while (n--){
		cin>>x;
		cout<<x-lowbit(x)+1<<' '<<x+lowbit(x)-1<<endl;
	}
	return 0;
}
