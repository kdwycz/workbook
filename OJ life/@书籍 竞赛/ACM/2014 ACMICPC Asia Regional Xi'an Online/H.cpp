#include <cstdio>
#include <algorithm>
using namespace std;
//                   0 1 2 3 4  5  6  7   8   9   10   11   12   13   14    15    16    17
const int table[20]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071};
int b[100010];

struct node{
    int x,no;
}c[100010];

bool cmp(node a,node b){
    return a.x>b.x;
}

int main()
{
    int n,s,s0,m;
    while (~scanf("%d",&n)){
        for (int i=0;i<=n;++i){
            scanf("%d",&c[i].x);
            c[i].no=i;
        }
        sort(c,c+n+1,cmp);
        long long nn=(long long)n*(n+1);
        printf("%lld\n",nn);
        
        int m=131071;
        for (int i=0;i<=n;++i){
            if (m>c[i].x){
                s=0;
                while (c[i].x>table[s]) ++s;
                m=table[s]-c[i].x;
            }
            b[c[i].no]=table[s]-c[i].x;
        }

        for (int i=0;i<n;++i)
            printf("%d ",b[i]);
        printf("%d\n",b[n]);
    }
    return 0;
}

