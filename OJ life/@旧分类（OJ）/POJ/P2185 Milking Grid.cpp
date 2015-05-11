#include <iostream>
using namespace std;

string s[10010],a;
int p[10010],i,j,x,y,r,c,f[80]={0};

int main()
{
	ios::sync_with_stdio(false);
	cin>>r>>c;
	for (i=0;i<r;++i){
		cin>>s[i];
		a=s[i];
		for (j=c-1;j>0;--j){
			a[j]=0;
			for (x=0,y=0;s[i][y];++x,++y){
				if (!a[x]) x=0;
				if (a[x]!=s[i][y]) break;
			}
			if (!s[i][y]) f[j]++;
		}
	}
	for (i=0;i<c;++i) if (f[i]==r) break;
	x=i;
	for (i=0;i<r;++i) s[i][x]=0;
	p[0]=-1; j=-1;
	for (i=1;i<r;++i){
		while (j>-1 && s[i]!=s[j+1]) j=p[j];
		if (s[i]==s[j+1]) j++;
		p[i]=j;
	}
	cout<<(r-1-p[r-1])*x<<endl;
	return 0;
}
