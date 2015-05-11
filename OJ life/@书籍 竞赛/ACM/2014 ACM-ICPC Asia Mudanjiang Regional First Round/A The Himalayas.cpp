// zoj 3809
#include <iostream>
using namespace std;
int main()
{
    int t,n,h[100]={0};
    cin>>t;
    while (t--){
        cin>>n; int ans=0;
        for (int i=1;i<=n;++i)
            cin>>h[i];
        for (int i=2;i<n;++i)
            if (h[i]>h[i-1] && h[i]>h[i+1])
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}