#include <iostream>
#include <cmath>
using namespace std;

int arr[381968][2],i,m,n,k;
int main()
{
	arr[0][0]=arr[0][1]=0;
	for (i=1;;++i){
		arr[i][0]=(i*(1+sqrt(5))/2);
		arr[i][1]=arr[i][0]+i;
		if (arr[i][1]>1000000) break;
	}
	
	while (cin>>m>>n && (m || n)){
		k=n-m;
		if (int(k*(1+sqrt(5))/2)==m)
			cout<<"0\n";
		else{
			cout<<"1\n";
			if (m>arr[k][0])
				cout<<arr[k][0]<<' '<<arr[k][1]<<endl;
			for (i=0;arr[i][1]<n;++i)
				if (m==arr[i][0]&&n>arr[i][1] || n==arr[i][1]&&m>arr[i][0] || m==arr[i][1])
					cout<<arr[i][0]<<' '<<arr[i][1]<<endl;
		}
	}
	
	return 0;
}
