#include <iostream>
using namespace std;
int main()
{
	int m,n,k,ans;
	cin>>m;
	while (m--){
		cin>>n;
		ans=0;
		while (n--){
			cin>>k;
			if (k%4==1 || k%4==2)
				ans^=k;
			else if (k%4==0)
				ans^=(k-1);
			else
				ans^=(k+1);
		}
		if (ans) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
} 
