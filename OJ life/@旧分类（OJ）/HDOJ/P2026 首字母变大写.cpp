#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a; int j;
    while(getline(cin,a)){
        a[0]-=32;
        j=a.length();
        for(int i=1;i<j;++i)
              if (a[i]==' ') a[i+1]-=32;
        cout<<a<<endl;
    }
    return(0);
}