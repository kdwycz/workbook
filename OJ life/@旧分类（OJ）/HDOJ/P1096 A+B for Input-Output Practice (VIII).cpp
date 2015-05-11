#include<iostream>
using namespace std;
int main()
{
    int a,s,n,m;
    cin>>m;
    do 
    {
        cin>>n;
        s=0;
        while(n>0)
        {
            cin>>a;
            s+=a;
            --n;
        }
        cout<<s<<endl;
        if (m>1) cout<<endl;
        --m;
    } while (m>0);
    cin>>a>>s;
    return(0);
}