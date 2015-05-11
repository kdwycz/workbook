#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 200010;
int flag[maxn],tree[maxn<<3];
struct point{
	int x,y;
	bool operator < (const point& a) const{
		if (x!=a.x) return x<a.x;
		return y < a.y;
	}
}a[maxn],x[maxn],ans,null;

void PushUp(int rt){
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}

void Update(bool f,int x,int p,int l,int r,int rt){
	if (l==r){
		tree[rt]=f?p:-1;
		return;
	}
	int m=(l+r)>>1;
	if (x<=m)
		Update(f,x,p,lson);
	else
		Update(f,x,p,rson);
	PushUp(rt);
}

void Query(point p,int l,int r,int rt){
	if (x[r].x <= p.x || tree[rt] <= p.y) return;
	if (l==r) ans=x[l];
	int m=(l+r)>>1;
	Query(p,lson);
	if (ans.x==-1) Query(p,rson);
}

int main()
{
	memset(tree,-1,sizeof(tree));
	int n,i,m=0;
	null.x=null.y=-1;
	char op[10];
	scanf("%d",&n);
	for (i=0;i<n;++i){
		scanf("%s%d%d",op,&a[i].x,&a[i].y);
		if (op[0]=='a'){
			x[m++]=a[i]; flag[i]=1;
		}
		else if (op[0]=='f'){
			x[m++]=a[i]; flag[i]=2;
		}
		else flag[i]=0;
	}
	sort(x,x+m);
	for (i=0;i<n;++i){
		int now = lower_bound(x,x+m,a[i])-x;
		if (flag[i]<2) 
			Update(flag[i],now,a[i].y,0,m-1,1);
		else{
			ans=null;
			Query(a[i],0,m-1,1);
			if (ans.x==-1) 
				puts("-1");
			else
				printf("%d %d\n",ans.x,ans.y);
		}
	}
	return 0;
}
