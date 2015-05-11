#include <iostream>
#include <algorithm>
using namespace std;

struct criminal{
	int a,b,s;
}cr[100010];
int set[100010],offset[100010];
int fx,fy,n,m,i,flag;

int cmp(criminal a,criminal b);
int FindSet(int x);
void Union(int x,int y,int fx,int fy);

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m; flag=1;
	for (i=1;i<=n;++i){
		set[i]=i;
		offset[i]=0;
	}
	for (i=1;i<=m;++i)
		cin>>cr[i].a>>cr[i].b>>cr[i].s;
	sort(cr+1,cr+m,cmp);
	
	while((m--)&&(flag)){
		fx=FindSet(cr[m].a);
		fy=FindSet(cr[m].b);
		if (fx != fy)
			Union(cr[m].a,cr[m].b,fx,fy);
		else
			if (offset[cr[m].a] == offset[cr[m].b])
				flag=0;
	}
	if (m>0)
		cout<<cr[m+1].s<<endl;
	else
		cout<<"0\n";
	return 0;
}

int cmp(criminal a,criminal b){
	return a.s<b.s;
}

int FindSet(int x){
	if (set[x] != x){
		int temp=set[x];
		set[x]=FindSet(set[x]);
		offset[x]^=offset[temp];
	}
	return set[x];
}

void Union(int x,int y,int fx,int fy){
	set[fx]=fy;
	offset[fx]=offset[x]^offset[y]^1;
	return;
}
