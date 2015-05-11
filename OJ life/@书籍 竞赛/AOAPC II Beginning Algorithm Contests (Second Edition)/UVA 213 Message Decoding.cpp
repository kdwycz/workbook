#include <iostream>
#include <string>

char dict[1025];
string s;

int main()
{
	while (getline(cin,s)){
		int j=2,k=4;
		for (int i=0;i<=s.size()){
			if (j==k-1){
				++j; k*=2;
			}
			dict[j]=s[i];
			++j;
		}
		
	}	
	return 0;
}
