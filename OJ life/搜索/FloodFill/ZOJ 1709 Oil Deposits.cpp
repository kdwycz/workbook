#include <iostream>
using namespace std;

string s[110];
int m,n,ans;

void FloodFill(int y,int x){
    if (y>=0 && y<m && x>=0 && x<n && s[y][x]=='@'){
        s[y][x]='*';
        for (int i=-1;i<=1;++i)
            for (int j=-1;j<=1;++j)
                FloodFill(y+i,x+j);
    }
}

int main()
{
    while (cin>>m>>n && m){
        ans=0;
        for (int i=0;i<m;++i)
            cin>>s[i];
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if (s[i][j]=='@'){
                    ans++;
                    FloodFill(i,j);
                }
        cout<<ans<<endl;
    }
    return 0;
}

