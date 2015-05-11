#include <iostream>
using namespace std;

int set[30010],count[30010],before[30010];
int i,n,x,y,fx,fy;
string s;

int FindSet(int x);
void Union(int x,int y);
int main()
{
	ios::sync_with_stdio(false);
	for (i=1;i<30010;++i){
		set[i]=i;
		count[i]=1;
		before[i]=0;
	}
	cin>>n;
	while (n--){
		cin>>s;
		if (s == "M"){
			cin>>x>>y;
			Union(x,y);
		}else{
			cin>>x;
			FindSet(x);
			cout<<before[x]<<endl;
		}
	}
	return 0;
}

int FindSet(int x){
	if (set[x] != x){
		int temp=set[x];
		set[x]=FindSet(set[x]);
		count[x]=count[temp];
		before[x]+=before[temp];
	}
	return set[x];
}

void Union(int x,int y){
	int fx=FindSet(x);
	int fy=FindSet(y);
	set[fx]=fy;
	before[fx]=count[fy];
	count[fy]+=count[fx];
	return;
}
