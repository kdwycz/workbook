#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 110;

int sum[maxn<<2];

void PushUP(int rt){
	sum[rt] = sum[rt<<1] +sum[rt<<1|1];
}

void Build(int l,int r,int rt){
	if (l == r){
		scanf("%d",&sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUP(rt);
}

int Query(int L,int R,int l,int r,int rt){
	if (L <= l && r <= R)
		return sum[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += Query(L,R,lson);
	if (R > m) ret += Query(L,R,rson);
	return ret;
}

int main()
{
	int T,n,a,b,m;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		Build(1,n,1);
		scanf("%d",&m);
		while (m--){
			scanf("%d%d",&a,&b);
            printf("%.2lf\n",Query(a,b,1,n,1)/(double)(b-a+1));
		}
	}
	return 0;
}
