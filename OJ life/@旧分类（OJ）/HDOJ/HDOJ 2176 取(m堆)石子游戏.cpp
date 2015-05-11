#include <iostream>
using namespace std;
int a[200001],m,i,ans;
int main()
{
	std::ios::sync_with_stdio(false);
	while (cin>>m && m){
		ans=0;
		for (i=1;i<=m;++i){
			cin>>a[i];
			ans^=a[i]; 
		}
		if (ans==0)
			cout<<"No\n";
		else{
			cout<<"Yes\n";
			for (i=1;i<=m;++i)
				if (a[i]>(ans^a[i]))
					cout<<a[i]<<' '<<(ans^a[i])<<endl; 
		}
	}
	return 0;
} 
