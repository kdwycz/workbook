#include <iostream>
#include <cstring>
using namespace std;
struct node{
    int min;
    double sum;
    int arr[11];
}dp[11][1010];

double in[11][1010],temp,ans;
int T,t,i,j,m,n,temp1;

int main()
{
    cin>>T;
    for (int t=1;t<=T;++t){
        cin>>m>>n;
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=m;++i)
            for (int j=1;j<=n;++j)
                cin>>in[i][j];

        if (m>1){
            for (int i=1;i<=m;++i){
                dp[i][1].min=0;
                dp[i][1].sum=in[i][1];
                dp[i][1].arr[i]=1;
            }

            for (int j=2;j<=n;++j){
                for (int i=1;i<=m;++i){
                    temp=0.0; temp1=0;
                    for (int k=1;k<=m;++k){
                        if (k==i) continue;
                        if (dp[k][j-1].arr[i]+1-dp[k][j-1].min<=1 && dp[k][j-1].sum+in[i][j]>temp){
                            temp=dp[k][j-1].sum+in[i][j]; temp1=k;
                        }
                    }
                    dp[i][j]=dp[temp1][j-1];
                    dp[i][j].sum=temp;
                    dp[i][j].arr[temp1]++;
                    dp[i][j].min=dp[i][j].arr[1];
                    for (int l=2;l<=m;++l)
                        if (dp[i][j].min>dp[i][j].arr[l])
                            dp[i][j].min=dp[i][j].arr[l];
                }
            }
            ans=0;
            for (int i=1;i<=m;++i)
                if (ans<dp[i][n].sum)
                    ans=dp[i][n].sum;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
