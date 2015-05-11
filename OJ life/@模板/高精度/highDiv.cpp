/*
PROG:模板 高精度除法  
AUTHOR:12嵌入式 李思辰 
*/
#include <iostream>
#include <string> 
using namespace std;

void right(int a[]);
int compare(int a[],int b[]); 
void sub(int a[],int b[],int c[]);
 
const int maxl=100;
string sa,sb,stem;
int a[maxl]={0},b[maxl]={0},c[maxl]={0},d[maxl]={0},i,j,k,len;
int main(int argc, char *argv[])
{
	cin>>sa>>sb;
	a[0]=sa.size();
	b[0]=sb.size();
	for (i=1;i<=a[0];++i) a[i]=sa[a[0]-i]-'0';
	for (i=1;i<=b[0];++i) b[i]=sb[b[0]-i]-'0';
	len=a[0]; d[0]=1;
	for (i=len;i;--i){
		right(d);
		d[1]=a[i];
		while (compare(d,b)>=0){
			sub(d,b,d);
			c[i]++;
		}
	}
	while (len-1 && !c[len]) len--;
	c[0]=len;
	for (i=c[0];i;--i) cout<<c[i];  cout<<endl;	
	for (i=d[0];i;--i) cout<<d[i];  cout<<endl;			
	return 0;
}

void right(int a[]){
	for (int i=a[0];i;--i){
		a[i+1]=a[i];
	}
//	a[1]=0; 
	if (a[a[0]+1]) a[0]++;
}

int compare(int a[],int b[]){
	if (a[0]<b[0]) return -1;
	for (int i=a[a[0]];i;--i)
		if (a[i]>b[i]) return 1;
	return 0;
}

void sub(int a[],int b[],int c[]){
	c[0]=a[0];
	for (int i=1;i<=c[0];++i){
		c[i]=a[i]-b[i];
		if (c[i]<0){
			c[i]+=10; c[i+1]--;
		} 
	}
	while (c[0] && !c[c[0]]) c[0]--;
}
