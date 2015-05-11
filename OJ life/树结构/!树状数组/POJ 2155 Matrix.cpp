//http://blog.csdn.net/zxy_snow/article/details/6264135
#include <iostream>
#include <cstring>
using namespace std;

#define Lowbit(x) (x&(-x))
const int M = 1010;

int n,arr[M][M];

int Getsum(int y,int x){
    int ans=0;
    for (int dy=y;dy<=n;dy+=Lowbit(dy))
        for (int dx=x;dx<=n;dx+=Lowbit(dx))
            ans+=arr[dy][dx];
    return ans;
}

void Update(int y,int x){
    for (int dy=y;dy;dy-=Lowbit(dy))
        for (int dx=x;dx;dx-=Lowbit(dx))
            arr[dy][dx]++;
}

int main()
{
	std::ios::sync_with_stdio(false);
    int nn,t; string s;
    cin>>nn;
    while (nn--){
        memset(arr,0,sizeof(arr));
        cin>>n>>t;
        while (t--){
            cin>>s;
            if (s=="C"){
                int x1,y1,x2,y2;
                cin>>y1>>x1>>y2>>x2;
                Update(y2,x2);
                Update(y1-1,x1-1);
                Update(y1-1,x2);
                Update(y2,x1-1);
                
            }
            else{
                int x,y;
                cin>>y>>x;
                cout<<Getsum(y,x)%2<<endl;
            }
        }
        if (n>1) cout<<endl;
    }
    return 0;
}
