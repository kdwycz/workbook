#include <iostream>
using namespace std;
int a[2][5001]={0},n,i,j;
string s;
int main()
{
	cin>>n>>s;
	for (i=1;i<=n;++i)
		for (j=1;j<=n;++j)
			if (s[i-1]==s[n-j])
				a[i%2][j]=a[(i-1)%2][j-1]+1;
			else a[i%2][j]=a[(i-1)%2][j]>a[i%2][j-1]?a[(i-1)%2][j]:a[i%2][j-1];
	cout<<n-a[n%2][n]<<endl;
	return 0;
} 
