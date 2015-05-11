#include <iostream>
using namespace std;
struct map{
	int step,point;
}a[100100];
int n,k,i,t,fa,so,line[100100]={0};

int main()
{
	cin>>n>>k;
	line[n]=1;
	fa=0; so=0;
	a[fa].point=n; a[fa].step=0; 
	while (so>=fa){
		for (i=-1;i<2;++i){
			if (i) t=a[fa].point+i;
			else t=a[fa].point*2;
			if (t>=0 && t<=100000 && !line[t])
				if (t==k){
					cout<<a[fa].step+1<<endl; 
					return 0;
				}
				else{
					so++; line[t]=1;
					a[so].point=t;
					a[so].step=a[fa].step+1;
				}
		}
		fa++;
	}
	cout<<0<<endl;
	return 0;
}
