#include <iostream>
#include <cstring>
using namespace std;
const int x[11]={1,2,4,8,16,32,64,128,256,512,1024};

int n,sg[1001]={0};

void solve(){
	int temp[1000],i,j=0;
	for (i=1;i<=1000;++i){
		memset(temp,0,sizeof(temp));
		while (i>=x[j]){
			temp[sg[i-x[j]]]=1;
			j++;
		}
		for (j=0;temp[j];++j);
		sg[i]=j; j=0;
	}
}

int main()
{
	solve();
	while (cin>>n)
		if (sg[n])
			cout<<"Kiki\n";
		else
			cout<<"Cici\n";
	return 0;
} 
