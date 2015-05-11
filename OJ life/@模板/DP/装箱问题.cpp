#include <iostream>
using namespace std;
int a[40],b[20010],i,j,v;
int main(int argc, char *argv[])
{
	cin>>v>>a[0];
	for (i=1;i<=a[0];++i) cin>>a[i];
	memset(b,0,sizeof(b));
	b[0]=1;
	for (i=1;i<=a[0];++i)
		for (j=v;j>=a[i];--j)
			if (b[j-a[i]]) b[j]=1;
	i=v; while (!i) --i;
	cout<<v-i<<endl;
	return 0;
}
 