#include <iostream>
#include <string>
using namespace std;

string s1,s2;
int l1,l2,p[10010],i,j,n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	while (n--){
		cin>>s2>>s1;
		l1=s1.size();
		l2=s2.size();	
		p[0]=-1; j=-1;
		for (i=1;i<l2;++i){
			while (j>-1 && s2[j+1]!=s2[i]) j=p[j];
			if (s2[j+1]==s2[i]) ++j;
			p[i]=j;
		}
		j=-1; int ans=0;
		for (i=0;i<l1;++i){
			while (j>-1 && s1[i]!=s2[j+1]) j=p[j];
			if (s1[i] == s2[j+1]) ++j;
			if (j+1==l2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
} 
