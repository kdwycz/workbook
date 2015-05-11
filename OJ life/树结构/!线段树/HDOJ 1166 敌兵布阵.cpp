#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 55000;

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

void Update(int p,int add,int l,int r,int rt){
	if (l == r){
		sum[rt] += add;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
		Update(p,add,lson);
	else
		Update(p,add,rson);
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
	int T,n;
	scanf("%d",&T);
	for (int nn=1;nn<=T;++nn){
		printf("Case %d:\n",nn);
		scanf("%d",&n);
		Build(1,n,1);
		char op[10];
		while (scanf("%s",op) && op[0]!='E'){
			int a,b;
			scanf("%d%d",&a,&b);
			if (op[0]=='Q')
				printf("%d\n",Query(a,b,1,n,1));
			else if (op[0]=='S')
				Update(a,-b,1,n,1);
			else 
				Update(a,b,1,n,1);
		}
	}
	return 0;
} 
