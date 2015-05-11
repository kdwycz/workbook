// zoj 3818
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n; string s;
    cin>>n; getline(cin,s);
    while (n--){
        getline(cin,s);
        for (int i=0;i<s.size();++i){
            if (!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))){
                s.erase(i,1);
                i--;
            }
        }

        int l=2,flag1=0;
        while ((!flag1) && (l*2<s.size())){
            string s1=s.substr(0,l);
            string s2=s.substr(l,l);
            string s3=s.substr(2*l,50);
            if (s3.size()<s1.size() && s1==s2 && s1.find(s3)==0){
                string s4=s1.substr(s3.size(),50);
                if (s3!=s4)
                    flag1=true;
            }

            l++;
        }

        l=2; int flag2=0;
        while ((!flag2) && l*3<s.size()){
            string s1=s.substr(0,l);
            string s2=s.substr(l,l);
            string s3=s.substr(s.size()-l,l);
            if (s1==s2 && s2==s3 && l*3<s.size()){
                string s4=s.substr(l+l,s.size()-3*l);
                int ff=false;
                for (int i=1;!ff && i<s1.size();++i){
                    string s5=s1.substr(0,i);
                    string s6=s1.substr(i,s.size());
                    if (s4!=s5 && s5!=s6 && s4!=s6) ff=true;
                }
                if (ff) flag2=true;
            }
            ++l;
        }
        if (flag1 || flag2)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}