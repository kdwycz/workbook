#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a,b,flag;
	while (cin>>a>>b && (a || b)){
		flag=1;
		while (1){
			if (a<b) swap(a,b);
			if ((a/b>=2) || (a%b==0) || (b==0)){
				if (flag)
					cout<<"Stan wins\n";
				else
					cout<<"Ollie wins\n";
				break;
			}
			a-=b;	
			flag^=1;
		}
	}
	return 0;
} 
