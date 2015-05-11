#include <iostream>
#include <cstring>
using namespace std;

string s[55];
int m,n,ans;
int link[128][4]={0};
int vis[55][55];

void FloodFill(int y,int x){
    vis[y][x]=1;
    if (y>0   && link[s[y][x]][0] && link[s[y-1][x]][2] && !vis[y-1][x]) FloodFill(y-1,x);
    if (x<n-1 && link[s[y][x]][1] && link[s[y][x+1]][3] && !vis[y][x+1]) FloodFill(y,x+1);
    if (y<m-1 && link[s[y][x]][2] && link[s[y+1][x]][0] && !vis[y+1][x]) FloodFill(y+1,x);
    if (x>0   && link[s[y][x]][3] && link[s[y][x-1]][1] && !vis[y][x-1]) FloodFill(y,x-1);
}

int main()
{
    link['A'][0]=1; link['A'][3]=1;
    link['B'][0]=1; link['B'][1]=1;
    link['C'][2]=1; link['C'][3]=1;
    link['D'][1]=1; link['D'][2]=1;
    link['E'][0]=1; link['E'][2]=1;
    link['F'][1]=1; link['F'][3]=1;
    link['G'][0]=1; link['G'][1]=1; link['G'][3]=1;
    link['H'][0]=1; link['H'][2]=1; link['H'][3]=1;
    link['I'][1]=1; link['I'][2]=1; link['I'][3]=1;
    link['J'][0]=1; link['J'][1]=1; link['J'][2]=1;
    link['K'][0]=1; link['K'][1]=1; link['K'][2]=1; link['K'][3]=1;

    while (cin>>m>>n && m!=-1){
        ans=0; memset(vis,0,sizeof(vis));
        for (int i=0;i<m;++i)
            cin>>s[i];
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if (!vis[i][j]){
                    ans++;
                    FloodFill(i,j);
                }
        cout<<ans<<endl;
    }
	return 0;
}
