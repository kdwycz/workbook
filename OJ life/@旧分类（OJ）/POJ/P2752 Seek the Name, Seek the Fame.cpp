#include <iostream>
using namespace std;
const int N=400001;
string s;
int p[N],ans[N],ls,i,j,temp;
int main()
{
	while (cin>>s){
		ls=s.size();
		j=-1; p[0]=-1;
		for (i=1;i<ls;++i){
			while (j>-1 && s[i]!=s[j+1]) j=p[j];
			if (s[i]==s[j+1]) j++;
			p[i]=j;
		}
		
		ans[0]=ls-1;
		j=0; i=ls-1;
		while (p[i]>-1){
			ans[++j]=p[i];
			i=p[i];
		}
		for (i=j;i;i--)
			cout<<ans[i]+1<<' ';
		cout<<ans[0]+1<<endl;
	}
	return 0;
} 
