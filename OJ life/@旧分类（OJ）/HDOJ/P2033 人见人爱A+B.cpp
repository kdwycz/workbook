#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,d,e,f,i;
    cin>>i;
    while (i-->0){
        cin>>a>>b>>c>>d>>e>>f;
        a+=d; b+=e; c+=f;
        b+=(c/60); c=c%60;
        a+=(b/60); b=b%60;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return(0);
}