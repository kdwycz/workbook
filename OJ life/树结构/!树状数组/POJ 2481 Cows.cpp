#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define Lowbit(x) (x&(-x))
const int M = 100010;

struct node{
    int x,y,no;
}arr[M];

int n,c[M],b[M],a[M];

void Update(int x){
    for (int i=x;i<=n;i+=Lowbit(i))
        ++c[i];
}

int Getsum(int x){
    int ans=0;
    for (int i=x;i;i-=Lowbit(i))
            ans+=c[i];
    return ans;
}

bool cmp(node a,node b){
    if (a.y==b.y)
        return a.x<b.x;
    return a.y>b.y;
}

int main()
{
    while (~scanf("%d",&n) && n){
    	a[0]=arr[0].x=arr[0].y=-1;
        for (int i=1;i<=n;++i){
            scanf("%d%d",&arr[i].x,&arr[i].y);
            ++arr[i].x;
            arr[i].no=i;
        }
        sort(arr+1,arr+n+1,cmp);
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;++i){
        	if (arr[i].y==arr[i-1].y && arr[i].x==arr[i-1].x)
        		a[arr[i].no] = a[arr[i-1].no];
        	else
            	a[arr[i].no]=Getsum(arr[i].x);
            Update(arr[i].x);
        }
        for (int i=1;i<n;++i)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}

