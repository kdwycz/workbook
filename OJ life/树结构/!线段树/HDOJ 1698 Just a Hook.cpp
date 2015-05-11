#include <iostream>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100010;
int h,w,n;
int col[maxn<<2],sum[maxn<<2];

void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
} 

void PushDown(int rt,int m){
	if (col[rt]){
		col[rt<<1]=col[rt<<1|1]=col[rt];
		sum[rt<<1]=(m-(m>>1))*col[rt];
		sum[rt<<1|1]=(m>>1)*col[rt];
		col[rt]=0;
	}
}

void Build(int l,int r,int rt){
	col[rt]=0; sum[rt]=1;
	if (l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

void Update(int L,int R,int c,int l,int r,int rt){
	if (L<=l && R>=r){
		col[rt]=c;
		sum[rt]=c*(r-l+1);
		return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if (L<=m) Update(L,R,c,lson);
	if (R>m) Update(L,R,c,rson);
	PushUp(rt);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T,n,m;
	cin>>T;
	for (int i=1;i<=T;++i){
		cin>>n>>m;
		Build(1,n,1);
		while (m--){
			int a,b,c;
			cin>>a>>b>>c;
			Update(a,b,c,1,n,1);
		}
		cout<<"Case "<<i<<": The total value of the hook is "<<sum[1]<<".\n";
	}
	return 0;
}
