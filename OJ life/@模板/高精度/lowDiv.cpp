/*
PROG:模板 高精度除低精度 a/b=c a%b=d
AUTHOR:12嵌入式 李思辰 
*/
#include <iostream>
#include <string> 
using namespace std;
const int maxl=100;
string sa;
int a[maxl]={0},c[maxl]={0},b,d,i,j,len;
int main(int argc, char *argv[])
{
	cin>>sa>>b;
	if (0==b) return 0;
	a[0]=sa.size();
	for (i=1;i<=a[0];++i) a[i]=sa[a[0]-i]-'0';
	len=a[0]; d=0;
	for (i=len;i;--i){
		d=d*10+a[i];
		c[i]=d/b;
		d%=b;
	}
	while (len && !c[len]) --len;
	c[0]=len;
	if (0==c[0]){
		d=b;
		cout<<'0';
	}
	for (i=c[0];i;--i) cout<<c[i];
	cout<<endl<<d<<endl;
	
	return 0;
}
