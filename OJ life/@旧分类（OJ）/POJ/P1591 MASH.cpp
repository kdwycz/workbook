#include <iostream>
#include <cstring>
using namespace std;

int i,j,n,m=0,x,a[20];
bool queue[51];

int main()
{
	while (cin>>n>>x){
		for (i=1;i<=20;++i)
			cin>>a[i];
		memset(queue,0,sizeof(queue));
		int flaga=1,flag=n;
		while (flag!=x){
			j=0;
			for (i=1;i<=n;++i){
				if (!queue[i]) j++;
				if (flag!=x && j==a[flaga]){
					j=0; flag--;
					queue[i]=true;
				}
			}
			flaga++;
		}
		cout<<"Selection #"<<m++<<endl;
		for (i=1;i<=n;++i)
			if (!queue[i]) cout<<i<<' '; 
		cout<<endl<<endl;
	}
	return 0;
} 
