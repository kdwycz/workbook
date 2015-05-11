#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s; char t;
    while(cin>>s){
        for(int i=0;i<2;++i)
          for(int j=i+1;j<3;++j)
            if (s[i]>s[j]) {
                t=s[i]; s[i]=s[j]; s[j]=t;
            }
        cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
    } 
    return(0);
}