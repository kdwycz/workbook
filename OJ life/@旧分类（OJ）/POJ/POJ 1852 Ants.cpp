#include <iostream>
using namespace std;
int main()
{
	int l,m,n,a,max,min;
	ios::sync_with_stdio(false);
	cin>>n;
	while (n--){
		cin>>l>>m;
		max=min=0;
		while (m--){
			cin>>a;
			a=a>l-a?a:l-a;
			max=max<a?a:max;
			min=min<l-a?l-a:min;
		}
		cout<<min<<' '<<max<<endl;
	}
	return 0;
} 
