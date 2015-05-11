/*
ID:kdwycz
PROG:gift1
LANG:C++ 
*/

#include <iostream>
#include <fstream>
using namespace std;
struct person{
	string name;
	int pay,income;
}a[11];
int n,i,j,k,l; string s;

int find(string);
int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	fin>>n;
	for (i=1;i<=n;++i){
		fin>>a[i].name;
		a[i].pay=0;
		a[i].income=0;
	}
	while (fin>>s){
		i=find(s);
		fin>>a[i].pay>>l;
		if (l!=0){
			j=a[i].pay/l;
			a[i].pay=l*j;
		}
		for (k=0;k<l;++k){
			fin>>s;
			a[find(s)].income+=j;
		}
	}
	for (i=1;i<=n;++i)
		fout<<a[i].name<<' '<<a[i].income-a[i].pay<<endl;
	return 0;	
}

int find(string s){
	for (int i=1;i<=n;++i)
		if (a[i].name == s) return i;
}
