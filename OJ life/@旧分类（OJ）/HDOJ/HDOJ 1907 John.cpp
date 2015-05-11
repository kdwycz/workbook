#include <iostream>
using namespace std;
int main()
{
	int t,n,a,b,c,i;
	cin>>t;
	while (t--){
		b=c=0;
		cin>>n;
		for (i=1;i<=n;++i){
			cin>>a;
			if (a>1) c++;
			b^=a;
		}
		if ((c==0 && b==0)||(c && b))
			cout<<"John\n";
		else
			cout<<"Brother\n";
	}
	return 0;
}
