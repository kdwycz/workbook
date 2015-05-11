/* 朴素算法 
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[])
{
	bool a[100001];
	int step,mod,i,s,flag;
	while (cin>>step>>mod){
		memset(a,0,sizeof(a));
		a[0]=1; s=0; flag=1;
		for(i=1;i<mod;++i){
			if (a[(s+step)%mod]){
				flag=0; continue;
			}
			s=(s+step)%mod;
			a[s]=0;
		}
		if (flag) cout<<setw(10)<<step<<setw(10)<<mod<<"    Good Choice"<<"\n\n";
  		   else cout<<setw(10)<<step<<setw(10)<<mod<<"    Bad Choice"<<"\n\n";
 	}
	return 0;
}
*/

//数学方法 
#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a,int b); 
int main(int argc, char *argv[])
{
	int step,mod;
	while (cin>>step>>mod)
		if (gcd(step,mod)==1) cout<<setw(10)<<step<<setw(10)<<mod<<"    Good Choice"<<"\n\n";
						 else cout<<setw(10)<<step<<setw(10)<<mod<<"    Bad Choice"<<"\n\n";
	return 0;
}

int gcd(int a,int b){
	return b? gcd(b,a%b):a;
}