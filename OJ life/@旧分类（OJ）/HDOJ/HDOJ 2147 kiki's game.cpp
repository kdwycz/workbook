#include <iostream>
using namespace std;
int main()
{
	int n,m;
	while (cin>>n>>m && n && m){
		if (m%2 && n%2)
			cout<<"What a pity!"<<endl;
		else
			cout<<"Wonderful!"<<endl; 
	}
	return 0;
} 
