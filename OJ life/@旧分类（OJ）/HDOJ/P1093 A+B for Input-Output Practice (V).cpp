#include<iostream>
using namespace std;
int main()
{
    int a,s,m,n,i,j;
    cin>>m;
    for(j=0;j<m;++j)
    {
        s=0; cin>>n;
        for(i=0;i<n;++i)
        {
            cin>>a;
            s+=a;
        }
        cout<<s<<endl;
    }
    return(0);
}