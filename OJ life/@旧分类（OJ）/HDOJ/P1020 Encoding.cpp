#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	string s; int ii,n;
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>s; 
		for (int j=0;j<s.length();++j){
			ii=1;
			while ((s[j+1]==s[j])&&(j<s.length()-1)){
				++j; ++ii;
			}
			if (ii>1) cout<<ii;
			cout<<s[j];
		}
	cout<<endl;
	}
	return 0;
}
