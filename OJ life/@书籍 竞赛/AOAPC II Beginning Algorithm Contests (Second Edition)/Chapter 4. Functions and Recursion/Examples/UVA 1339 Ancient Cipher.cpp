#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

string s1,s2;
int a1[27],a2[27],flag;
int main()
{
    while (cin>>s1>>s2){
        flag=1;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for (int i=0;i<s1.size();++i)
            a1[s1[i]-'A']++;
        for (int i=0;i<s2.size();++i)
            a2[s2[i]-'A']++;
        sort(a1,a1+26,cmp);
        sort(a2,a2+26,cmp);
        for (int i=0;i<26&&flag;++i)
            if (a1[i]!=a2[i])
                flag=0;
        if (flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
