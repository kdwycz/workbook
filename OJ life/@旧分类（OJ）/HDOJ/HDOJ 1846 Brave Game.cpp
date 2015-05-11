#include <iostream>
using namespace std;
int main()
{
 	int c,m,n;
 	cin>>c;
 	while (c--){
 		cin>>m>>n;
 		if (m%(n+1)!=0)
 			cout<<"first\n";
 		else
 			cout<<"second\n";
 	}
	return 0;
}

