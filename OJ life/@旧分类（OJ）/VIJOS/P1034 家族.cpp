#include <iostream>
using namespace std;

int set[5010]={0};
int n,m,p,i,x,y;

int FindSet(int x);
void Union(int x,int y);
int main()
{
	cin>>n>>m>>p;
	for (i=1;i<=n;++i)
		set[i]=i;
	for (i=1;i<=m;++i){
		cin>>x>>y;
		Union(x,y);
	}
	for (i=1;i<=p;++i){
		cin>>x>>y;
		if (FindSet(x) == FindSet(y))
			cout<<"YES\n";
		else
			cout<<"No\n";
	}
	return 0;
}

int FindSet(int x){
	if (x != set[x])
		set[x]=FindSet(set[x]);
	return set[x];
}

void Union(int x,int y){
	x=FindSet(x);
	y=FindSet(y);
	set[x]=y;
	return;
}

