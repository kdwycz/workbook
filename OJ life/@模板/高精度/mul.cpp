/*
PROG:模板 高精度乘法 a*b=c a,b>=0
AUTHOR:12嵌入式 李思辰 
*/
#include <iostream>
#include <string> 
using namespace std;
const int maxl=100;
string sa,sb,stem;
int a[maxl]={0},b[maxl]={0},c[maxl]={0},i,j,k,len;
int main(int argc, char *argv[])
{
	cin>>sa>>sb;
	a[0]=sa.size();
	b[0]=sb.size();
	for (i=1;i<=a[0];++i)
		a[i]=sa[a[0]-i]-'0';
	for (i=1;i<=b[0];++i)
		b[i]=sb[b[0]-i]-'0';
	
	for (i=1;i<=a[0];++i)
		for (j=1;j<=b[0];++j){
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	len=a[0]+b[0];
	while (len && !c[len]) len--;
	c[0]=len;
	
	if (0==c[0]) c[0]++;
	for (i=c[0];i;--i) cout<<c[i];
	cout<<endl;
	
	return 0;
}
