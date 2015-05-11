#include <iostream>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=5010;

int tree[maxn<<2],x[maxn];

void PushUp(int rt){
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

void Build(int l,int r,int rt){
	tree[rt]=0;
	if (l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void Update(int p,int l,int r,int rt){
	if (l==r){
		tree[rt]++;
		return;
	}
	int m=(l+r)>>1;
	if (p<=m)
		Update(p,lson);
	else
		Update(p,rson);
	PushUp(rt);
}

int Query(int L,int R,int l,int r,int rt){
	if (L<=l && R>=r)
		return tree[rt];
	int m=(l+r)>>1;
	int ret=0;
	if (L<=m) ret+=Query(L,R,lson);
	if (R>m) ret+=Query(L,R,rson);
	return ret;
}

int main()
{
	int n,sum,ret;
	while (cin>>n){
		Build(0,n-1,1);
		sum=0;
		for (int i=0;i<n;++i){
			cin>>x[i];
			sum+=Query(x[i],n-1,0,n-1,1);
			Update(x[i],0,n-1,1); 
		}
		ret=sum;
		for (int i=0;i<n;++i){
			sum+=n-x[i]-x[i]-1;
			ret=min(sum,ret);
		}
		cout<<ret<<endl;
	}
	return 0;
}
