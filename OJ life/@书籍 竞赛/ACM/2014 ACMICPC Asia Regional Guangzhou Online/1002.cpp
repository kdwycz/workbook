#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=1000010;
int col[maxn<<3],sum[maxn<<3],ans;

void PushUp(int rt){
    sum[rt]=sum[rt<<1]|sum[rt<<1|1];
}

void PushDown(int rt){
    if (col[rt]){
        col[rt<<1]=col[rt<<1|1]=1;
        sum[rt<<1]=sum[rt<<1|1]=sum[rt];
        col[rt]=0;
    }
}

void Build(int l,int r,int rt){
    col[rt]=0;
	sum[rt]=2;
	if (l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void Update(int L,int R,int c,int l,int r,int rt){
	if (L<=l && R>=r){
		sum[rt]=(1<<(c-1));
		col[rt]=1;
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if (L<=m) Update(L,R,c,lson);
	if (R>m) Update(L,R,c,rson);
	PushUp(rt);
}

void Query(int L,int R,int l,int r,int rt){
    if (L<=l && R>=r){
        ans|=sum[rt];
        return;
    }
    PushDown(rt);
    if (l==r) return;
    int m=(l+r)>>1;
    if (L<=m) Query(L,R,lson);
    if (R>m) Query(L,R,rson);
}

void Output(){
    int i=1;
    while (ans>=1){
        while (ans%2==0){
            ++i; ans/=2;
        }
        printf("%d",i);
        if (ans!=1) printf(" ");
        ans/=2; ++i;
    }
    printf("\n");
}

int main()
{
	int n,m,a,b,c; char s;
	while (scanf("%d%d",&n,&m) && n){
        Build(1,n,1);
        for (int i=1;i<=m;++i){
            getchar();
            s=getchar();
            if (s == 'P'){
                scanf("%d%d%d",&a,&b,&c);
                Update(a,b,c,1,n,1);
            }
            else{
                scanf("%d%d",&a,&b);
                ans=0;
                Query(a,b,1,n,1);
                Output();
            }
        }
	}
	return 0;
}
