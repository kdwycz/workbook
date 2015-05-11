#include <iostream>
#include <algorithm>
using namespace std;

long long a[110],b[10010],ans;
int n;

int main()
{
    while (cin>>n){
        for (int i=1;i<=n;++i)
            cin>>a[i];
        int k=1;
        for (int i=1;i<n;++i)
            for (int j=i+1;j<=n;++j){
                b[k++]=a[i]+a[j];
            }
        sort(b+1,b+k);
        ans=b[1];
        for (int i=2;i<k;++i)
            if (b[i]!=b[i-1])
                ans+=b[i];
        cout<<ans<<endl;
    }
    return 0;
}
