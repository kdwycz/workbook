#include <iostream>
#include <cmath> 
using namespace std;
int main(int argc, char *argv[])
{
	int t,n;
 	double PI = acos(-1.0),e = exp(1.0);
 	cin>>t;
 	for (int i=0;i<t;++i) {
		cin>>n;
 		n=log10(sqrt(2*PI*n))+(n*log10(n/e))+1;
 		cout<<int(n)<<endl;
  }
	return 0;
}



/* ¹«Ê½ log10(n!)=log10(1*2*3¡­*n)=log10(1)+log10(2)+¡­+log10(n)   968MS
#include <iostream>
#include <cmath> 
using namespace std;
int main(int argc, char *argv[])
{
	int t,i,j,n; double sum;
	cin>>t;
	for (i=0;i<t;++i){
		cin>>n; sum=0.0;
		for(j=1;j<=n;++j)
			sum+=log10(j);
		cout<<round(sum+0.5)<<endl;
	}
	return 0;
}
*/

