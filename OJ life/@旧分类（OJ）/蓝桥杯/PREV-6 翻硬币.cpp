#include <iostream>
using namespace std;
string a,b;
int i,ans=0;
int main()
{
	cin>>a>>b;
	for (i=0;i<a.size();++i)
		if (a[i]!=b[i]){
			ans++;
			a[i+1]=a[i+1]=='*'?'o':'*';
		}
	cout<<ans<<endl;
	return 0;
} 
