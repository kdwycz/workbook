#include <iostream>
using namespace std;
const int MAX=4000*4000+1;
int h[MAX]={0},t[MAX]={0};
int n,i,j,a[4000],b[4000],c[4000],d[4000],p,sum=0;

int hash(int x){
	int y=x%MAX;
	if (y<0) y+=MAX;
	while (h[y]!=0&&t[y]!=x)
		y=(y+1)%MAX;
	return y;
}

int main()
{
	cin>>n;
	for (i=0;i<n;++i)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	for (i=0;i<n;++i)
		for (j=0;j<n;++j){
			p=hash(a[i]+b[j]);
			h[p]++;
			t[p]=a[i]+b[j];
		}
	for (i=0;i<n;++i)
		for (j=0;j<n;++j){
			p=hash(-c[i]-d[j]);
			sum+=h[p];
		}
	cout<<sum<<endl;
	return 0;
}
