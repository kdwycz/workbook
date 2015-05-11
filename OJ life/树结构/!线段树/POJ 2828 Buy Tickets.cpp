/*
** 现在我们知道总共有 n 个人，且最后一个人要排在这 n 个人中的位置是 p[n]，我们可以直接把队列的第 p[n] 个位子安排给第 n 个人
** 现在来考虑第 n-1 个人，他要排在只有 n-1 个人的第 p[n-1] 个位置上，怎么做呢？我们肯定是从队列的第 1 个开始数，遇到没有被人占领的位置就加 1，直到数到了 p[n-1]，那么这个空位就安排给第 n-1 个人
** 对于第 n-2 个人，以及剩下的所有人都可以这样做
** 当然，不可能真的一个一个的数，但是可以用线段树动态的统计空余位置的数量和更新空余位置的信息
** 所以对每个人安排位置，最坏需要 log(n) 的时间，总的时间复杂度是 nlog(n) 的
*/ 


#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int M=200010;

int tree[M<<2],pos[M],val[M],ans[M],kk;

void Build(int l,int r,int rt){
	tree[rt]=r-l+1;
	if (l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void Update(int p,int l,int r,int rt){
	--tree[rt];
	if (l==r){
		kk=l;
		return;
	}
	int m=(l+r)>>1;	
	if (p<=tree[rt<<1]) 
		Update(p,lson);
	else
		Update(p-tree[rt<<1],rson);
}

int main()
{
//	std::ios::sync_with_stdio(false);
	int n,i,j,k;
	while (~scanf("%d",&n)){
		Build(1,n,1);
		for (i = 1; i <= n; ++i)
		//	cin>>pos[i]>>val[i];
			scanf("%d%d",&pos[i],&val[i]);
		for (i=n;i;--i){
			Update(pos[i]+1,1,n,1);
			ans[kk]=val[i];
		}
		for (i=1;i<n;++i)
			//cout<<ans[i]<<' ';
			printf("%d ",ans[i]);
		//cout<<ans[n]<<endl;
		printf("%d\n",ans[n]);
	}
	return 0;
}
