#include <iostream>
#include <cstring>
using namespace std;
string a[1100],s;
int b[1100],n,i,j,k,maxn; 
int main(int argc, char *argv[])
{
	 while((cin>>n)&&(n)){
	 	j=0; maxn=0;
	 	memset(b,0,sizeof(b));
	 	for (i=1;i<=n;++i){
	 		cin>>s;
	 		k=1;
	 		while((k<=j)&&(s!=a[k])) ++k;
	 		if (k<=j) ++b[k];
	 		else{
	 			++j;
	 			a[j]=s;
	 			b[j]=1;
	 		}
	 		maxn=maxn<b[k]?b[k]:maxn;
	 	}
	 	i=1; while (b[i]!=maxn) ++i;
	 	cout<<a[i]<<endl;
	 }
	return 0;
}


