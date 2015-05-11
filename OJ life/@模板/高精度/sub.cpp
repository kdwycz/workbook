/*
PROG:模板 高精度减法 a-=b a,b>=0
AUTHOR:12嵌入式 李思辰 
*/
#include <iostream>
#include <string>
using namespace std;
const int maxl=100;
string sa,sb,stem;
int a[maxl]={0},b[maxl]={0},i,j,k,len;
bool flag=0;
int main(int argc, char *argv[])
{
	cin>>sa>>sb;
	if (sb>sa){
		stem=sa; sa=sb; sb=stem; flag=true;
	} 
	a[0]=sa.size();
	b[0]=sb.size();
	for (i=1;i<=a[0];++i)
		a[i]=sa[a[0]-i]-'0';
	for (i=1;i<=b[0];++i)
		b[i]=sb[b[0]-i]-'0';
	len=a[0];

	for (i=1;i<=len;++i){
		a[i]-=b[i];
		if (a[i]<0){
			a[i]+=10; a[i+1]--;
		} 
	}
	
	while (a[0] && !a[a[0]]) a[0]--;
	if (!a[0]) cout<<"0";
	else {
		if (flag) cout<<'-';
		for (i=a[0];i;--i) cout<<a[i];
	}
	cout<<endl; 
	return 0;
}


