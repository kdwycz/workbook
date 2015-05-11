/*
ID: kdwycz
PROG: ride
LANG: C++
*/

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b; int sa,sb,i;
	fin>>a>>b;
	sa=1; sb=1;
	for(i=0;i<=a.length()-1;++i) 
		sa*=(a[i]-'A'+1);
	for(i=0;i<=b.length()-1;++i) 
		sb*=(b[i]-'A'+1);
	if(sa%47==sb%47) fout<<"GO"<<endl;
		else fout<<"STAY"<<endl;
	
	return 0;
}