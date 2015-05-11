#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int x,y,s;
}a[11000];

int set[101];

bool cmp(node a,node b){
	return a.s<b.s;
}

int FindSet(int x){
	if (x!=set[x])
		set[x]=FindSet(set[x]);
	return set[x];
}

void Union(int x,int y){
	int fx=FindSet(x);
	int fy=FindSet(y);
	set[fy]=fx;
}

int main()
{
	int m,n,i,j,k,x,y,ans=0;
	cin>>n; k=0;
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j){
			cin>>x;
			if (i>j){
				a[++k].s=x;
				a[k].x=i;
				a[k].y=j;
			}
		}
		set[i]=i;
	}
		
	sort(a+1,a+k+1,cmp);		
	
	cin>>m;
	for (i=1;i<=m;++i){
		cin>>x>>y;
		Union(x,y);
	}

	for (i=1;i<=k;++i)
		if (FindSet(a[i].x)!=FindSet(a[i].y)){
			Union(a[i].x,a[i].y);
			ans+=a[i].s;
		}	

	cout<<ans<<endl;
	return 0;
}
