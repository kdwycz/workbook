#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=200010;

int h,w,n,a;
int tree[maxn<<2];

void PushUp(int rt){
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}

void Build(int l,int r,int rt){
	if (l==r){
		tree[rt]=w;
		return;
	}
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

int Query(int x,int l,int r,int rt){
	if (l==r){
		tree[rt]-=x;
		return l;
	}
	int m=(l+r)>>1;
	int ret=(tree[rt<<1]>=x)?Query(x,lson):Query(x,rson);
	PushUp(rt);
	return ret;
}

int main()
{
	while (~scanf("%d%d%d",&h,&w,&n)){
		if (h>n) h=n;
		Build(1,h,1);
		while (n--){
			scanf("%d",&a);
			if (a>tree[1])
				printf("-1\n");
			else
				printf("%d\n",Query(a,1,h,1));
		}
	}
	return 0;
}
