#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(int argc, char *argv[])
{
    int map[11][11];
    int cc[11][11];
    int dx[8],dy[8];
    int n,x,y; char c;
    while (cin>>n>>y>>x && n){
        memset(map,0,sizeof(map));
        memset(cc,0,sizeof(cc));
        
        
        for (int i=0;i<n;++i){
            cin>>c>>dy[i]>>dx[i];
            cc[dy[i]][dx[i]]=c;
        }
        
        
        for (int i=0;i<n;++i){
            
            if (cc[dy[i]][dx[i]]=='G')
                for (int j=dy[i]-1;j;j--)
                    if (cc[j][dx[i]]!=0){
                        map[j][dx[i]]=true;
                        break;
                    }
                    else
                        map[j][dx[i]]=true;
            
            else if (cc[dy[i]][dx[i]]=='R'){
                for (int j=dx[i]-1;j;j--)
                    if (cc[dy[i]][j]!=0){
                        map[dy[i]][j]=true;
                        break;
                    }   
                    else
                        map[dy[i]][j]=true;
                
                for (int j=dx[i]+1;j<=10;j++)
                    if (cc[dy[i]][j]!=0){
                        map[dy[i]][j]=true;
                        break;
                    }
                    else
                        map[dy[i]][j]=true;
                        
                for (int j=dy[i]-1;j;j--)
                    if (cc[j][dx[i]]!=0){
                        map[j][dx[i]]=true;
                        break;
                    }
                    else
                        map[j][dx[i]]=true;
                
                for (int j=dy[i]+1;j<=9;j++)
                    if (cc[j][dx[i]]!=0){
                        map[j][dx[i]]=true; 
                        break;
                    }   
                    else
                        map[j][dx[i]]=true;     
            }
    
            else if (cc[dy[i]][dx[i]]=='C'){
                int j=dx[i]-1;
                while (j>0 && cc[dy[i]][j]==0) --j;
                --j;
                while (j>0 && cc[dy[i]][j]==0){
                    map[dy[i]][j]=true;
                    --j;
                }
                if (j>0) map[dy[i]][j]=true;
                
                j=dx[i]+1;
                while (j<=10 && cc[dy[i]][j]==0) ++j;
                ++j;
                while (j<=10 && cc[dy[i]][j]==0){
                    map[dy[i]][j]=true;
                    ++j;
                }
                if (j<=10) map[dy[i]][j]=true;
                
                j=dy[i]-1;
                while (j>0 && cc[j][dx[i]]==0) --j;
                --j;
                while (j>0 && cc[j][dx[i]]==0){
                    map[j][dx[i]]=true;
                    --j;
                }
                if (j>0) map[j][dx[i]]=true;
                
                j=dy[i]+1;
                while (j<=9 && cc[j][dx[i]]==0) ++j;
                ++j;
                while (j<=9 && cc[j][dx[i]]==0){
                    map[j][dx[i]]=true;
                    ++j;
                }
                if (j<=9) map[j][dx[i]]=true;
            }
            
            
            else if (cc[dy[i]][dx[i]]=='H'){
                if (dx[i]>=3 && cc[dy[i]][dx[i]-1]==0){
                    if (dy[i]!=10) map[dy[i]+1][dx[i]-2]=true;
                    if (dy[i]!= 1) map[dy[i]-1][dx[i]-2]=true; 
                }
                if (dx[i]<=7 && cc[dy[i]][dx[i]+1]==0){
                    if (dy[i]!=10) map[dy[i]+1][dx[i]+2]=true;
                    if (dy[i]!= 1) map[dy[i]-1][dx[i]+2]=true; 
                }
                if (dy[i]>=3 && cc[dy[i]-1][dx[i]]==0){
                    if (dx[i]!= 9) map[dy[i]-2][dx[i]+1]=true;
                    if (dx[i]!= 1) map[dy[i]-2][dx[i]-1]=true; 
                }
                if (dy[i]<=8 && cc[dy[i]+1][dx[i]]==0){
                    if (dx[i]!= 9) map[dy[i]+2][dx[i]+1]=true;
                    if (dx[i]!= 1) map[dy[i]+2][dx[i]-1]=true; 
                }   
            }   
        }
        
        bool ans=true;
        if (!map[y][x]) ans=false;
        if (y!=1 && !map[y-1][x]) ans=false;
        if (y!=3 && !map[y+1][x]) ans=false;
        if (x!=4 && !map[y][x-1]) 
            ans=false;
        if (x!=6 && !map[y][x+1]) ans=false;
        
        if (ans) 
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
    return 0;
}