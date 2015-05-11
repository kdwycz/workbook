/*
ID: kdwycz
PROG: friday
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;
const int p[13]={1,3,3,0,3,2,3,2,3,3,2,3,2};

int prime(int y);
int main(int argc, char *argv[])
{
	ofstream fout ("friday.out");	
	ifstream fin ("friday.in");
	int n,i,j,s,a[7]={0};
	fin>>n; s=3;
	for(i=1900;i<=1899+n;++i)
		for(j=1;j<=12;++j){
			if(j!=3) s+=p[j];
				else if(prime(i)) s+=p[0];
			s%=7;
			a[(s+1)%7]++;
		}
	for(i=0;i<6;++i) fout<<a[i]<<" ";
	fout<<a[6]<<endl;	
	return 0;
}

int prime(int y){
	if (((y%4==0)&&(y%100!=0))||(y%400==0)) return 1;
	return 0;	
}