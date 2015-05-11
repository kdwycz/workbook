#include <iostream>
using namespace std;

long long f[60],n;
int i;

int main()
{
	f[0]=0; f[1]=1;
	for (i=2;i<55;++i)
		f[i]=f[i-1]+f[i-2];
	
	while (cin>>n && n){
		for (i=3;n!=f[i] && i<54;++i);
		if (n==f[i])
			cout<<"Second win\n";
		else
			cout<<"First win\n";
	}
	
	return 0;
} 
