#include <iostream>
#include <cstring>
using namespace std;
int cha[128];
string s;
int T,n,m;
int main()
{
    cin>>T;
    while (T--){
        cin>>n>>m;
        memset(cha,0,sizeof(cha));
        for (int i=1;i<=n;++i){
            cin>>s;
            for (int j=0;j<s.size();++j)
                cha[s[j]]++;
        }
        if (cha['I']>=m && cha['L']>=m && cha['O']>=m && cha['V']>=m && cha['E']>=m && cha['U']>=m)
            cout<<"KK will have a girlfriend!\n";
        else
            cout<<"KK can only have gay friend~\n";
    }

    return 0;
}
