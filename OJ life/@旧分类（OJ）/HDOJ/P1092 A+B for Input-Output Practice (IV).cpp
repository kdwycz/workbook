#include<iostream>
using namespace std;
int main()
{
    int a,s,i,n;
    while(cin>>n&&n!=0)
    {
        s=0;
        for(i=0;i<n;++i)
        {
            cin>>a;
            s+=a;
        }
        cout<<s<<endl;
    }
    return(0);
}