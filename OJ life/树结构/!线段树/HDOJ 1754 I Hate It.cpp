#include <iostream>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 200010;

int tree[maxn<<2];

void PushUp(int rt){
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}

void Build(int l,int r,int rt){
	if (l==r){
		cin>>tree[rt];
		return;
	}
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

void Update(int p,int sc,int l,int r,int rt){
	if (l==r){
		tree[rt]=sc;
		return;
	}
	int m=(l+r)>>1;
	if (p<=m)
		Update(p,sc,lson);
	else
		Update(p,sc,rson);
	PushUp(rt);
}

int Query(int L,int R,int l,int r,int rt){
	if (L<=l && R>=r)
		return tree[rt];
	int m=(l+r)>>1;
	int ret=0;
	if (L<=m) ret=max(ret,Query(L,R,lson));
	if (R>m) ret=max(ret,Query(L,R,rson));
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int m,n,a,b;
	string s;
	while (cin>>n>>m){
		Build(1,n,1);
		for (int i=0;i<m;++i){
			cin>>s>>a>>b;
			if (s=="Q")
				cout<<Query(a,b,1,n,1)<<endl;
			else
				Update(a,b,1,n,1);
		}
	}
	return 0;
}
