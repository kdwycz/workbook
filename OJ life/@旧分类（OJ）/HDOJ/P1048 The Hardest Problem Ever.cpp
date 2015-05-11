#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int i;
    while(getline(cin,s)&&s!="ENDOFINPUT")
    {
        if ((s!="START")&&(s!="END"))
        {
            for(i=0;i<=s.size()-1;++i)
            {
                if((s[i]<='Z')&&(s[i]>='F'))
                   s[i]=s[i]-5;
                else
                switch(s[i])
                {
                  case 'A': s[i]='V'; break;
                  case 'B': s[i]='W'; break;
                  case 'C': s[i]='X'; break;
                  case 'D': s[i]='Y'; break;
                  case 'E': s[i]='Z'; break;
                }
            }
            cout<<s<<endl;
        }
     }
     return(0);
}