#include <iostream>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100010;

long long add[maxn<<2],sum[maxn<<2];

void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int m){
	if (add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		sum[rt<<1]+=add[rt]*(m-(m>>1));
		sum[rt<<1|1]+=add[rt]*(m>>1);
		add[rt]=0;
	}
}

void Build(int l,int r,int rt){
	add[rt]=0;
	if (l==r)
		cin>>sum[rt];
	else{
		int m=(l+r)>>1;
		Build(lson);
		Build(rson);
		PushUp(rt);
	}	
}

void Update(int L,int R,int c,int l,int r,int rt){
	if (L<=l && R>=r){
		add[rt]+=c;
		sum[rt]+=(long long)c*(r-l+1);
	}
	else{
		PushDown(rt,r-l+1);
		int m=(l+r)>>1;
		if (L<=m) Update(L,R,c,lson);
		if (m<R) Update(L,R,c,rson);
		PushUp(rt);
	}
}

long long Query(int L,int R,int l,int r,int rt){
	if (L<=l && r<=R)
		return sum[rt];
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	long long ret=0;
	if (L<=m) ret+=Query(L,R,lson);
	if (m<R) ret+=Query(L,R,rson);
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n,q,a,b,c; string s;
	cin>>n>>q;
	Build(1,n,1);
	while (q--){
		cin>>s;
		if (s=="Q"){
			cin>>a>>b;
			cout<<Query(a,b,1,n,1)<<endl;
		}
		else{
			cin>>a>>b>>c;
			Update(a,b,c,1,n,1);
		}
	}
	return 0;
}
