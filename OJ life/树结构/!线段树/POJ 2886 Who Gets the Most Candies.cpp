#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int M = 500100;
const int a[37]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,
           55440,83160,110880,166320,221760,277200,332640,498960,500001};
const int b[37]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};

int tree[M<<2];
int val[M],kk;
char name[M][11];

void Build(int l,int r,int rt){
	tree[rt]=r-l+1;
	if (l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

int query(int p,int l,int r,int rt){
	tree[rt]--;
	if (l==r) return l;
	int m=(l+r)>>1;
	if (p<=tree[rt<<1])
		return query(p,lson);
	else
		return query(p-tree[rt<<1],rson);
}

int main()
{
	int n,k;
	while (~scanf("%d%d",&n,&k)){
		int i=0, Max=0, p=0, nn=n; 
        while (a[i] <= n) i++;
        p=a[i-1];
        Max = b[i-1];
        
		Build(1,n,1);
		for (i=1;i<=n;++i)
			scanf("%s %d",&name[i],&val[i]);
		
		for (i=0;i<p;++i){
			nn--;
			kk=query(k,1,n,1);
			if (!nn) break;
			if (val[kk]>0)
				k=(k-1+val[kk]-1)%nn+1;
			else
				k=((k-1+val[kk])%nn+nn)%nn+1;
		}
		printf("%s %d\n",name[kk],Max);
	}
	return 0;
}
