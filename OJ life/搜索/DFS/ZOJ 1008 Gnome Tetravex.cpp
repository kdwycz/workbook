#include <iostream>
#include <cstring>
using namespace std;

int item[26][4],used[26],map[6][6];
int n,m,ans,ii=0;

void dfs(int i){
    if (i == n*n){
        ans=1; return;
    }
    int x=i%n;
    int y=i/n;
    for (int j=0;j<m && ans==0;++j)
        if (used[j]){
            if (y && item[j][3]!=item[map[y-1][x]][1]) continue;
            if (x && item[j][0]!=item[map[y][x-1]][2]) continue;
            map[y][x]=j;
            used[j]--;
            dfs(i+1);
            used[j]++;
        }
}

int main()
{
    while (cin>>n && n){
        memset(used,0,sizeof(used));
        if (ii) cout<<endl;
        m=0; ans=0; ++ii;
        for (int i=0;i<n*n;++i){
            int a,b,c,d,e,t=-1;
            cin>>a>>b>>c>>d;
            for (int j=0;j<=m;++j)
                if (j==m || (item[j][0]==a && item[j][1]==b && item[j][2]==c && item[j][3]==d))
                    t=j;
            item[t][0]=a; item[t][1]=b;
            item[t][2]=c; item[t][3]=d;
            used[t]++; ++m;
        }
        dfs(0);
        cout<<"Game "<<ii<<": ";
        if (ans)
            cout<<"Possible\n";
        else
            cout<<"Impossible\n";
    }
	return 0;
}

