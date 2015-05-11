#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int n;
	while (cin>>n)
		if(n%4==2) cout<<"yes\n";
		else cout<<"no\n";
	return 0;
}
