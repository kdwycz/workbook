#include <iostream>
using namespace std;
string s;
int l,i,j,p[1000010];
int main()
{
	ios::sync_with_stdio(false);
	while (cin>>s && s!="."){
		l=s.size();
		j=-1; p[0]=-1;
		for (i=1;i<l;++i){
			while (j>-1 && s[i]!=s[j+1]) j=p[j];
			if (s[i]==s[j+1]) ++j;
			p[i]=j;
		}
		i=l-p[l-1]-1;
		if (l%i==0) cout<<l/i<<endl; 
		else cout<<"1\n";
	}
	return 0;
} 
