#include <iostream>
using namespace std;
const int x[10]={1,2,4,8,16,32,64,128,256,512};

int n,pn[2000]={0};

int main()
{
	for (int i=0;i<=1000;++i)
		if (!pn[i])
			for (int j=0;j<10;++j)
				pn[i+x[j]]=1;

	while (cin>>n)
		if (pn[n])
			cout<<"Kiki\n";
		else
			cout<<"Cici\n";
	return 0;
}
