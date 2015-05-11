#include <iostream>
using namespace std;

int set[30010];
int m,n,k,i,x,y,score;

int FindSet(int x);
void Union(int x,int y);
int main()
{
	while (cin>>n>>m && (n!=0)){
		for (i=0;i<n;++i)
			set[i]=i;
		for (i=0;i<m;++i){
			cin>>k; cin>>x; k--;
			while(k--){
				cin>>y;
				if (FindSet(y) != 0) Union(x,y);
				else Union(y,x);
			}
		}
		score=0;
		for (i=0;i<n;++i)
			if (FindSet(i) == 0) score++;
		cout<<score<<endl;
	}
	return 0;
}

int FindSet(int x){
	if (set[x] != x)
		set[x]=FindSet(set[x]);
	return set[x];
}

void Union(int x,int y){
	x = FindSet(x);
	y = FindSet(y);
	set[y] = x;
	return;
}
