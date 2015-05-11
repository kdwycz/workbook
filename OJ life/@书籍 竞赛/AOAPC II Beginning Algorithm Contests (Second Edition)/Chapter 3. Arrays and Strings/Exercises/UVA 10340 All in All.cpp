#include <iostream>
using namespace std;

string s1,s2;

int main()
{
    while (cin>>s1>>s2){
        int i=0;
        for (int j=0;j<s2.size()&&i<s1.size();++j)
            if (s1[i]==s2[j]) i++;
        if (i==s1.size())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
