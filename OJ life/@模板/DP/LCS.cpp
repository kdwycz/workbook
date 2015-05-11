/*
LCS 
        
	   \=0 (i==0||j==0)
a[i][j]\=a[i-1][j-1]+1 (s1[i]==s2[j])
	   \=max(a[i-1][j],a[i][j-1]) (s1[i]!=s2[j])
*/   

#include <iostream>
using namespace std;
const int maxn=10000;
string s1,s2;
void find(int,int);
int n,i,j,a[maxn][maxn]={0},b[maxn]={0};
int main()
{
	 cin>>s1>>s2;
	 for (i=1;i<=s1.length();++i)
	 	for (j=1;j<=s2.length();++j)
	 		if (s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1]+1;
	 		else a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
	 cout<<a[s1.length()][s2.length()]<<endl;
	 find(s1.length(),s2.length());
	 for (i=b[0];i;--i) cout<<s1[b[i]]<<' ';
	 cout<<endl;
	 return 0;		
}

void find(int m,int n){
	if (!a[m][n]) return;
	else if (s1[m-1]==s2[n-1]){
		b[0]++; b[b[0]]=m-1;
		find(m-1,n-1);
	}	else if (a[m-1][n]>a[m][n-1]) find(m-1,n);
			else find(m,n-1);
		
}
