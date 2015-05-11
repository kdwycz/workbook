/*
ID: kdwycz
PROG: gift1
LANG: C++
*/

#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	string s[12],ss;
	int a[12],n,m,i,x,j,y;
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	fin>>n;
	for(i=1;i<=n;++i) fin>>s[i];
	memset(a,0,sizeof(a));
	while (fin>>ss){
		i=1;
		while(s[i]!=ss) ++i;
		fin>>y>>m;
		if(m!=0){ 
			x=y/m; y=-x*m; a[i]+=y;
			for(j=1;j<=m;++j){
				fin>>ss; i=1;
				while(s[i]!=ss) ++i;
				a[i]+=x;
			}
		}
	}
	for(i=1;i<=n;++i) 
		fout<<s[i]<<" "<<a[i]<<endl;
	
	
	return 0;
}