#include <iostream>
using namespace std;
int main()
{
	long long m,n,a,b,suma,sumb;
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>n;
		suma=sumb=0;
		while (n--){
			cin>>a>>b;
			while (a>1&&b>1){
				a>>=1;
				b>>=1;
			}
			if (a>b)
				suma+=a;
			else
				sumb+=b;
		}
		cout<<"Case "<<i<<": ";
		cout<<(suma>sumb?"Alice\n":"Bob\n");
	}
	return 0;
}
