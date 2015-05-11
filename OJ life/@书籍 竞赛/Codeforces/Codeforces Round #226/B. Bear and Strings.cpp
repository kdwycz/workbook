#include <iostream>
using namespace std;
string s1,s2="bear";
int l1,l2=4,i,j,n,lasti=0;
int main()
{
	cin>>s1;
	l1=s1.size();	
	j=-1; int ans=0;
	for (i=0;i<l1;++i){
		while (j>-1 && s1[i]!=s2[j+1]) j=-1;
		if (s1[i] == s2[j+1]) ++j;
		if (j+1==l2){
		//	cout<<i<<' '<<(i-2-lasti)*(l1-i)<<endl;
			ans+=(i-2-lasti)*(l1-i);
			lasti=i-2;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
