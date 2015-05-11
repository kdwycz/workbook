#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=10010;

bool hash[maxn];
int li[maxn],ri[maxn];
int x[maxn<<3],col[maxn<<4];
int cnt;

void PushDown(int rt){
	if (col[rt]!=-1){
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}

void Update(int L,int R,int c,int l,int r,int rt){
	if (L<=l && R>=r)
		col[rt]=c;
	else{
		PushDown(rt);
		int m=(l+r)>>1;
		if (L<=m) Update(L,R,c,lson);
		if (m<R) Update(L,R,c,rson);
	}
}

void Query(int l,int r,int rt){
	if (col[rt]!=-1){
		if (!hash[col[rt]]) cnt++;
		hash[col[rt]]=true;
	}
	else{
		if (l==r) return;
		int m=(l+r)>>1;
		Query(lson);
		Query(rson);
	}
}

int Bin(int key,int n,int x[]){
	int l=0,r=n-1;
	while (l<=r){
		int m=(l+r)>>1;
		if (x[m]==key) return m;
		if (x[m]<key)
			l=m+1;
		else
			r=m-1;
	}
}

int main()
{
	int t,n,nn,m;
	cin>>t;
	while (t--){
		cin>>n;
		nn=0; m=1;
		for (int i=0;i<n;++i){
			cin>>li[i]>>ri[i];
			x[nn++]=li[i];
			x[nn++]=ri[i];
		}
		sort(x,x+nn);
		for (int i=1;i<nn;++i)
			if (x[i]!=x[i-1]) x[m++]=x[i];
		for (int i=m-1;i>0;--i){
			if (x[i]!=x[i-1]+1) x[m++]=x[i-1]+1;
		}
		sort(x,x+m);
		memset(col,-1,sizeof(col));
		for (int i=0;i<n;++i){
			int l=Bin(li[i],m,x);
			int r=Bin(ri[i],m,x);
			Update(l,r,i,0,m,1);
		}
		cnt=0;
		memset(hash,0,sizeof(hash));
		Query(0,m,1);
		cout<<cnt<<endl;
	}
	return 0;
}
