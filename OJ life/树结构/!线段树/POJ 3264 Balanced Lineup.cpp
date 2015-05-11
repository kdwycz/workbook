#include <iostream>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=50010;
const int INF=0x3f3f3f3f;

struct node{
	int max,min;
}tree[maxn<<2];
int Max,Min;

void PushUp(int rt){
	tree[rt].max=max(tree[rt<<1].max,tree[rt<<1|1].max);
	tree[rt].min=min(tree[rt<<1].min,tree[rt<<1|1].min);
}

void Build(int l,int r,int rt){
	if (l==r){
		cin>>tree[rt].max;
		tree[rt].min=tree[rt].max;
		return;
	}
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

void Query(int L,int R,int l,int r,int rt){
	if (L<=l && R>=r){
		Max=max(Max,tree[rt].max);
		Min=min(Min,tree[rt].min);
		return;
	}
	int m=(l+r)>>1;
	if (L<=m) Query(L,R,lson);
	if (R>m)  Query(L,R,rson);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n,q,a,b;
	cin>>n>>q;
	Build(1,n,1);
	while (q--){
		cin>>a>>b;
		Max=-INF,Min=INF;
		Query(a,b,1,n,1);
		cout<<Max-Min<<endl;
	}
	return 0;
}

/* 
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
const int M=200010;
int minv,maxv;

struct Node{
	int l,r;
	int minv,maxv;
	int Mid(){
		return (l+r)>>1;
	}
}tree[M<<2];

void Build(int root,int l,int r){
	tree[root].l=l;
	tree[root].r=r;
	tree[root].minv=INF;
	tree[root].maxv=-INF;
	if (l!=r){
		Build(root<<1,l,(l+r)>>1);
		Build(root<<1|1,(l+r)/2+1,r);
	}
}

void Insert(int root,int i,int v){
	if (tree[root].l==tree[root].r){
		tree[root].minv=tree[root].maxv=v;
		return;
	}
	tree[root].minv=min(tree[root].minv,v);
	tree[root].maxv=max(tree[root].maxv,v);
	if (i<=tree[root].Mid())
		Insert(root<<1,i,v);
	else
		Insert(root<<1|1,i,v);
}

void Query(int root,int l,int r){
	if (tree[root].minv>=minv && tree[root].maxv<=maxv)
		return;
	if (tree[root].l==l && tree[root].r==r){
		minv=min(minv,tree[root].minv);
		maxv=max(maxv,tree[root].maxv);
	}
	else if (r<=tree[root].Mid())
		Query(root<<1,l,r);
	else if (l>tree[root].Mid())
		Query(root<<1|1,l,r);
	else{
		Query(root<<1,l,tree[root].Mid());
		Query(root<<1|1,tree[root].Mid()+1,r);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n,q,a,b;
	cin>>n>>q;
	Build(1,1,n);
	for (int i=1;i<=n;++i){
		cin>>a;
		Insert(1,i,a);
	}
	for (int i=0;i<q;++i){
		cin>>a>>b;
		minv=INF;
		maxv=-INF;
		Query(1,a,b);
		cout<<maxv-minv<<endl;
	}
	return 0;
} 
*/
