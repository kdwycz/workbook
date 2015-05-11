#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int i,n,ii;
    cin>>n;
    getline(cin,s);
    while (n--){
          getline(cin,s); ii=0;
          for(i=0;i<s.length();++i)
            if (s[i]<0){ //首位为1的话。。。因为是补码，不解释了 
            	++ii;
            	++i;
            }
    cout<<ii<<endl;
    }           
}
