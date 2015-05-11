#include <iostream>
using namespace std;
long long sum[10011]={0};
int main()
{
    for (int i=1;i<=10010;++i){
        sum[i]=(long long)i*i*i;
        sum[i]+=sum[i-1];
    }
    int n,a,b;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a>>b;
        cout<<"Case #"<<i<<": "<<sum[b]-sum[a-1]<<endl;
    }
    return 0;
}
