#include <iostream>
using namespace std;
string s[10],temp,ans;
int n,m,i,j,i1,j1,l,p[60],flag;

int kmp(int x){
	int j=-1;
	for (int i=0;i<s[x].size();++i){
		while (j>-1 && s[x][i]!=temp[j+1]) j=p[j];
		if (s[x][i]==temp[j+1]) j++;
		if (j+1==l) return 1;
	}
	return 0;
}

int main()
{
	cin>>n;
	while (n--){
		cin>>m; ans=" ";
		for (i=0;i<m;++i)
			cin>>s[i];
		for (i=0;i<58;++i)
			for (j=3;j<61-i;++j){
				temp=s[0].substr(i,j);
				l=temp.size();
				j1=-1; p[0]=-1;
				for (i1=1;i1<l;++i1){
					while (j1>-1 && temp[i1]!=temp[j1+1]) j1=p[j1];
					if (temp[i1]==temp[j1+1]) j1++;
					p[i1]=j1;
				} 
				flag=true;
				for (i1=1;i1<m && flag;++i1)
					if (!kmp(i1))
						flag=false;
				if (flag)
					if (l>ans.size() || (l==ans.size() && temp<ans))
						ans=temp;
			}
		if (ans==" ")
			cout<<"no significant commonalities\n";
		else cout<<ans<<endl;
	}
	return 0;
} 
