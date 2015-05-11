#include<iostream>
using namespace std;
int main()
{
    int a,b,n;
    cin>>n;
    while(n>0)
    {
      cin>>a>>b;
      cout<<a+b<<endl;
      --n;
    }
    return (0);
}