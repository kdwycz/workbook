#include <iostream>
using namespace std;
int gcd(int,int);
int main(int argc, char *argv[])
{
	int a,n,m; long long s;
	cin>>m;
	for (int i=1;i<=m;++i){
		cin>>n; s=1;
		for(int j=1;j<=n;++j){
			cin>>a;
			s=s*a/gcd(s,a);
		}
		cout<<s<<endl;
	} 
	return 0;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
