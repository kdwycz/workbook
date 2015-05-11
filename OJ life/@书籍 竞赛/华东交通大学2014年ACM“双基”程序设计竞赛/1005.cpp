#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int T,n,m,s,flag;
int arr[110][17];
int hash[16385];
int a[17];

void test(int x){
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=n;++i){
        int cc=0,t=1;
        for (int j=1;j<=x;++j){
            cc+=arr[i][a[j]]*t;
            t*=2;
        }
        if(hash[cc]) return;
        else hash[cc]=1;
    }
    flag=true;
}

void dfs(int i,int m){
    for (int j=a[i-1]+1;j<=n;++j){
        if (flag) return;
        a[i]=j;
        if (i==m) test(i);
        else dfs(i+1,m);
    }
}

int main()
{
    cin>>T;
    while (T--){
        flag=false;
        cin>>n>>m;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j){
                cin>>arr[i][j];
                arr[i][j]++;
            }
        s = ceil(log2(n));
        for (int i=s;i<m;++i){
            dfs(1,i);
            if(flag){
                cout<<i<<endl;
                break;
            }
        }
        if (!flag) cout<<m<<endl;
    }
    return 0;
}
