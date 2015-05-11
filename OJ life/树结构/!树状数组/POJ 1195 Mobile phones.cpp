#include <iostream>
using namespace std;

#define Lowbit(x) (x&(-x))
const int M = 1030;

int c[M][M]={0},op,n,x,y,x1,y1,t;

void Update(int x,int y,int t){
    for (int i=x;i<=n;i+=Lowbit(i))
        for (int j=y;j<=n;j+=Lowbit(j))
            c[i][j]+=t;
}

int Getsum(int x,int y){
    int ans=0;
    for (int i=x;i;i-=Lowbit(i))
        for (int j=y;j;j-=Lowbit(j))
            ans+=c[i][j];
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>op>>n; n+=2;
    while (cin>>op && op!=3){
        if (op==1){
            cin>>x>>y>>t;
            Update(x+2,y+2,t);
        }
        else{
            cin>>x>>y>>x1>>y1;
            cout<<Getsum(x1+2,y1+2)-Getsum(x+1,y1+2)-Getsum(x1+2,y+1)+Getsum(x+1,y+1)<<endl;
        }
    }
    return 0;
}
