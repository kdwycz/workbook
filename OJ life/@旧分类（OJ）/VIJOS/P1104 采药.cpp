#include <iostream>
using namespace std;
struct medic{
	int w,p;
};
medic a[110];
int f[1001]={0},t,m,i;

void ZeroOnePack(int f[],medic);
int main()
{
	cin>>t>>m;
	for (i=1;i<=m;++i) cin>>a[i].w>>a[i].p;

	for (i=1;i<=m;++i) ZeroOnePack(f,a[i]);
	cout<<f[t]<<endl;
	return 0;
} 

void ZeroOnePack(int f[],medic a){
	for (int i=t;i>=a.w;--i)
		f[i]=f[i-a.w]+a.p>f[i]?f[i-a.w]+a.p:f[i];
	return;
}
