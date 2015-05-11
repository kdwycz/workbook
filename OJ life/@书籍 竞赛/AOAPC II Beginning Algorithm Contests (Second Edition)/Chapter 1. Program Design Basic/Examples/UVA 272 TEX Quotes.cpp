#include <iostream>
using namespace std;
int main()
{
	string s;
	int flag=1;
	while (getline(cin,s)){
		for (int i=0;i<s.size();++i)
			if (s[i]=='"'){
				if (flag)
					cout<<"``";
				else
					cout<<"''";
				flag^=1;
			}
			else
				cout<<s[i];
		cout<<endl;
	}
	return 0;
}
