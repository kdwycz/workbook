#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a;
    while (cin>>a){
        if (a<=1){
            cout<<"0\n";
            continue;
        }

        int b=a,c=1;
        for (int i=2;i<=sqrt(b);++i)
            if (b%i==0){
                c*=i;
                b/=i;
                i=1;
            }
        cout<<c<<endl;
    }
    return 0;
}
