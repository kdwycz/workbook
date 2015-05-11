#include <iostream>
using namespace std;
string s1="Apple",s2="iPhone",s3="iPod",s4="iPad",s5="Sony";
int main()
{
    string s,ss;
    while (cin>>s){
        for (int i=0;i<=s.size();++i){
            if (s[i]=='A'){
                ss=s.substr(i,5);
                if (ss==s1)
                    cout<<"MAI MAI MAI!\n";
            }
            else if (s[i]=='i'){
                ss=s.substr(i,6);
                if (ss==s2)
                    cout<<"MAI MAI MAI!\n";
                ss=s.substr(i,4);
                if (ss==s3 || ss==s4)
                    cout<<"MAI MAI MAI!\n";
            }
            else if (s[i]=='S'){
                ss=s.substr(i,4);
                if (ss==s5)
                    cout<<"SONY DAFA IS GOOD!\n";
            }
        }
    }
    return 0;
}
