 #include <iostream>
using namespace std;
int main()
{
    double n;
    while (cin>>n){
        while (n>18)  n/=18;
        cout<<(n<=9?"Stan wins.\n":"Ollie wins.\n");
    }
    return 0;
}
