#include<iostream>
using namespace std;
int main()
{
    int a,s,n;
    while(cin>>n)
    {
        s=0;
        while(n>0)
        {
            cin>>a;
            s+=a;
            --n;
        }
        cout<<s<<endl;
     }
     return(0);
}