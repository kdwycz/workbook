#include <iostream>
using namespace std;
int main()
{
	int a[101]={0},b[101]={0};
	int n,i,j,ans=0;
	
	cin>>n;
	
	cin>>j;
	if (j>0)
		a[j]=2;
	else
		b[-j]=2;

	for (i=1;i<n;++i){
		cin>>j;
		if (j>0)
			a[j]=1;
		else
			b[-j]=1;
	}
	
	while (n){
		if (a[99]>0){
			n--;
			if (a[99]==2)
				ans++;
			a[99]=0;
		}
		for (i=98;i;--i)
			if (a[i]){
				a[i+1]=a[i];
				a[i]=0;
				if (b[i+1] && (b[i+1]==2 || a[i+1]==2))
					a[i+1]=b[i+1]=2;
			}
			
		if (b[1]>0){
			n--;
			if (b[1]==2)
				ans++;
			b[1]=0;
		}
		for (i=2;i<100;++i)
			if (b[i]){
				b[i-1]=b[i];
				b[i]=0;
				if (a[i-1] && (b[i-1]==2 || a[i-1]==2))
					a[i-1]=b[i-1]=2;
			}
	}
	cout<<ans<<endl;
	return 0;
}
