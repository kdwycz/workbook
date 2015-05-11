#include <iostream>
using namespace std;

string s[110];
int m,n,ans;

void FloodFill(int y,int x){
    if (s[y][x]=='.'){
        ans++; s[y][x]='#';
        if (y>0)    FloodFill(y-1,x);
        if (y<m-1)  FloodFill(y+1,x);
        if (x<n-1)  FloodFill(y,x+1);
        if (x>0)    FloodFill(y,x-1);
    }
}

int main()
{
    while (cin>>n>>m && n){
        ans=0; int x,y;
        for (int i=0;i<m;++i){
            cin>>s[i];
            for (int j=0;j<n;++j)
                if (s[i][j]=='@'){
                    y=i; x=j;
                }
        }
        s[y][x]='.';
        FloodFill(y,x);
        cout<<ans<<endl;
    }
    return 0;
}
