#include <iostream>
using namespace std;

string a[12],b[12],s="............";
char c; 

int make(int x,int y){
	int i,j,ans=0;
	for (i=x-1;i<=x+1;++i)
		for (j=y-1;j<=y+1;++j)
			if (a[i][j]=='*')
				ans++;
	return ans;
}

int main()
{
	int n,i,j;
	cin>>n; c='.';
	for (i=1;i<=n;++i){
		cin>>a[i];
		a[i]='.'+a[i]+'.';
	}
	for (i=1;i<=n;++i){
		cin>>b[i];
		b[i]='.'+b[i]+'.';
		for (j=1;j<=n;++j)
			if (a[i][j]=='*' && b[i][j]=='x')
				c='*';
	}
	a[n+1]=b[n+1]=s;
		
	for (i=1;i<=n;++i,cout<<endl)
		for (j=1;j<=n;++j)
			if (a[i][j]=='*')
				cout<<c;
			else if (b[i][j]=='x')
				cout<<make(i,j);
			else
				cout<<'.';
	return 0;
} 
